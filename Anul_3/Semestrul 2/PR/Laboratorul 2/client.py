import socket
import threading

INTERFACE = "127.0.0.1"
PORT = 11111
BUFFER_SIZE = 1024

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ADDR = (INTERFACE, PORT)

def receive():
    while True:
        try:
            msg, _ = client.recvfrom(BUFFER_SIZE)
            print("[Received]", msg.decode("utf-8"))
        except Exception as e:
            print("Error while receiving message:", e)

def main():
    print("Welcome to the UDP Chat Client")
    nickname = input("Please enter your nickname: ")

    # Start receiving thread
    t = threading.Thread(target=receive)
    t.start()

    # Send signup message
    client.sendto(f"SIGNUP_TAG:{nickname}".encode("utf-8"), ADDR)

    # Main loop for sending messages
    while True:
        try:
            msg = input('Enter your message: ')
            client.sendto(f'{nickname}:{msg}'.encode('utf-8'), ADDR)
        except Exception as e:
            print("Error while sending message:", e)

if __name__ == "__main__":
    main()
