#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;
bool isPrime(int n)
{
    if (n == 1)
    {
        return true;
    }
    else if (n <= 2)
    {
        false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> primeArray(int n)
{
    vector<int> primeArrays;
    if (n < 2)
        return primeArrays;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            primeArrays.push_back(i);
    }

    return primeArrays;
}

int main()
{
    primeArray(97);
    return 0;
}