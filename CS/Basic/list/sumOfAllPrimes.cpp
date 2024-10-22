#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primeNums(int n)
{
    vector<bool> isPrimeList;
    vector<int> primeList;
    for (int i = 0; i <= n; i++)
    {
        isPrimeList.push_back(true);
    }

    for (int i = 2; i <= pow(n, 0.5); i++)
    {
        if (!isPrimeList[i])
            continue;

        // iはtrueであるため
        int loopNum = i * 2;
        while (loopNum <= n)
        {
            isPrimeList[loopNum] = false;
            loopNum += i;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrimeList[i])
            primeList.push_back(i);
    }

    return primeList;
}

int sumOfAllPrimes(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    vector<int> primeList = primeNums(n);
    int answer = 0;
    for (int i = 0; i < primeList.size(); i++)
    {
        answer += primeList[i];
    }

    return answer;
}

int main()
{
    cout << sumOfAllPrimes(100) << endl;
}