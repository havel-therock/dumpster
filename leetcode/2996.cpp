// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

#include <array>
#include <iostream>
#include <vector>


class Solution
{
  public:
    int missingInteger(std::vector<int>& nums)
    {
        uint8_t seq_len = 1;
        uint16_t seq_sum = *nums.begin();
        std::array<bool, 51> appears_table = {};
        appears_table[*nums.begin()] = true;
        for (auto it_dragging = nums.begin(), it = nums.begin() + 1; it < nums.end(); it++, it_dragging++) {
            appears_table[*it] = true;
            if (*it == (*it_dragging) + 1) {
                seq_len++;
                seq_sum += *it;
            } else {
                while (it != nums.end()) {
                    appears_table[*it] = true;
                    it++;
                }
                break;
            }
        }


        if (seq_sum > 50)
            return seq_sum;

        for (auto it2 = appears_table.begin() + seq_sum; it2 < appears_table.end(); it2++) {
            if (!*it2) {
                return std::distance(appears_table.begin(), it2);
            }
        }

        return 51;
    }


    int missingIntegerNotOnlyPrefixAnySequence(std::vector<int>& nums)
    {
        uint8_t longest_seq_len = 1;
        uint16_t longest_seq_sum = *nums.begin();
        uint8_t current_seq_len = 1;
        uint16_t current_seq_sum = *nums.begin();
        auto it_dragging = nums.begin();
        std::array<bool, 51> appears_table = {};
        appears_table[*it_dragging] = true;
        for (auto it = nums.begin() + 1; it < nums.end(); it++, it_dragging++) {
            appears_table[*it] = true;
            if (*it == (*it_dragging) + 1) {
                current_seq_len++;
                current_seq_sum += *it;
            } else {
                if (current_seq_len > longest_seq_len) {
                    longest_seq_len = current_seq_len;
                    longest_seq_sum = current_seq_sum;
                }
                current_seq_len = 1;
                current_seq_sum = *it;
            }
        }
        if (current_seq_len > longest_seq_len) {
            longest_seq_sum = current_seq_sum;
        }


        // look for the sum or look right for the next values

        if (longest_seq_sum > 50)
            return longest_seq_sum;

        for (auto it2 = appears_table.begin() + longest_seq_sum; it2 < appears_table.end(); it2++) {
            if (!*it2) {
                return std::distance(appears_table.begin(), it2);
            }
        }

        return 51;
    }
};


int main(int argc, char** argv)
{
    Solution sol;
    std::vector<int> case1 = {29, 30, 31, 32, 33, 34, 35, 36, 37};
    std::cout << sol.missingInteger(case1) << "\n";
    return 0;
}
