#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Row and Column Transformation Encryption
string rowColumnEncrypt(string text, vector<int> key)
{
    int n = key.size();
    int paddedLen = text.length() + (n - text.length() % n) % n;
    text.append(paddedLen - text.length(), 'X');

    vector<string> grid;
    for (int i = 0; i < text.length(); i += n)
    {
        grid.push_back(text.substr(i, n));
    }

    string encryptedText;
    for (int i : key)
    {
        for (const string &row : grid)
        {
            encryptedText += row[i - 1];
        }
    }

    return encryptedText;
}

// Row and Column Transformation Decryption
string rowColumnDecrypt(string cipher, vector<int> key)
{
    int n = key.size();
    int numRows = cipher.length() / n;

    vector<string> grid(numRows, string(n, ' '));
    int index = 0;

    for (int i : key)
    {
        for (int j = 0; j < numRows; ++j)
        {
            grid[j][i - 1] = cipher[index++];
        }
    }

    string decryptedText;
    for (const string &row : grid)
    {
        decryptedText += row;
    }

    while (decryptedText.back() == 'X')
    {
        decryptedText.pop_back();
    }

    return decryptedText;
}

int main()
{
    string plaintext = "Sourabh Patil";
    vector<int> key = {3, 1, 4, 2};

    string encryptedText = rowColumnEncrypt(plaintext, key);
    string decryptedText = rowColumnDecrypt(encryptedText, key);

    cout << "\nRow and Column Transformation:\nEncrypted: " << encryptedText << "\nDecrypted: " << decryptedText << endl;

    return 0;
}
