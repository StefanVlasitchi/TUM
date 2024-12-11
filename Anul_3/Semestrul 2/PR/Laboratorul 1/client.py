import socket
import threading
import server

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('localhost', 12345)


# Function to send messages to the server
def send_message(message, name):
    client_socket.sendto(f"{name}: {message}".encode('utf-8'), server_address)


# Function to join the chat with a name
def join_chat():
    name = input("Enter your name: ")
    send_message(f"JOIN {name}", name)
    return name  # Return the name after joining the chat


# Function to leave the chat
def leave_chat(name):
    send_message(f"LEAVE {name}", name)


# Function to receive messages from the server
def receive_messages():
    while True:
        data, _ = client_socket.recvfrom(1024)
        print(data.decode('utf-8'))


# Main function
# Main function
def main():
    try:
        name = join_chat()  # Obtain the name from the join_chat() function
        print("You joined the chat.")

        while True:
            message = input("Enter message (type 'exit' to leave the chat): ")
            if message.lower() == 'exit':
                leave_chat(name)  # Pass the name to the leave_chat function
                print("You left the chat.")
                break
            elif message.startswith('@'):
                recipient, private_message = extract_private_message(message)
                if recipient and private_message:
                    # Send private message directly to the recipient's address
                    send_private_message(recipient, private_message)
                else:
                    print("Invalid private message format. Use '@recipient message'.")
            else:
                send_message(message, name)  # Pass the name to the send_message function
    except KeyboardInterrupt:
        leave_chat(name)
        print("\nClosing the client...")
    finally:
        client_socket.close()


# Function to extract recipient and private message from the private message string
def extract_private_message(message):
    parts = message.split(' ', 1)  # Split the message into two parts
    if len(parts) == 2:
        recipient = parts[0][1:]  # Extract recipient
        private_message = parts[1]  # Extract private message
        return recipient, private_message
    else:
        return None, None

    try:
        name = join_chat()  # Obtain the name from the join_chat() function
        print("You joined the chat.")

        while True:
            message = input("Enter message (type 'exit' to leave the chat): ")
            if message.lower() == 'exit':
                leave_chat(name)  # Pass the name to the leave_chat function
                print("You left the chat.")
                break
            elif message.startswith('@'):
                parts = message.split(maxsplit=1)  # Split the message into two parts
                if len(parts) == 2:
                    recipient, private_message = parts[0][1:], parts[1]  # Extract recipient and private message
                    # Send private message directly to the recipient's address
                    send_private_message(recipient, private_message)
                else:
                    print("Invalid private message format. Use '@recipient message'.")
            else:
                send_message(message, name)  # Pass the name to the send_message function
    except KeyboardInterrupt:
        leave_chat(name)
        print("\nClosing the client...")
    finally:
        client_socket.close()


# Function to send private messages directly to the recipient's address
def send_private_message(recipient, message):
    if recipient in server.clients:
        client_socket.sendto(f"[PRIVATE] {recipient}:{message}".encode('utf-8'), server.clients[recipient])


if __name__ == "__main__":
    main()
