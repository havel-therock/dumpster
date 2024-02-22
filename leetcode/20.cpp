// 20. Valid Parentheses

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution
{
  public:
    bool isValid(std::string s)
    {
        std::stack<char> tracking_stack = {};
        for (char ch : s) {
            std::unordered_map<char, char>::const_iterator iter = m_parentheses_map.find(ch);
            // this if is only for nad input string (one that contains other characters than in a map).
            // shouldn't happen.
            if (iter == m_parentheses_map.cend()) {
                return false;
            }
            if (iter->second == '\0') {
                tracking_stack.push(iter->first);
            } else if (!tracking_stack.empty() && tracking_stack.top() == iter->second) {
                tracking_stack.pop();
            } else {
                return false;
            }
        }

        return tracking_stack.empty();
    }

  private:
    const std::unordered_map<char, char> m_parentheses_map = {{'{', '\0'}, {'(', '\0'}, {'[', '\0'},
                                                              {'}', '{'},  {')', '('},  {']', '['}};
};

int main(int argc, char** argv)
{
    Solution s;
    const std::string str = "()[()]{}";
    std::cout << "Result:" << s.isValid(str) << "\n";

    return 0;
}
