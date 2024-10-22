#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primeNums(int n)
{
    vector<bool> isPrimeList;
    for (int i = 0; i <= n; i++)
    {
        isPrimeList.push_back(true);
    }

    for (int i = 2; i < pow(n, 0.5); i++)
    {

        int currentPrime = i;

        // すでに判定されている場合
        if (!isPrimeList[currentPrime]){
            continue;
        }

        for (int j = currentPrime * 2; j < n; j += currentPrime)
        {
            isPrimeList[j] = false;
        }
    }

    vector<int> primeList;
    for (int i = 2; i <= n; i++){
        if(!isPrimeList[i]) continue;
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