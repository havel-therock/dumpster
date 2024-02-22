#include <string>


using namespace std;


struct Person {
    int id;
    string name;
};


class PersonFactory
{
  public:
    PersonFactory()
        : m_person_idx(0)
    {
    }

    Person create_person(const string& name)
    {
        Person p;
        p.id = m_person_idx;
        p.name = name;
        m_person_idx++;
        return p;
    }

  private:
    int m_person_idx;
};

int main(int argc, char** argv)
{
    PersonFactory pf;

    auto p = pf.create_person("Johnson");
    auto p2 = pf.create_person("Johnny");
    auto p3 = pf.create_person("Johnson");

    return 0;
}


// Factory Coding Exercise
// You are given a class called Person . The person has two fields: id , and name.
//
// Please implement a non-static PersonFactory that has a create_person() method that takes a person's name.
//
// The id  of the person should be set as a 0-based index of the object created. So, the first person the factory makes
// should have id=0, second id=1 and so on.
