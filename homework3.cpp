// homework3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#define PI 3.14159265

// task 1
class Figure {
public:
    Figure() = default;
    virtual float area() = 0;
};

class Parallelogram : public Figure {
public:
    Parallelogram(float _a = 1.0f, float _b = 1.0f, float _alpha = 90.0f) : a(_a), b(_b), alpha(_alpha) {}
    float area() { return a * b * sin(alpha * c1); }
    const float c1 = PI / 180;
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
    float area() { return a * a * sin(alpha * c1); }
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
        else if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    void print() { std::cout << numerator << "/" << denominator << std::endl; }

    Fraction operator-() { return Fraction(-numerator, denominator); }

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

    friend Fraction operator+(int l_numb, Fraction& r_numb) {
        int num1 = l_numb * r_numb.denominator + r_numb.numerator;
        return Fraction(num1, r_numb.denominator);
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

    friend Fraction operator-(int l_numb, Fraction& r_numb) {
        int num1 = l_numb * r_numb.denominator - r_numb.numerator;
        return Fraction(num1, r_numb.denominator);
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

    friend Fraction operator*(int l_numb, Fraction& r_numb) {
        int num1 = r_numb.numerator * l_numb;
        return Fraction(num1, r_numb.denominator);
    }

    Fraction operator/(Fraction& r_numb) {
        int num1 = numerator * r_numb.denominator;
        int den1 = r_numb.numerator * denominator;
        return Fraction(num1, den1);
    }

    Fraction operator/(int r_numb) {
        int den1 = denominator * r_numb;
        return Fraction(numerator, den1);
    }

    friend Fraction operator/(int l_numb, Fraction& r_numb) {
        int den1 = r_numb.denominator * l_numb;
        return Fraction(den1, r_numb.numerator);
    }

    bool operator>(Fraction& r_numb) {
        bool res = (numerator / float(denominator) > r_numb.numerator / float(r_numb.denominator)) ? true : false;
        return res;
    }

    bool operator<(Fraction& r_numb) {
        bool res = (numerator / float(denominator) < r_numb.numerator / float(r_numb.denominator)) ? true : false;
        return res;
    }

    bool operator==(Fraction& r_numb) {
        bool res = (numerator / float(denominator) == r_numb.numerator / float(r_numb.denominator)) ? true : false;
        return res;
    }

    bool operator<=(Fraction& r_numb) {
        return !operator>(r_numb);
    }

    bool operator>=(Fraction& r_numb) {
        return !operator<(r_numb);
    }

    bool operator!=(Fraction& r_numb) {
        return !operator==(r_numb);
    }

    friend std::ostream& operator<<(std::ostream& c_out, Fraction& r_numb) {
        c_out << r_numb.numerator << "/";
        c_out << r_numb.denominator << std::endl;
        return c_out;
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
    // task 1
    float a = 2.0f;
    float b = 5.5f;
    float alp = 30.0f;
    Parallelogram F1(a,b,alp);
    std::cout << "Spar = " << F1.area() << std::endl;
    Circle F2(a);
    std::cout << "Scir = " << F2.area() << std::endl;
    Rectangle F3(a,b);
    std::cout << "Srec = " << F3.area() << std::endl;
    Square F4(a);
    std::cout << "Ssq = " << F4.area() << std::endl;
    Rhombus F5(a,alp);
    std::cout << "Srho = " << F5.area() << std::endl;


    // task 2 
    Minivan car1;

    // task 3
    Fraction num1(2, 3);
    Fraction num2(1, 0);

    Fraction N1(2, 3);
    Fraction N2(4, -7);
    Fraction N3;
    N1.print();
    N2.print();
    N3.print();

    N3 = -N1;
    N3.print();
    N3 = -N2;
    N3.print();

    N3 = N1 + N2;
    N3.print();
    N3 = N1 - N2;
    N3.print();
    N3 = N2 - N1;
    N3.print();
    N3 = N1 * N2;
    N3.print();
    N3 = N1 / N2;
    N3.print();
    N3 = N2 / N1;
    N3.print();

    N3 = 10 + N2;
    N3.print();
    N3 = N1 - 10;
    N3.print();
    N3 = 10 - N2;
    N3.print();
    N3 = N1 * 10;
    N3.print();
    N3 = 10 * N2;
    N3.print();
    N3 = 10 / N2;
    N3.print();
    N3 = N1 / 10;
    N3.print();
    N3 = N1 / 0;
    N3.print();

    std::cout << (N1 < N2) << std::endl;
    std::cout << (N1 > N2) << std::endl;
    std::cout << (N1 == N2) << std::endl;
    std::cout << (N1 <= N2) << std::endl;
    std::cout << (N1 >= N2) << std::endl;

    // task 4
    Card card1;
    card1.flip();
    card1.flip();
    std::cout << card1.GetValue() << std::endl;
}
