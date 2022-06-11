// homework3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

// task 1
class Figure {
public:
    Figure() = default;
    virtual float area() = 0;
};

class Parallelogram : public Figure {
public:
    Parallelogram(float _a = 1.0f, float _b = 1.0f, float _alpha = 90.0f) : a(_a), b(_b), alpha(_alpha) {}
    float area() override { return a * b * sin(alpha); }
private:
    float a;
    float b;
    float alpha;
};

class Circle : public Figure {
public:
    Circle(float _R = 1.0f) : R(_R) {}
    float area() override { return 3.14f * R * R; }
private:
    float R;
};

class Rectangle : public Parallelogram {
public:
    Rectangle(float _a = 1.0f, float _b = 1.0f) : a(_a), b(_b) {}
    float area() override { return a * b; }
private:
    float a;
    float b;
};

class Square : public Parallelogram {
public:
    Square(float _a = 1.0f) : a(_a) {}
    float area() override { return a * a; }
private:
    float a;
};

class Rhombus : public Parallelogram {
public:
    Rhombus(float _a = 1.0f, float _alpha = 45.0f) : a(_a), alpha(_alpha) {}
    float area() override { return a * a * sin(alpha); }
private:
    float a;
    float alpha;
};

// task 2
class Car {
public:
    Car() { std::cout << "Car :: print() " << std::endl; }
private:
    std::string company;
    std::string model;
};

class PassengerCar : virtual public Car {
public:
    PassengerCar() { std::cout << "PassengerCar :: print()" << std::endl; }
private:
};

class Bus : virtual public Car {
public:
     Bus() { std::cout << "Bus :: print()" << std::endl; }
private:
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan() { std::cout << "Minivan :: print()" << std::endl; }
private:
};

// task 3
class Fraction {
public:
    Fraction(int _numerator = 1, int _denominator = 1) : numerator(_numerator), denominator(_denominator) {
        if (denominator == 0) {
            std::cout << "Error: Denominator can't be 0" << std::endl;
            denominator = 1;
        }
        std::cout << numerator << "/" << denominator << std::endl;
    }

    void operator-() { numerator = -numerator; }

    Fraction operator+(Fraction& r_numb) {
        if (r_numb.denominator == denominator)
        {
            int num1 = r_numb.numerator + numerator;
            return Fraction(num1, denominator);
        }
        else
        {
            int num1 = r_numb.numerator * denominator + numerator * r_numb.denominator;
            int den1 = r_numb.denominator * denominator;
            return Fraction(num1, den1);
        }
    }

    Fraction operator+(int r_numb) {
        int num1 = r_numb * denominator + numerator;
        return Fraction(num1, denominator);
    }

    Fraction operator-(Fraction& r_numb) {
        if (r_numb.denominator == denominator)
        {
            int num1 = numerator - r_numb.numerator;
            return Fraction(num1, denominator);
        }
        else
        {
            int num1 = numerator * r_numb.denominator - r_numb.numerator * denominator;
            int den1 = r_numb.denominator * denominator;
            return Fraction(num1, den1);
        }
    }

    Fraction operator-(int r_numb) {
        int num1 = numerator - r_numb * denominator;
        return Fraction(num1, denominator);
    }

    Fraction operator*(Fraction& r_numb) {
            int num1 = numerator * r_numb.numerator;
            int den1 = r_numb.denominator * denominator;
            return Fraction(num1, den1);
    }

    Fraction operator*(int r_numb) {
        int num1 = numerator * r_numb;
        return Fraction(num1, denominator);
    }

    Fraction operator/(Fraction& r_numb) {
        int num1 = numerator * r_numb.denominator;
        int den1 = r_numb.numerator * denominator;
        return Fraction(num1, den1);
    }

    Fraction operator/(int r_numb) {
        int den1 = numerator * r_numb;
        return Fraction(numerator, den1);
    }


private:
    int numerator;
    int denominator;
};

// task 4

enum cardVal { ace = 1, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, jack = 11, queen = 12, king = 13 };
enum cardSuit { spades, hearts, diamonds, clubs };

class Card {
public:
    Card(cardVal _val = ace, cardSuit _suit = hearts, bool _side = false) : val(_val), suit(_suit), side(_side) {}
    void flip() { side = !side; std::cout << side << std::endl; }
    cardVal GetValue() { return val; }
private:
    cardVal val;
    cardSuit suit;
    bool side;

};

int main()
{
    Minivan car1;

    Fraction num1(2,3);
    Fraction num2(1, 0);

    Card card1;
    card1.flip();
    card1.flip();
    std::cout << card1.GetValue() << std::endl;

}

