from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

def ensure_bytes(data, encoding='utf-8'):
    # Convert string to bytes if it's not already in bytes
    return data.encode(encoding) if isinstance(data, str) else data

def encrypt_des(plaintext, key):
    # Ensure key is exactly 8 bytes, padding if necessary
    key = ensure_bytes(key)[:8].ljust(8, b'\0')
    des = DES.new(key, DES.MODE_ECB)
    # Convert plaintext to bytes if it's a string, then pad
    padded_text = pad(ensure_bytes(plaintext), DES.block_size)
    ciphertext = des.encrypt(padded_text)
    return ciphertext

def decrypt_des(ciphertext, key):
    # Ensure key is exactly 8 bytes, padding if necessary
    key = ensure_bytes(key)[:8].ljust(8, b'\0')
    des = DES.new(key, DES.MODE_ECB)
    # Decrypt and unpad the ciphertext, decode to string for readability
    decrypted_text = unpad(des.decrypt(ciphertext), DES.block_size)
    return decrypted_text.decode('utf-8')

# Example usage
key = "secret_k"  # This can be a string or 8-byte bytes object
plaintext = "Hello, DES!"  # This can be a string or bytes

# Encrypt the plaintext
ciphertext = encrypt_des(plaintext, key)
print("Ciphertext:", ciphertext.hex())

# Decrypt the ciphertext
decrypted_text = decrypt_des(ciphertext, key)
print("Decrypted Text:", decrypted_text)
