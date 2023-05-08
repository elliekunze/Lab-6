//
// Created by Ellie Kunze on 11/7/22.
//
#include <string>
using namespace std;
#define PI 3.14159f // Do a simple find-and-replace of PI everywhere in your code


class Shape {
public:
    const float PI_ = 3.14159f; // Create an actual variable with PI as its value.
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape() = 0;

};
class Shape2D : virtual public Shape
{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D& rhs) const;
    bool operator<(const Shape2D& rhs) const;
    bool operator==(const Shape2D& rhs) const;
};
class Shape3D : virtual public Shape
{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D& rhs) const;
    bool operator<(const Shape3D& rhs) const;
    bool operator==(const Shape3D& rhs) const;
};
class Square : virtual public Shape2D {
    string Shape; //name
    float side1; //base 1
public:
    Square(float side1 = 0.0, string Shape = "Square");
    string GetName2D() const {
        return Shape;
    }
    void Display() const;
    void Scale(float scaleFactor);
    float Area() const;
};

class Triangle : virtual public Shape2D {
private:
    string Shape;
    float side1, side2;
public:
    Triangle(float side1 = 0.0, float side2 = 0.0, string Shape = "Triangle");
    string GetName2D() const {
        return Shape;
    }
    void Display() const;
    void Scale(float scaleFactor);
    float Area() const;
};

class Circle : virtual public Shape2D {
public:
    string Shape;
    float side1;
    Circle(float side1 = 0.0, string Shape = "Circle");
    string GetName2D() const {
        return Shape;
    }
    void Display() const;
    void Scale(float scaleFactor);
    float Area() const;

};
class TriangularPyramid : virtual public Shape3D, virtual private Triangle {
private:
    float side1, side2, length;
    string Shape;
public:
    TriangularPyramid(float side1 = 0.0, float side2 = 0.0, float length = 0.0, string Shape = "TriangularPyramid");
    string GetName3D() const {
        return Shape;
    }
    void Display() const;
    void Scale(float scaleFactor);
    float Volume() const;

};
class Cylinder : virtual public Shape3D, virtual public Circle {
public:
    string Shape;
    float side1, length;
    Cylinder(float side1 = 0.0, float length = 0.0, string Shape = "Cylinder");
    string GetName3D() const {
        return Shape;
    }
    void Display() const;
    void Scale(float scaleFactor);
    float Volume() const;
};

class Sphere : virtual public Shape3D, virtual public Circle {
public:
    string Shape;
    float side1;
    Sphere(float side1 = 0.0, string Shape = "Sphere");
    string GetName3D() const {
        return Shape;
    }
    void Display() const;
    void Scale(float scaleFactor);
    float Volume() const;
};