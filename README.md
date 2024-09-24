# Encryption and Decryption System

This project is an **Encryption and Decryption** system implemented in C++ using **Object-Oriented Programming (OOPs)** concepts. The system provides a secure way to encode and decode messages using randomly generated keys and multiple transformation techniques.

## Features

- **Message Rearrangement:** The message is first reversed and then characters are swapped in pairs to obfuscate the original content.
- **Key Generation:** A random key is generated using ASCII values to perform the encryption, making the process highly secure.
- **Character Shift:** The encryption process includes dynamic character shifts based on the product of the digits from the key values at the front and back of the key vector.
- **Decoding (to be implemented):** A decryption process to retrieve the original message from the encoded text.

## How It Works

### Encoding Process
1. **Rearrange the Message:** The message is reversed, and character pairs are swapped.
2. **Generate a Key:** A random key twice the size of the message is generated using ASCII characters between 32 and 126.
3. **Character Shifting:** The message characters are shifted using dynamic shifts based on the product of key digits from the front and back.
4. **Obfuscation:** This creates a highly scrambled and unreadable message that is difficult to decrypt without the correct key.

### Decoding Process
- (To be implemented) The decoding process will reverse the transformations applied during the encoding to retrieve the original message.

## Code Overview

### Functions

- `void rearrangeMessage(string &str)`:  
  Reverses the message and swaps characters in pairs.

- `void rearrangeKey(vector<int> &key)`:  
  Reverses the key and swaps elements in pairs.

- `vector<int> keyGeneration(int messageLength)`:  
  Generates a random key using ASCII values between 32 and 126.

- `int characterShift(int front, int back)`:  
  Calculates the shift value by multiplying the digits of the key's front and back elements.

- `void encode(string &message, vector<int> key)`:  
  Encodes the message using rearranged characters and the randomly generated key.

- `void decode()`:  
  Placeholder for the decoding logic (to be implemented).
