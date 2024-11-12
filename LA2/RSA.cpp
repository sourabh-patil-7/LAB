#include <iostream>
#include <gmpxx.h>

using namespace std;

// Function to calculate gcd
mpz_class gcd(mpz_class a, mpz_class b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to perform modular exponentiation
mpz_class modExp(mpz_class base, mpz_class exp, mpz_class mod)
{
    mpz_class result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // equivalent to exp / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to generate a random prime number
mpz_class generatePrime(int bits)
{
    gmp_randclass r(gmp_randinit_default);
    r.seed(time(0));
    return r.get_z_prime(bits);
}

// Function to generate RSA keys
void generateKeys(mpz_class &e, mpz_class &d, mpz_class &n)
{
    mpz_class p = generatePrime(512);  // Generate a random prime number p
    mpz_class q = generatePrime(512);  // Generate a random prime number q
    n = p * q;                         // n is the product of p and q
    mpz_class phi = (p - 1) * (q - 1); // phi(n)

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    e = 65537; // Common choice for e
    while (gcd(e, phi) != 1)
    {
        e += 2; // Increment e by 2 to keep it odd
    }

    // Calculate d, the modular multiplicative inverse of e mod phi
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());
}

// Function to encrypt a message
mpz_class encrypt(mpz_class e, mpz_class n, mpz_class message)
{
    return modExp(message, e, n);
}

// Function to decrypt a message
mpz_class decrypt(mpz_class d, mpz_class n, mpz_class cipher)
{
    return modExp(cipher, d, n);
}

int main()
{
    mpz_class e, d, n;
    generateKeys(e, d, n);

    cout << "Public Key: (e = " << e << ", n = " << n << ")" << endl;
    cout << "Private Key: (d = " << d << ", n = " << n << ")" << endl;

    mpz_class message;
    cout << "Enter a message to encrypt (as an integer): ";
    cin >> message;

    mpz_class cipher = encrypt(e, n, message);
    cout << "Encrypted message: " << cipher << endl;

    mpz_class decryptedMessage = decrypt(d, n, cipher);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}