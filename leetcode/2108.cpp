// 2108. Find First Palindromic String in the Array

#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    std::string firstPalindrome(std::vector<std::string>& words)
    {
        for (const auto& str : words) {
            auto f_it = str.begin();
            auto r_it = str.rbegin();
            bool palindrome = true;
            while (std::distance(f_it, r_it.base() - 1) > 0) {
                if (*r_it != *f_it) {
                    palindrome = false;
                    break;
                }
                r_it++;
                f_it++;
            }
            if (palindrome) {
                return str;
            }
        }
        return "";
    }
};

int main(int argc, char** argv)
{
    Solution s;
    std::vector<std::string> words = {"abc", "car", "ada", "racecar", "cool"};
    std::cout << s.firstPalindrome(words);
    return 0;
}
