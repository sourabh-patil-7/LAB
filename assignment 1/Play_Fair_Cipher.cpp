#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to remove duplicates from a string
string removeDuplicates(string str)
{
    string result;
    for (char c : str)
    {
        if (result.find(c) == string::npos)
        {
            result += c;
        }
    }
    return result;
}

// Function to prepare the 5x5 key matrix
void generateKeyMatrix(string key, char keyMatrix[5][5])
{
    key = removeDuplicates(key);                               // Remove duplicates from the key
    key.erase(remove(key.begin(), key.end(), 'J'), key.end()); // Remove 'J'

    vector<bool> used(26, false);
    used['J' - 'A'] = true; // Treat 'I' and 'J' as the same letter

    int index = 0;
    for (char c : key)
    {
        if (!used[c - 'A'])
        {
            keyMatrix[index / 5][index % 5] = c;
            used[c - 'A'] = true;
            index++;
        }
    }

    // Fill the remaining spaces with other letters
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (!used[c - 'A'])
        {
            keyMatrix[index / 5][index % 5] = c;
            index++;
        }
    }
}

// Function to find the position of a letter in the key matrix
void findPosition(char keyMatrix[5][5], char c, int &row, int &col)
{
    if (c == 'J')
        c = 'I'; // Treat 'I' and 'J' as the same letter
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyMatrix[i][j] == c)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of characters
string encryptPair(char keyMatrix[5][5], char a, char b)
{
    int row1, col1, row2, col2;
    findPosition(keyMatrix, a, row1, col1);
    findPosition(keyMatrix, b, row2, col2);

    if (row1 == row2)
    {
        // Same row, shift columns right
        return string(1, keyMatrix[row1][(col1 + 1) % 5]) + keyMatrix[row2][(col2 + 1) % 5];
    }
    else if (col1 == col2)
    {
        // Same column, shift rows down
        return string(1, keyMatrix[(row1 + 1) % 5][col1]) + keyMatrix[(row2 + 1) % 5][col2];
    }
    else
    {
        // Rectangle swap
        return string(1, keyMatrix[row1][col2]) + keyMatrix[row2][col1];
    }
}

// Function to prepare the plaintext by handling pairs
string prepareText(string text)
{
    string result;
    for (size_t i = 0; i < text.length(); i++)
    {
        result += toupper(text[i]);
        if (i + 1 < text.length() && toupper(text[i]) == toupper(text[i + 1]))
        {
            result += 'X'; // Insert 'X' between duplicate letters in a pair
        }
    }
    if (result.length() % 2 != 0)
    {
        result += 'X'; // Append 'X' if the length of the text is odd
    }
    return result;
}

// Function to encrypt the plaintext using Playfair cipher
string playfairEncrypt(string plaintext, string key)
{
    char keyMatrix[5][5];
    generateKeyMatrix(key, keyMatrix);

    plaintext = prepareText(plaintext);
    string cipherText = "";

    for (size_t i = 0; i < plaintext.length(); i += 2)
    {
        cipherText += encryptPair(keyMatrix, plaintext[i], plaintext[i + 1]);
    }

    return cipherText;
}

int main()
{
    string plaintext, key;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    cout << "Enter the key: ";
    getline(cin, key);

    string cipherText = playfairEncrypt(plaintext, key);
    cout << "Encrypted Text: " << cipherText << endl;

    return 0;
}
