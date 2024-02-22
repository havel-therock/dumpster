// 739. Daily Temperatures

#include <iostream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

class Solution
{
  public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::vector<int> days_to_wait(temperatures.size(), 0);
        // tuple <iter, idx, offset>
        std::stack<std::tuple<std::vector<int>::iterator, int, int>> trace_stack;
        int counter = 0;

        for (std::pair<std::vector<int>::iterator, int> for_pair({temperatures.begin(), 0});
             for_pair.first < temperatures.end(); for_pair.first++, for_pair.second++) {
            if (trace_stack.empty()) {
                counter = 0;
                trace_stack.push(std::make_tuple(for_pair.first, for_pair.second, counter));
            } else {
                if (*std::get<0>(trace_stack.top()) >= *for_pair.first) {
                    trace_stack.push(std::make_tuple(for_pair.first, for_pair.second, counter));
                } else {
                    std::tuple<std::vector<int>::iterator, int, int> check_tuple = trace_stack.top();
                    while (*std::get<0>(check_tuple) < *for_pair.first) {
                        days_to_wait[std::get<1>(check_tuple)] = counter - std::get<2>(check_tuple);
                        trace_stack.pop();
                        if (trace_stack.empty()) {
                            counter = 0;
                            break;
                        }
                        check_tuple = trace_stack.top();
                    }
                    // add t to a stack;
                    trace_stack.push(std::make_tuple(for_pair.first, for_pair.second, counter));
                }
            }
            counter++;
        }

        return days_to_wait;
    }
};

int main(int argc, char** argv)
{

    Solution s;
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> days_to_wait = s.dailyTemperatures(temperatures);

    // auto iter = temperatures.begin();
    // auto iter2 = days_to_wait.begin();

    for (auto t : temperatures) {
        std::cout << t << ", ";
    }
    std::cout << "\n";
    for (auto d : days_to_wait) {
        std::cout << d << ", ";
    }
    return 0;
}
