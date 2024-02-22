// 1232. Check If It Is A Straight Line

#include <algorithm>
#include <iostream>
#include <vector>


class Solution
{
  public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates)
    {
        if (coordinates.size() == 2) {
            return true;
        }

        // line formula y = mx + c
        // gradient formula (angle of the line) m = (y2 - y1) / (x2 - x1)
        // There could be a need for sorting points by x.

        bool straight_up_line = false;
        double gradient = 0.0;
        if (coordinates[1][0] - coordinates[0][0] == 0) {
            straight_up_line = true;
        } else {
            gradient =
                (coordinates[1][1] - coordinates[0][1]) / static_cast<double>(coordinates[1][0] - coordinates[0][0]);
        }

        auto it = std::adjacent_find(
            coordinates.begin() + 1, coordinates.end(),
            [straight_up_line, gradient](const std::vector<int>& point1, const std::vector<int>& point2) {
                if (straight_up_line) {
                    return (point2[0] - point1[0]) != 0;
                } else {
                    return gradient != (point2[1] - point1[1]) / static_cast<double>(point2[0] - point1[0]);
                }
            });
        return it == coordinates.end();
    }
};

int main(int argc, char** argv)
{
    Solution s;

    std::vector<std::vector<int>> coords = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    std::vector<std::vector<int>> coords2 = {{0, 0}, {0, 1}, {0, -1}};
    std::cout << "Result:" << s.checkStraightLine(coords2) << "\n";

    return 0;
}
