import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('localhost', 12345)
server_socket.bind(server_address)

print('Server is up and listening...')

clients = {}


def handle_client_messages():
    while True:
        data, client_address = server_socket.recvfrom(1024)
        decoded_data = data.decode('utf-8')

        print(f"Received message from {client_address}: {decoded_data}")

        if decoded_data.startswith("JOIN"):
            client_name = decoded_data.split()[1]
            clients[client_name] = client_address
            print(f"Client {client_name} joined the chat.")
            broadcast(f"Client {client_name} joined the chat.", client_name)
        elif decoded_data.startswith("LEAVE"):
            client_name = decoded_data.split()[1]
            del clients[client_name]
            print(f"Client {client_name} left the chat.")
            broadcast(f"Client {client_name} left the chat.")
        elif decoded_data.startswith("[PRIVATE]"):
            parts = decoded_data.split(maxsplit=2)
            if len(parts) >= 3:
                sender = parts[1].split(':')[0]
                recipient = parts[2].split(':')[0]
                message = ' '.join(parts[3:])
                send_private_message(sender, recipient, message)
            else:
                print("Invalid private message format.")

        else:
            broadcast(decoded_data)


def broadcast(message, sender=None):
    for client_name, client_address in clients.items():
        if client_name != sender:
            server_socket.sendto(f"(Client {sender}): {message}".encode('utf-8'), client_address)


def send_private_message(sender, recipient, message, clients):
    if recipient in clients:
        server_socket.sendto(f"[PRIVATE] {sender}:{message}".encode('utf-8'), clients[recipient])


def main():
    try:
        handle_client_messages()
    except Exception as e:
        print(f"Error: {e}")
    finally:
        server_socket.close()


if __name__ == "__main__":
    main()
