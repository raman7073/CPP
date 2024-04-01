#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the digit sum of a positive integer
int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to count good numbers (numbers in A005349) up to N
long long countGoodNumbers(long long N)
{
    vector<int> countByDigitSum(10, 0);

    for (int i = 1; i <= N; ++i)
    {
        int sumDigits = digitSum(i);
        countByDigitSum[sumDigits]++;
    }

    long long count = 0;

    for (int i = 1; i <= 9; ++i)
    {
        count += countByDigitSum[i] * (N / i);
    }

    return count;
}

int main()
{
    long long N;
    cin >> N;
    cout << countGoodNumbers(N) << endl;

    return 0;
}
