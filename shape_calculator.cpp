// Mini-Project 3: Shape Area & Perimeter Calculator
// Concepts: Inheritance, virtual functions, overriding, runtime polymorphism, encapsulation
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

// Base class: common interface for all shapes
class Shape {
public:
    virtual double area() const = 0;        // virtual: each shape gives its own formula
    virtual double perimeter() const = 0;
    virtual const char* name() const = 0;
    virtual
	 ~Shape() {}                     // virtual destructor
};

class Circle : public Shape {
private:                                    // encapsulation: dimensions are hidden
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override      { return PI * radius * radius; }
    double perimeter() const override { return 2 * PI * radius; }
    const char* name() const override { return "Circle"; }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override      { return length * width; }
    double perimeter() const override { return 2 * (length + width); }
    const char* name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
private:
    double a, b, c;                         // three sides
public:
    Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
    double area() const override {          // Heron's formula
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }
    const char* name() const override { return "Triangle"; }
};

// Works with ANY shape through a base-class reference (runtime polymorphism)
void showResult(const Shape& s) {
    cout << s.name() << " -> Area: " << s.area()
         << " | Perimeter: " << s.perimeter() << "\n";
}

int main() {
    double r, l, w, s1, s2, s3;

    cout << "===== Shape Area & Perimeter Calculator =====\n";

    cout << "\nCircle - enter radius: ";
    cin >> r;
    cout << "Rectangle - enter length and width: ";
    cin >> l >> w;
    cout << "Triangle - enter three sides: ";
    cin >> s1 >> s2 >> s3;

    if (r <= 0 || l <= 0 || w <= 0 || s1 <= 0 || s2 <= 0 || s3 <= 0) {
        cout << "\nError: all dimensions must be positive.\n";
        return 1;
    }
    if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
        cout << "\nError: these sides cannot form a triangle.\n";
        return 1;
    }

    Circle c(r);
    Rectangle rect(l, w);
    Triangle t(s1, s2, s3);

    Shape* shapes[3] = { &c, &rect, &t };   // base-class pointers

    cout << "\n----------------- Results -----------------\n";
    for (int i = 0; i < 3; i++) {
        showResult(*shapes[i]);             // correct version chosen at runtime
    }
    return 0;
}
