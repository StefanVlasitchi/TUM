import queue
import socket
import threading

INTERFACE = "127.0.0.1"
PORT = 11111
BUFFER_SIZE = 1024

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ADDR = (INTERFACE, PORT)
server.bind(ADDR)

messages = queue.Queue()

clients = []
nickNames = {}


def add_client(msg, addr):
    name = msg[msg.index(":") + 1:]
    nickNames[addr] = name
    for client in clients:
        if client != addr:
            try:
                server.sendto(f"{name} joined!".encode("utf-8"), client)
            except:
                clients.remove(client)


def receive():
    while True:
        try:
            msg, addr = server.recvfrom(BUFFER_SIZE)
            messages.put((msg, addr))
        except:
            pass


def send_private_message(sender, to, message):
    for client_addr, nickname in nickNames.items():
        if nickname == to:
            try:
                server.sendto(
                    f"{sender}<<!PRIVATE!>>:{message}".encode("utf-8"), client_addr
                )
            except:
                pass


def broadcast(msg, addr):
    for client in clients:
        if client == addr:
            continue
        try:
            server.sendto(msg, client)
        except:
            clients.remove(client)


def send():
    while True:
        while not messages.empty():
            msg, addr = messages.get()
            print(msg.decode("utf-8"))
            if addr not in clients:
                clients.append(addr)

            msg_str = msg.decode("utf-8")
            if msg_str.startswith("SIGNUP_TAG:"):
                add_client(msg_str, addr)
            elif msg_str.count(":") == 2:
                sender, rest = msg_str.split(":", 1)
                to, message = rest.split(":", 1)
                send_private_message(sender, to, message)
            else:
                broadcast(msg, addr)


# Print server details when starting
print(f"UDP Chat Server started")
print(f"Listening on {INTERFACE}:{PORT}")

t1 = threading.Thread(target=receive)
t2 = threading.Thread(target=send)
t1.start()
t2.start()
