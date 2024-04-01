#include <iostream>
#include <list>
#include <unordered_map>

int main()
{
    int N;
    std::cin >> N;

    std::list<int> A;
    std::unordered_map<int, std::list<int>::iterator> positions;

    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        A.push_back(num);
        positions[num] = std::prev(A.end());
    }

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int type, x;
        std::cin >> type >> x;

        if (type == 1)
        {
            int y;
            std::cin >> y;
            auto it = positions[x];
            A.insert(std::next(it), y);
            positions[y] = std::next(it);
        }
        else if (type == 2)
        {
            auto it = positions[x];
            A.erase(it);
            positions.erase(x);
        }
    }

    for (int num : A)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}