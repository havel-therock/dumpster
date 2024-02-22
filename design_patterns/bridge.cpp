#include <string>
using namespace std;

struct Renderer {
    virtual string str(const string& name) const = 0;
};

struct Shape {
    string name;

protected:
    Shape(const Renderer& r) : renderer(r) {}
    const Renderer& renderer;
};

struct Triangle : Shape {
    Triangle(const Renderer& r) : Shape(r) { name = "Triangle"; }
    std::string str() { return renderer.str(name); }
};

struct Square : Shape {
    Square(const Renderer& r) : Shape(r) { name = "Square"; }
    std::string str() { return renderer.str(name); }
};


struct VectorRenderer : Renderer {
    string str(const string& s) const override { return "Drawing " + s + " as lines"; }
};

struct RasterRenderer : Renderer {
    string str(const string& s) const override { return "Drawing" + s + " as pixels"; }
};

// imagine e.g. VectorTriangle/RasterTriangle etc. here

