"""
Server receiver buffer is char[256]
If correct, the server will send a message back to you saying "I got your message"
Write your socket client code here in python
Establish a socket connection -> send a short message -> get a message back -> ternimate
use python "input->" function, enter a line of a few letters, such as "abcd"
"""
import socket

def main():

    HOST = "172.20.10.3"
    PORT = 5000

    # TODO: Create a socket and connect it to the server at the designated IP and port
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))

    # TODO: Get user input and send it to the server using your TCP socket
        userInput = input("Message: ")
        s.sendall(bytes(userInput, encoding='utf-8'))


    # TODO: Receive a response from the server and close the TCP connection
        data = s.recv(1024)
    
    # .decode() used to decode bytes string
    print(data.decode())


if __name__ == '__main__':
    main()