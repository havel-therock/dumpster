struct Square {
    int side{0};

    explicit Square(const int side)
        : side(side)
    {
    }
};

struct Rectangle {
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const { return width() * height(); }
};

struct SquareToRectangleAdapter : Rectangle {
    SquareToRectangleAdapter(const Square& square)
        : m_sq(square)
    {
    }
    virtual inline int width() const { return m_sq.side; }
    virtual inline int height() const { return m_sq.side; }

  private:
    const Square& m_sq;
};
