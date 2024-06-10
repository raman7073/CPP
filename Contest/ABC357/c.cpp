#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fillCarpet(vector<string> &carpet, int level, int x, int y, int size)
{
    if (level == 0)
    {
        carpet[x][y] = '#';
        return;
    }

    int newSize = size / 3;
    int subLevel = level - 1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1 && j == 1)
            {

                for (int dx = 0; dx < newSize; ++dx)
                {
                    for (int dy = 0; dy < newSize; ++dy)
                    {
                        carpet[x + i * newSize + dx][y + j * newSize + dy] = '.';
                    }
                }
            }
            else
            {

                fillCarpet(carpet, subLevel, x + i * newSize, y + j * newSize, newSize);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int size = 1;
    for (int i = 0; i < N; ++i)
    {
        size *= 3;
    }

    vector<string> carpet(size, string(size, '.'));

    fillCarpet(carpet, N, 0, 0, size);

    for (const string &row : carpet)
    {
        cout << row << endl;
    }

    return 0;
}
