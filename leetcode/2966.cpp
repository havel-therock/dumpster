// 2966. Divide Array Into Arrays With Max Difference

#include <algorithm>
#include <iostream>
#include <vector>


class Solution
{
  public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result(nums.size() / 3, std::vector<int>(3));
        uint32_t idx = 0;
        for (auto val : nums) {
            uint8_t second_idx = idx%3;
            uint32_t first_idx = idx/3;
            result[first_idx][second_idx] = val;

            if(second_idx == 2 && abs(result[first_idx][second_idx] - result[first_idx][0]) > k ) {
               return {};
            }
            idx++;
        }
        return result;
    }
};

int main(int argc, char** argv)
{
    Solution s{};
    std::vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    std::vector<std::vector<int>> result = s.divideArray(nums, k);
    std::cout << "Result:\n";
    for (auto arr : result) {
        for (auto i : arr) {
            std::cout << i << " ";
        }
        std::cout << "| ";
    }

    return 0;
}
