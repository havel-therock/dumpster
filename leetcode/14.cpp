// 14. Longest Common Prefix

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


class Solution
{
  public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        std::string common_prefix = "";
        const std::string& smallest_str = *std::min_element(strs.begin(), strs.end());
        if (smallest_str == "") {
            return common_prefix;
        }
        short idx = 0;
        for (auto it = smallest_str.begin(); it < smallest_str.end(); it++) {
            const char under_check_val = *it;
            for (const std::string& str : strs) {
                if (str[idx] != under_check_val) {
                    return common_prefix;
                }
            }
            idx++;
            common_prefix += under_check_val;
        }


        return common_prefix;
    }
};


int main(int argc, char** argv)
{
    Solution s;
    std::vector<std::string> strs = {" henlo", " hder", " hfagrhtn", " h", " hewg"};

    std::cout << "Result:" << s.longestCommonPrefix(strs) << "\n";

    return 0;
}
