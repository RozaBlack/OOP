// homework3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

// task 1
class Figure {
public:
    virtual float area() = 0;
};

class Parallelogram : public Figure {
public:
    Parallelogram(float _a = 1.0f, float _b = 1.0f, float _alpha = 90.0f) : a(_a), b(_b), alpha(_alpha) {}
    float area() { return a * b * sin(alpha); }
private:
    float a;
    float b;
    float alpha;
};

class Circle : public Figure {
public:
    Circle(float _R = 1.0f) : R(_R) {}
    float area() { return 3.14f * R * R; }
private:
    float R;
};

class Rectangle : public Parallelogram {
public:
    Rectangle(float _a = 1.0f, float _b = 1.0f) : a(_a), b(_b) {}
    float area() { return a * b; }
private:
    float a;
    float b;
};

class Square : public Parallelogram {
public:
    Square(float _a = 1.0f) : a(_a) {}
    float area() { return a * a; }
private:
    float a;
};

class Rhombus : public Parallelogram {
public:
    Rhombus(float _a = 1.0f, float _alpha = 45.0f) : a(_a), alpha(_alpha) {}
    float area() { return a * a * sin(alpha); }
private:
    float a;
    float alpha;
};

// task 2



int main()
{
    std::cout << "Hello World!\n";
}

