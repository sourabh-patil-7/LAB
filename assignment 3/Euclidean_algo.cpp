#include <bits/stdc++.h>

using namespace std;

// Function to compute the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main()
{
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
