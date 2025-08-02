OTP File Ecryption

This is a small C project that implements a basic one time pad encryption and decryption system. It can generate a random key, encrypt a file using XOR, and then decrypt it back using the same key.

Build:
To compile the project, run: make
To clean up the compiler files, run: make clean

How to use the project:
1. Generate a key
./otp keygen <input_file> <key_file>

2. Encrypt a file
./otp encrypt <input_file> <key_file> <output_file>

3. Decrypt a file
./otp decrypt <encrypted_file> <key_file> <output_file>

Example:
./otp keygen message.txt key.bin
./otp encrypt message.txt key.bin encrypted.bin
./otp decrypt encrypted.bin key.bin decrytped.txt

Additional informations:
1. The key must be the same size as the file you are encrypting.
2. The file you are decrypting must be the same size as the key you are using for decrypt.



