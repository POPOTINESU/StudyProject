#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int primesUpToNCount(int n)
{
    if (n <= 2)
    {
        return 0;
    }

    int primeCount = 0;
    vector<bool> primeList(n + 1, true);

    for (int i = 2; i <= pow(n, 0.5); i++)
    {
        int currentPrime = i;
        // すでに除外されている場合はスキップ
        if (!primeList[currentPrime])
            continue;

        currentPrime += i;
        while (currentPrime <= n)
        {   
            primeList[currentPrime] = false;
            currentPrime += i;
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (primeList[i])
            primeCount++;
    }

    return primeCount;
}

int main(){
    primesUpToNCount(13);
    return 0;
}
