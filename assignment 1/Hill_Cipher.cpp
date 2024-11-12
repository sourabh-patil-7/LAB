#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> keyMatrix = {{3, 3}, {2, 5}};

vector<int> multiplyMatrix(vector<int> vec)
{
    vector<int> result(2);
    result[0] = (keyMatrix[0][0] * vec[0] + keyMatrix[0][1] * vec[1]) % 26;
    result[1] = (keyMatrix[1][0] * vec[0] + keyMatrix[1][1] * vec[1]) % 26;
    return result;
}

string hillEncrypt(string text)
{
    string result = "";
    for (int i = 0; i < text.length(); i += 2)
    {
        vector<int> vec = {text[i] - 'A', text[i + 1] - 'A'};
        vector<int> resVec = multiplyMatrix(vec);
        result += (char)(resVec[0] + 'A');
        result += (char)(resVec[1] + 'A');
    }
    return result;
}

int main()
{
    string text = "Cryptography";
    string encrypted = hillEncrypt(text);
    cout << "Plaintext: " << text << endl;
    cout << "Encrypted: " << encrypted << endl;
    return 0;
}
