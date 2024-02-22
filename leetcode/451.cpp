// 451. Sort Characters By Frequencey

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

class Solution
{
  public:
    std::string frequencySort(std::string s) {
        std::ostringstream oss;
        std::vector<std::pair<uint32_t, char>> sorted_occurence{256, {0,0}};
        for (char ch : s) {
            sorted_occurence[ch].first++;
            sorted_occurence[ch].second = ch;
        }

        std::sort(sorted_occurence.begin(), sorted_occurence.end(), std::greater());

        for (auto ch : sorted_occurence) {
            oss << std::string(ch.first, ch.second);
        }

        return oss.str();
    }
};

int main(int argc, char** argv)
{
    Solution s;
    std::cout << s.frequencySort("tree");

    return 0;
}
