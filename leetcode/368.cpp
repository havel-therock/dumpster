// 368. Largest Divisible Subset

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>


class Solution
{
  public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        std::unordered_map<int, std::vector<int>> subset_per_num;
        std::vector<int>* current_max_set = &subset_per_num[-1];
        for (auto it = nums.begin(); it < nums.end(); it++) {
            auto rev_it = it;
            while (rev_it != nums.begin()) {
                rev_it--;
                if (*it % *rev_it == 0 && subset_per_num[*rev_it].size() > subset_per_num[*it].size()) {
                    subset_per_num[*it] = subset_per_num[*rev_it];
                }
            }
            subset_per_num[*it].push_back(*it);
            if (subset_per_num[*it].size() > current_max_set->size()) {
                current_max_set = &subset_per_num[*it];
            }
        }

        return std::vector(current_max_set->begin(), current_max_set->end());
    }
};

int main(int argc, char** argv)
{
    Solution s;
    std::vector<int> nums = {4, 8, 10, 240};
    for (auto i : s.largestDivisibleSubset(nums)) {
        std::cout << i << ", ";
    }

    return 0;
}
