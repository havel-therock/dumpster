#include <iostream>
#include <sstream>
#include <string>
#include <vector>


class Code
{
  public:
    Code(const std::string& name, const std::string& type)
        : m_name(name)
        , m_type(type)
    {
        if (type == "class") {
        }
    }


    std::string str(uint32_t indent = 0) const
    {
        indent++;
        std::ostringstream oss;
        oss << std::string(2 * (indent - 1), ' ') << m_type << " " << m_name;
        if (m_type == "class") {
            oss << "\n" << std::string(2 * (indent - 1), ' ') << "{\n";
        } else {
            oss << ";\n";
        }

        for (auto& child : childrens) {
            oss << child.str(indent);
        }

        if (m_type == "class") {
            oss << std::string(2 * (indent - 1), ' ') << "};\n";
        }
        return oss.str();
    }


    std::vector<Code> childrens;

  private:
    const std::string m_name;
    const std::string m_type;
};


class CodeBuilder
{
  public:
    CodeBuilder(const std::string& class_name)
        : root(Code{class_name, "class"})
    {
    }

    CodeBuilder& add_field(const std::string& name, const std::string& type)
    {
        root.childrens.emplace_back(name, type);
        return *this;
    }

    operator Code() { return root; }

    friend std::ostream& operator<<(std::ostream& os, const CodeBuilder& obj) { return os << obj.root.str(); }

  private:
    Code root;
};

int main(int argc, char** argv)
{
    auto cb = CodeBuilder{"Person"}
                  .add_field("name", "std::string")
                  .add_field("age", "int")
                  .add_field("insideClass", "class")
                  .add_field("test_int", "int");
    std::cout << cb;
    std::cout << static_cast<Code>(cb).str();
    return 0;
}

// class Person
//{
//   std::string name;
//   int age;
// };
// Please observe the same placement of curly braces and use two-space indentation.
