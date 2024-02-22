#include <iostream>

#include <functional>


using namespace std;


struct SingletonTester {
    template <typename T>
    bool is_singleton(function<T*()> factory)
    {
        auto obj1 = factory();
        auto obj2 = factory();

        return obj1 == obj2;
    }
};


int main(void)
{
    std::cout << "a";

    return 0;
}
