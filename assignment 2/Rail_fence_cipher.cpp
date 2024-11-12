#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to encrypt using the Rail Fence Cipher
string railFenceEncrypt(string text, int key)
{
    if (key == 1)
        return text; // Special case where key is 1 (no encryption)

    vector<string> rail(key);
    int direction = -1;
    int row = 0;

    for (char c : text)
    {
        rail[row] += c;

        // Change direction when you reach the top or bottom rail
        if (row == 0 || row == key - 1)
        {
            direction *= -1;
        }

        row += direction;
    }

    // Combine all the rails to form the ciphertext
    string cipherText;
    for (const string &line : rail)
    {
        cipherText += line;
    }

    return cipherText;
}

// Function to decrypt using the Rail Fence Cipher
string railFenceDecrypt(string cipherText, int key)
{
    if (key == 1)
        return cipherText; // Special case where key is 1 (no decryption)

    vector<int> railLength(key, 0);
    int direction = -1;
    int row = 0;

    // First determine the length of each rail
    for (char c : cipherText)
    {
        railLength[row]++;
        if (row == 0 || row == key - 1)
        {
            direction *= -1;
        }
        row += direction;
    }

    // Now, populate the rails with the cipher text
    vector<string> rail(key);
    int index = 0;
    for (int i = 0; i < key; i++)
    {
        rail[i] = cipherText.substr(index, railLength[i]);
        index += railLength[i];
    }

    // Reconstruct the original text by reading in zigzag order
    string plainText;
    row = 0;
    direction = -1;
    int railPos[key] = {0};

    for (int i = 0; i < cipherText.length(); i++)
    {
        plainText += rail[row][railPos[row]++];
        if (row == 0 || row == key - 1)
        {
            direction *= -1;
        }
        row += direction;
    }

    return plainText;
}

int main()
{
    string text;
    int key;

    cout << "Enter the plaintext: ";
    getline(cin, text);
    cout << "Enter the key (number of rails): ";
    cin >> key;

    string cipherText = railFenceEncrypt(text, key);
    cout << "Encrypted Text: " << cipherText << endl;

    string decryptedText = railFenceDecrypt(cipherText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
