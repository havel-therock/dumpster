// 279. Perfect Square

#include <climits>
#include <cmath>
#include <iostream>
#include <vector>


class Solution
{
  public:
    int numSquares(int n)
    {
        std::vector<int> operations_count(n + 1);
        operations_count[0] = 0;
        operations_count[1] = 1;

        for (uint32_t idx = 2; idx < operations_count.size(); idx++) {
            int sqrt = static_cast<int>(std::sqrt(idx));

            if (idx == sqrt*sqrt) {
                operations_count[idx] = 1;
                continue;
            } else {
                int sqr_idx = 1;
                int min_operation_count = idx;
                while (sqr_idx < std::sqrt(idx)) {
                    if (operations_count[idx - sqr_idx*sqr_idx] + 1 < min_operation_count) {
                        min_operation_count = operations_count[idx - sqr_idx*sqr_idx] + 1;
                    }
                    sqr_idx++;
                }
                operations_count[idx] = min_operation_count;
            }
        }
        return operations_count.at(n);
    }
};


int main(int argc, char** argv)
{
    Solution s;
    std::cout << s.numSquares(12);
    return 0;
}
