//
// Created by kevin on 21/04/2025.
//


#include <utility>

class TestingTwo {
public:
    virtual ~TestingTwo() = default;

    [[nodiscard]] int a1() const {
        return a;
    }

    void a1(const int a) {
        this->a = a;
    }

    [[nodiscard]] virtual int b1() const {
        return b;
    }

    friend void swap(TestingTwo &lhs, TestingTwo &rhs) noexcept {
        using std::swap;
        swap(lhs.a, rhs.a);
        swap(lhs.b, rhs.b);
        swap(lhs.c, rhs.c);
    }


    void b1(const int b) {
        this->b = b;
    }

    [[nodiscard]] float c1() const {
        return c;
    }

    void c1(const float c) {
        this->c = c;
    }

    TestingTwo(int a, int b, float c)
        : a(a),
          b(b),
          c(c) {
    }

private:
    int a;
    int b;
    float c;
};
