#include <algorithm>
#include <array>
#include <bitset>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>


// Ex 1 ////////////////////////////////////////////////////////////////////////
int solution1(std::string& S)
{
    int operation_count = 0;
    // Strip leading 0s
    S.erase(0, S.find_first_of('1'));

    // check if not empty meaning s was just a zero -> return 0;
    if (S.empty()) {
        return 0;
    }

    for (const auto& ch : S) {
        if (ch == '1') {
            operation_count += 2;
        } else if (ch == '0') {
            operation_count++;
        }
    }
    operation_count--;

    return operation_count;
}

////////////////////////////////////////////////////////////////////////////////


// Ex 2 ////////////////////////////////////////////////////////////////////////
int solution2(std::string& S)
{
    int substr_count = 1;
    std::unordered_set<char> current_substr;
    for (const auto& ch : S) {
        if (current_substr.count(ch)) {
            substr_count++;
            current_substr = {ch};
        } else {
            current_substr.insert(ch);
        }
    }

    return substr_count == 1 ? 0 : substr_count;
}

////////////////////////////////////////////////////////////////////////////////


// Ex 3 ////////////////////////////////////////////////////////////////////////
int solution(std::vector<std::string>& S, int K)
{
    // Implement your solution here
    // 0 - a, 9 - f;
    std::map<uint32_t, uint32_t> bitmasks = {};
    for (auto& str : S) {
        std::bitset<10> current_mask{false};
        for (auto& ch : str) {
            current_mask[ch - 'a'] = true;
        }
        if (current_mask.count() > K) {
            continue;
        }
        for (auto& [mask, word_count] : bitmasks) {
            if ((mask & current_mask.to_ulong()) == current_mask.to_ulong()) {
                bitmasks[mask]++;
            } else if ((mask & current_mask.to_ulong()) == mask) {
                bitmasks[current_mask.to_ulong()]++;
            }
        }
        if (bitmasks.count(current_mask.to_ulong()) == 0) {
            bitmasks[current_mask.to_ulong()] = 1;
        }
    }
    return std::max_element(bitmasks.begin(), bitmasks.end(),
                            [](const std::pair<uint32_t, uint32_t>& a, const std::pair<uint32_t, uint32_t>& b) {
                                return a.second < b.second;
                            })->second;
}
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
    std::vector<std::string> s = {"abc", "abb", "cb", "a", "bbb", "a"};
    int k = 2;
    std::cout << solution(s, k) << "\n";
    return 0;
}
