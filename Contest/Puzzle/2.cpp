#include <iostream>
#include <vector>
int weighingFunction(const std::vector<int> &weights, int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; ++i)
    {
        sum += weights[i];
    }
    return sum;
}
int findCounterfeitCoin(const std::vector<int> &weights)
{
    int left = 0;
    int right = weights.size() - 1;
    int count = 0;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        count++;

        int leftSum = weighingFunction(weights, left, mid);
        int rightSum = weighingFunction(weights, mid + 1, right);
        if (leftSum < rightSum)
        {
            right = mid;
        }
        else if (leftSum > rightSum)
        {
            left = mid + 1;
        }
        else
        {
            left = mid;
            right = mid;
        }
    }

    std::cout << "Number of iterations: " << count << std::endl;

    return left;
}

int main()
{
    std::vector<int> weights = {10, 10, 10, 10, 10, 10, 10, 10, 9, 10};
    int counterfeitIndex = findCounterfeitCoin(weights);

    std::cout << "The counterfeit coin is at index: " << counterfeitIndex << std::endl;

    return 0;
}