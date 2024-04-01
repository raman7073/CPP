/* Yes, there is an alternate approach to solve this problem.
Instead of creating a copy of the array and sorting it,
we can use the concept of cycles to find the minimum number of swaps.
We can iterate through the array and for each element,
find the length of the cycle it belongs to.
The number of swaps required in each cycle is the length of the cycle minus 1.
We can sum up the number of swaps required for each cycle to get the total
number of swaps needed to sort the array.
This approach has a time complexity of O(nlogn) and auxiliary space complexity of O(n).
*/
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> arrPos(n);
    for (int i = 0; i < n; i++)
    {
        arrPos[i] = {arr[i], i};
    }

    // Sort the array by array element values to get right position of every element as the elements of second array.
    sort(arrPos.begin(), arrPos.end());

    // To keep track of visited elements. Initialize all elements as not visited or false.
    vector<bool> visited(n, false);

    // Initialize result
    int swaps = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or already present at correct pos
        if (visited[i] || arrPos[i].second == i)
        {
            continue;
        }

        // Find number of nodes in this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!visited[j])
        {
            visited[j] = true;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.
        if (cycle_size > 0)
        {
            swaps += (cycle_size - 1);
        }
    }

    // Return result
    return swaps;
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 2};
    cout << "Minimum number of swaps required: " << minSwaps(arr) << endl;
    return 0;
}
