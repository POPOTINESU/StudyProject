#include <iostream>
#include <vector>
using namespace std;

// 再帰を使って解くやり方
int fibonacciRecursionHelper(int f1, int f2, int n)
{
    if (n < 1)
        return f1;

    return fibonacciRecursionHelper(f2, f1 + f2, n - 1);
}

int fibonacciRecursion(int n)
{
    int answer = fibonacciRecursionHelper(0, 1, n);

    cout << answer << endl;
    return answer;
}


// タービュレーション
int fibonacciFib(int n)
{
    vector<long int> cache;
    for (int i = 0; i <= n; i++)
    {
        cache.push_back(0);
    }
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i <= n; i++){
        cache[i] = cache[i-1]+cache[i-2];
    }
    cout << cache[n] << endl;
    return cache[n];
}

// メモ化で解く方法

int fibonacciMemo(int n){
    vector<long int> cache;
    for (int i = 0; i <= n; i++){
        cache.push_back(i);
    }

    if(cache[n] == 0){
        if (n == 0){
            return 0;
        } else if(n == 1){
            return 1;
        }else{
            cache[n] = fibonacciMemo(n-1)+fibonacciMemo(n-2);
        }
    }

    cout << cache[n] << endl;
    return cache[n];
}

int main(){
    int n = 5;

    fibonacciRecursion(5);
    fibonacciFib(5);
    fibonacciMemo(5);
}