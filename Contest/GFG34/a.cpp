#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int findMEX(const std::vector<int> &arr)
{
    std::unordered_set<int> numSet(arr.begin(), arr.end());
    for (int i = 0;; ++i)
    {
        if (numSet.find(i) == numSet.end())
        {
            return i;
        }
    }
}

int minElementsToRemove(std::vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    int originalMEX = findMEX(arr);

    if (originalMEX == 0)
    {

        return -1;
    }

    // Count the occurrences of numbers from 0 to originalMEX
    std::vector<int> count(originalMEX + 1, 0);
    for (int num : arr)
    {
        if (num <= originalMEX)
        {
            count[num]++;
        }
    }

    // If all numbers from 0 to originalMEX-1 are present, we need to remove one of them
    for (int i = 0; i < originalMEX; ++i)
    {
        if (count[i] == 0)
        {
            return -1; // If any number from 0 to originalMEX-1 is missing, it's impossible to change the MEX
        }
    }

    // The minimum number of elements to remove is the minimum count of any number from 0 to originalMEX-1
    int minRemovals = *std::min_element(count.begin(), count.end() - 1);
    return minRemovals;
}

int main()
{
    std::vector<int> arr = {0, 1, 2, 2, 3, 5};
    int result = minElementsToRemove(arr);
    if (result != -1)
    {
        std::cout << "Minimum elements to remove: " << result << std::endl;
    }
    else
    {
        std::cout << "It's not possible to change the MEX." << std::endl;
    }
    return 0;
}
