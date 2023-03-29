import socket

# Get the hostname of the machine
hostname = socket.gethostname()

# Get the IP address of the machine
ip_address = socket.gethostbyname(hostname)

# Print the IP address
print("IP address:", ip_address)
