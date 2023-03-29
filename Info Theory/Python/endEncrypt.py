from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

class AESCipher:
    def __init__(self, key):
        self.key = key
    
    def encrypt(self, data):
        cipher = AES.new(self.key, AES.MODE_CBC)
        ciphertext = cipher.encrypt(pad(data, AES.block_size))
        iv = cipher.iv
        return (iv + ciphertext)
    
    def decrypt(self, data):
        iv = data[:AES.block_size]
        ciphertext = data[AES.block_size:]
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
        return plaintext

key = b'Sixteen byte key'
cipher = AESCipher(key)

# encrypt
plaintext = b'Hello, World!'
ciphertext = cipher.encrypt(plaintext)
print(ciphertext)

# decrypt
decrypted = cipher.decrypt(ciphertext)
print(decrypted)
