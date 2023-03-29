import socket
# from huffman import Huffman

# HOST = '192.168.43.216'

HOST = '192.168.1.12'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    data = ""

    while data != 'quit':
        data = input("Enter Message: ")
        # h = Huffman(data)
        # huffed = h.huff()
        s.sendall(data.encode())
        

