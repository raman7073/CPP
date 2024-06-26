int leadOptions(int N, vector<int> &E)
{
    int maxElement = INT_MIN;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (E[i] > maxElement)
        {
            maxElement = E[i];
            count = 1;
        }
        else if (E[i] == maxElement)
        {
            count++;
        }
    }

    return count;
}