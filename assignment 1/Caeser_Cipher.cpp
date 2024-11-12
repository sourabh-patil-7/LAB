#include <bits/stdc++.h>
#include <string>

using namespace std;

// Function to encrypt the text using Caesar Cipher
string caesarCipherEncrypt(string text, int shift)
{
    string result = "";

    // Traverse the text
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch))
        {
            result += char(int(ch + shift - 65) % 26 + 65);
        }
        // Encrypt lowercase letters
        else if (islower(ch))
        {
            result += char(int(ch + shift - 97) % 26 + 97);
        }
        // If it's not an alphabet, keep it unchanged
        else
        {
            result += ch;
        }
    }

    return result;
}

// Function to decrypt the text using Caesar Cipher
string caesarCipherDecrypt(string text, int shift)
{
    string result = "";

    // Traverse the text
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];

        // Decrypt uppercase letters
        if (isupper(ch))
        {
            result += char(int(ch - shift - 65 + 26) % 26 + 65);
        }
        // Decrypt lowercase letters
        else if (islower(ch))
        {
            result += char(int(ch - shift - 97 + 26) % 26 + 97);
        }
        // If it's not an alphabet, keep it unchanged
        else
        {
            result += ch;
        }
    }

    return result;
}

int main()
{
    string text;
    int shift;

    cout << "Enter the text to be encrypted: ";
    getline(cin, text);

    cout << "Enter the shift value: ";
    cin >> shift;

    string encryptedText = caesarCipherEncrypt(text, shift);
    string decryptedText = caesarCipherDecrypt(encryptedText, shift);

    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
