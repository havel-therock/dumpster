// 387. First Unique Character in a String
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>


class Solution
{
  public:
    int firstUniqChar(std::string s)
    {
        std::unordered_set<char> reoccuring;
        std::unordered_map<char, uint32_t> search_map;
        uint32_t idx = 0;
        for (auto ch : s) {
            if (reoccuring.count(ch)) {
                idx++;
                continue;
            }

            if (search_map.count(ch)) {
                reoccuring.insert(ch);
                search_map.erase(ch);
            } else {
                search_map.insert({ch, idx});
            }
            idx++;
        }

        uint32_t min_idx = UINT32_MAX;
        for (auto [ch, idx] : search_map) {
            if (min_idx > idx) {
                min_idx = idx;
            }
        }

        return min_idx == UINT32_MAX ? -1 : min_idx;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    std::string s = "dddccdbba";
    std::cout << sol.firstUniqChar(s);
    return 0;
}
