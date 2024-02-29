
#include <sstream>
#include <string>
using namespace std;

struct Flower {
    virtual string str() = 0;
};

struct Rose : Flower {
    string str() override
    {
        ostringstream oss;
        oss << "A rose";
        return oss.str();
    }
};


struct RedFlower : Flower {
    Flower& m_flower;

    RedFlower(Flower& flower)
        : m_flower(flower)
    {
    }


    string str() override
    {
        ostringstream oss;
        oss << m_flower.str();
        if (oss.str().length() == 6) {
            oss << " that is red";
        } else if (oss.str().length() == 19) {
            oss << " and red";
        }
        return oss.str();
    }
};

struct BlueFlower : Flower {
    Flower& m_flower;

    BlueFlower(Flower& flower)
        : m_flower(flower)
    {
    }

    string str() override
    {
        ostringstream oss;
        oss << m_flower.str();
        if (oss.str().length() == 6) {
            oss << " that is blue";
        } else if (oss.str().length() == 18) {
            oss << " and blue";
        }
        return oss.str();
    }
};
