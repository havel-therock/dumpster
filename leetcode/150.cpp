// 150. Evaluate Reverse Polish Notation
//
//
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
  public:
    Solution()
        : m_operators({"+", "-", "*", "/"})
    {}

    int evalRPN(std::vector<std::string>& tokens)
    {

        for (const auto& token : tokens) {
            if (is_operator(token)) {
                int operand2 = m_output.top();
                m_output.pop();
                int operand1 = m_output.top();
                m_output.pop();

                m_output.push(calculate(operand1, operand2, token));
            } else {
                m_output.push(atoi(token.c_str()));
            }
        }
        return m_output.top();
    }

  private:
    inline bool is_operator(const std::string& token) { return m_operators.find(token) != m_operators.end(); }

    int calculate(int arg1, int arg2, const std::string& op)
    {
        int result = 0;
        if (op == "+") {
            result = arg1 + arg2;
        } else if (op == "-") {
            result = arg1 - arg2;
        } else if (op == "*") {
            result = arg1 * arg2;
        } else if (op == "/") {
            result = arg1 / arg2;
        }
        return result;
    }


    std::stack<int> m_output;
    const std::unordered_set<std::string> m_operators;
};

int main(int argc, char** argv)
{

    std::cout << "Result: " << atoi("2+3") << "\n";
    Solution s{};

    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    std::cout << "Result: " << s.evalRPN(tokens) << "\n";
    return 0;
}
