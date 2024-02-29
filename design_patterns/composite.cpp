// Composite Coding Exercise
// Consider the code presented below. The sum()  function takes a vector of pointers to either SingleValue or ManyValues
// instances and adds up all their elements together.
//
// Please complete the implementation so that the sum()  function starts to operate correctly. This may involve giving
// the classes a common interface, among other things.
//
// Here is an example of how the function might be used:
//
// SingleValue single_value{ 1 };
// ManyValues other_values;
// other_values.add(2);
// other_values.add(3);
// sum({ &single_value, &other_values }); // returns 6


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// #include "exercise.h"
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ContainsIntegers
{
  public:
    virtual int calculate() const = 0;
};

struct SingleValue : ContainsIntegers {
    int value{0};

    SingleValue() = default;

    explicit SingleValue(const int value)
        : value{value}
    {
    }

    int calculate() const override { return value; }
};

struct ManyValues : std::vector<int>, ContainsIntegers {
    void add(const int value) { push_back(value); }

    int calculate() const override
    {
        int result = 0;
        for (auto val : *this) {
            result += val;
        }
        return result;
    };

    // int sum(const std::vector<ContainsIntegers*> items);
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <vector>


int sum(const std::vector<ContainsIntegers*> items)
{
    int result = 0;
    for (auto const item : items) {
        result += item->calculate();
    }
    return result;
}
