// 1668. Maximum Repeating Substring

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


class Solution
{
  public:
    static int maxRepeatingBrute(std::string sequence, std::string word)
    {
        std::size_t found_in_pos = sequence.find(word);
        unsigned short max = 0, counter = 0, end_of_match = 0;
        std::string back_up = sequence;
        while (back_up.length() > 0) {
            if (found_in_pos != 0) {
                counter = 0;
                back_up = back_up.substr(1, back_up.length());
                sequence = back_up;
                found_in_pos = sequence.find(word);
                continue;
            }
            counter++;
            if (counter > max) {
                max = counter;
            }

            end_of_match = found_in_pos + word.length();
            sequence = sequence.substr(end_of_match, sequence.length() - end_of_match);
            found_in_pos = sequence.find(word);
        }

        return max;
    }


    static int maxRepeating(std::string sequence, std::string word)
    {
        const std::boyer_moore_searcher searcher(word.begin(), word.end());
        auto it = std::search(sequence.begin(), sequence.end(), searcher);
        std::vector<unsigned short> found_pos{};
        while (it != sequence.end()) {
            size_t pos = std::distance(sequence.begin(), it);
            found_pos.push_back(pos);
            it++;
            it = std::search(it, sequence.end(), searcher);
        }

        if (found_pos.empty()) {
            return 0;
        }

        std::sort(found_pos.begin(), found_pos.end());
        unsigned short wd_space = word.length();
        unsigned short max = 1;
        auto it2 = found_pos.begin();
        unsigned short counter = 1;

        while (!found_pos.empty()) {
            unsigned short next_value_pos = (*it2) + wd_space;
            auto it3 = std::find(found_pos.begin(), found_pos.end(), next_value_pos);

            // it2 = std::find_if(found_pos.begin(), found_pos.end(), [it2, wd_space](unsigned short val) {
            //     return val == (*it2) + wd_space;
            // });
            // it2 = found_pos.find((*it2) + wd_space);

            if (it3 != found_pos.end() && *it3 == next_value_pos) {
                counter++;
                found_pos.erase(it2);
                it2 = std::find(found_pos.begin(), found_pos.end(), next_value_pos);
            } else {
                counter = 1;
                found_pos.erase(it2);
                it2 = found_pos.begin();
            }

            if (counter > max) {
                max = counter;
            }
        }
        return max;
    }
};

int main(int argc, char** argv)
{
    std::string s1 = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
    std::string s2 = "aaaba";
    std::cout << Solution::maxRepeating(s1, s2) << "\n";
    // assert(sol.maxRepeating(s1, s2) == 5);
    std::cout << Solution::maxRepeating("aaaaaa", "a") << "\n";
    Solution::maxRepeating("ababc", "ab");
    Solution::maxRepeating("ababc", "ba");
    Solution::maxRepeating("ababc", "ac");
    // std::cout << "Result:" << sol.maxRepeatingBrute(s1, s2) << "\n";


    return 0;
}
