#include <iostream>
#include <string>

using namespace std;

// Function to generate the key in a cyclic manner until its length equals the length of the text
string generateKey(string text, string key)
{
    int textLength = text.length();
    int keyLength = key.length();

    for (int i = 0; i < textLength - keyLength; i++)
    {
        key += key[i % keyLength];
    }
    return key;
}

// Function to encrypt the plaintext using Vigenère Cipher
string vigenereEncrypt(string text, string key)
{
    string cipherText = "";

    for (int i = 0; i < text.length(); i++)
    {
        // Convert letters to numbers, A=0, B=1, ..., Z=25
        char x = (text[i] + key[i]) % 26;
        // Convert numbers back to letters
        x += 'A';
        cipherText += x;
    }

    return cipherText;
}

// Function to decrypt the ciphertext using Vigenère Cipher
string vigenereDecrypt(string cipherText, string key)
{
    string plainText = "";

    for (int i = 0; i < cipherText.length(); i++)
    {
        // Convert letters to numbers, A=0, B=1, ..., Z=25
        char x = (cipherText[i] - key[i] + 26) % 26;
        // Convert numbers back to letters
        x += 'A';
        plainText += x;
    }

    return plainText;
}

int main()
{
    string text, keyword;

    cout << "Enter the plaintext (uppercase letters only): ";
    getline(cin, text);

    cout << "Enter the keyword (uppercase letters only): ";
    getline(cin, keyword);

    // Generate the key in a cyclic manner
    string key = generateKey(text, keyword);

    // Encrypt the text
    string cipherText = vigenereEncrypt(text, key);
    cout << "Encrypted Text: " << cipherText << endl;

    // Decrypt the text
    string decryptedText = vigenereDecrypt(cipherText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
