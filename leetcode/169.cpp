// 169. Majority Element

#include <iostream>
#include <vector>


class Solution
{
  public:
    int majorityElement(std::vector<int>& nums)
    {
        int majority_candidate = nums.at(0);
        uint32_t counter = 0;
        for (int num : nums) {
            if (num == majority_candidate) {
                counter++;
            } else {
                if (counter == 1) {
                    majority_candidate = num;
                } else {
                    counter--;
                }
            }
        }

        return majority_candidate;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> nums = {3, 2, 3};
    std::cout << s.majorityElement(nums);

    return 0;
}
