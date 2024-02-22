// 49. Group Anagram
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


class Solution
{
  public:
    static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, uint32_t> groups;
        uint32_t idx = 0, group_index = 0;

        for (auto str : strs) {
            std::sort(str.begin(), str.end());
            if (groups.count(str)) {
                result[groups[str]].push_back(strs[idx]);
            } else {
                result.push_back({strs[idx]});
                groups.insert({str, group_index});
                group_index++;
            }
            idx++;
        }

        return result;
    }
};


int main(int argc, char** argv)
{
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = Solution::groupAnagrams(strs);

    std::ostringstream oss;

    for (auto& group : result) {
        oss << "{";
        for (auto str : group) {
            oss << str << " ";
        }
        oss << "}, ";
    }

    std::cout << oss.str();
    return 0;
}
