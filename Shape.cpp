//
// Created by Ellie Kunze on 11/7/22.
//
#include <string>
#include <iostream>

using namespace std;
#include "Shape.h"

Square::Square(float side1, string Shape) {
    this->side1 = side1;
    this->Shape = Shape;
}
float Square::Area() const {
    float width;
    width = side1 * side1;
    return width;
}
void Square::Scale(float scaleFactor) {
    float num;
    num = side1;
    side1 = scaleFactor * num;
}
void Square::Display() const {
    cout << "The area of the " <<GetName2D() << " is : " << Square::Area() << endl;
    cout << "Length of a side: " << side1 << endl;
}
Triangle::Triangle(float side1, float side2, string Shape) {
    this->side1 = side1;
    this->side2 = side2;
    this->Shape = Shape;
}
float Triangle::Area() const {
    float width;
    width = side1 * side2 * 0.5f;
    return width;
}
void Triangle::Scale(float scaleFactor) {
    side1 = scaleFactor * side1;
    side2 = scaleFactor * side2;
}
void Triangle::Display() const {
    cout << "The area of the " << GetName2D() << " is : " << Triangle::Area() << endl;
    cout << "Base: " << side1 << endl;
    cout << "Height: " << side2 <<endl;
}
Circle::Circle(float side1, string Shape) {
    this->side1 = side1;
    this->Shape = Shape;
}
float Circle::Area() const {
    float width;
    float circle_ = side1;
    width = circle_ * circle_ * PI;
    return width;
}
void Circle::Scale(float scaleFactor) {
    side1 = scaleFactor * side1;
}
void Circle::Display() const {
    cout << "The area of the " <<GetName2D() << " is : " << Circle::Area() << endl;
    cout << "Radius: " << side1 << endl;
}
TriangularPyramid::TriangularPyramid(float side1, float side2, float length, std::string Shape) {
    this->side1 = side1;
    this->side2 = side2;
    this->Shape = Shape;
    this->length = length;
}
float TriangularPyramid::Volume() const {
    float num;
    float num2 = (float)1 / 3;
    num = (side1 * length * side2 * num2) / 2;
    //num = num2 * this->Area() * length;
    return num;
}
void TriangularPyramid::Scale(float scaleFactor) {
    side1 = side1 * scaleFactor;
}
void TriangularPyramid::Display() const {
    //
    cout << "The volume of the " << GetName3D() << " is : " <<TriangularPyramid::Volume() << endl;
    cout << "The height is: " << side1 << endl;
    cout << "The area of the " << GetName2D() << " is : " << 0.5f * side2 * length << endl;
    cout <<"Base: " << side2 << endl;
    cout << "Height: " << length << endl;
}
Cylinder::Cylinder(float side1, float length, std::string Shape) {
    this->side1 = side1;
    this->Shape = Shape;
    this->length = length;
}
float Cylinder::Volume() const {
    float num;
    num = side1 * length * length * PI;
    return num;
}
void Cylinder::Scale(float scaleFactor) {
    side1 = side1 * scaleFactor;
    length = length * scaleFactor;
}
void Cylinder::Display() const {
    cout << "The volume of the " << GetName3D() << " is : " <<Cylinder::Volume() << endl;
    cout << "The height is: " << side1 << endl;
    cout << "The area of the " << GetName2D() << " is : " << PI * length * length << endl;
    cout <<"Radius: " << length << endl;
}
Sphere::Sphere(float side1, std::string Shape) {
    this->side1 = side1;
    this->Shape = Shape;
}
float Sphere::Volume() const {
    float num;
    float circle_ = side1;
    float num2 = 4.0 / 3.0;
    num = (circle_*circle_*circle_) * PI * num2;
    return num;
}
void Sphere::Scale(float scaleFactor) {
    float newSide = side1 * scaleFactor;
    side1 = newSide;
}
void Sphere::Display() const {
    cout << "The volume of the " << GetName3D() << " is : " <<Sphere::Volume() << endl;
    cout << "The area of the " << GetName2D() << " is : " << (PI * side1 * side1) << endl;
    cout <<"Radius: " << side1 << endl;
}
void Shape2D::ShowArea() const
{
    cout << "The area of the " <<GetName2D() << " is : ";
    cout << Area() << endl;
}
bool Shape2D::operator>(const Shape2D &rhs) const {
    bool number_ = false;
    float area_ = rhs.Area();
    if(this->Area() > area_) {
        number_ = true;
    }
    return number_;
}
bool Shape2D::operator<(const Shape2D &rhs) const {
    bool number_ = false;
    float area_ = rhs.Area();
    if(this->Area() < area_) {
        number_ = true;
    }
    return number_;
}
bool Shape2D::operator==(const Shape2D &rhs) const {
    bool number_ = false;
    float area_ = rhs.Area();
    if(this->Area() == area_) {
        number_ = true;
    }
    return number_;
}
void Shape3D::ShowVolume() const {
    //
    cout << "The volume of the " <<GetName3D() << " is : " << endl;
    cout << Volume() << endl;
}
bool Shape3D::operator>(const Shape3D &rhs) const {
    bool number_ = false;
    float volume_ = rhs.Volume();
    if(this->Volume() > volume_) {
        number_ = true;
    }
    return number_;
}
bool Shape3D::operator<(const Shape3D &rhs) const {
    bool number_ = false;
    float volume_ = rhs.Volume();
    if(this->Volume() < volume_) {
        number_ = true;
    }
    return number_;
}
bool Shape3D::operator==(const Shape3D &rhs) const {
    bool number_ = false;
    float volume_ = rhs.Volume();
    if (this->Volume() == volume_) {
        number_ = true;
    }
    return number_;
}
Shape::~Shape() noexcept {

}