#include <iostream>

using namespace std;

// Function to implement the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main()
{
    int a, b;
    int x, y;

    cout << "Enter two integers: ";
    cin >> a >> b;

    int gcd = extendedGCD(a, b, x, y);
    cout << "GCD of " << a << " and " << b << " is: " << gcd << endl;
    cout << "Coefficients x and y are: " << x << " and " << y << endl;
    cout << "Verification: " << a << " * " << x << " + " << b << " * " << y << " = " << gcd << endl;

    return 0;
}
