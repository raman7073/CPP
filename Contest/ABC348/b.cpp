#include <iostream>
#include <vector>
#include <cmath>

struct Point
{
    int id;
    int x;
    int y;
};

int main()
{
    int N;
    std::cin >> N;

    std::vector<Point> points(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> points[i].x >> points[i].y;
        points[i].id = i + 1;
    }

    for (const auto &p : points)
    {
        int farthestId = -1;
        double maxDistance = -1;

        for (const auto &q : points)
        {
            double distance = std::sqrt(std::pow(p.x - q.x, 2) + std::pow(p.y - q.y, 2));
            if (distance > maxDistance)
            {
                maxDistance = distance;
                farthestId = q.id;
            }
        }

        std::cout << farthestId << std::endl;
    }

    return 0;
}