// homework2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

// task 1
class Person {
public:
    Person()
            : name(" "), age(0), gen(' '), weight(0.0f) {}
    void rename(std::string _name) { this->name = _name; }
    void changeAge(int _age) { this->age = _age; }
    void changeGen(char _gen) { this->gen = _gen; }
    void changeWeight(float _weight) { this->weight = _weight; }
    void showPersonInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Gen: " << gen << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }
private:
    std::string name;
    int age;
    char gen;
    float weight;
};

class Student : public Person {
    
public:
    Student() : educationYear(0) { ++studentNumb; }
    void changeYear(int _educationYear) { this->educationYear = _educationYear; }
    void plusYear() { this->educationYear++; }
    void showStudentInfo(){
        showPersonInfo();
        std::cout << "Course number: " << educationYear << std::endl << std::endl;
    }
    void StNumbPrint() { std::cout << "Number of students: " << studentNumb << std::endl; }
private:
    int educationYear;
    static int studentNumb;
};

int Student::studentNumb = 0;

// task 2
class Fruit {
public:
    Fruit(std::string _name = " ", std::string _color = " ") : name(_name), color(_color) {}
    void initFruit(std::string _name, std::string _color) {
        name = _name;
        color = _color;
    }
    std::string getName() { return name; }
    std::string getColor() { return color; }
private:
    std::string name;
    std::string color;
};

class Apple : public Fruit {
public:
    Apple(std::string color = "green", std::string name = "") : Fruit(name + "apple", color) {}
};

class Banana : public Fruit {
public:
    Banana(std::string color = "yellow") : Fruit("banana", color) {}
};

class GrannySmith : public Apple {
public:
    GrannySmith(std::string name = "Granny Smith ", std::string color = "green") : Apple(color, name) {}

};

int main()
{
    // task 1
    Student Anna;
    Anna.rename("Anna");
    Anna.changeGen('f');
    Anna.changeAge(20);
    Anna.changeWeight(60.5f);
    Anna.changeYear(1);
    Anna.showStudentInfo();

    Student Pavel;
    Pavel.rename("Pavel");
    Pavel.changeGen('m');
    Pavel.changeAge(23);
    Pavel.changeWeight(69.4f);
    Pavel.changeYear(3);
    Pavel.showStudentInfo();

    Student Ulia;
    Ulia.rename("Ulia");
    Ulia.changeGen('f');
    Ulia.changeAge(19);
    Ulia.changeWeight(54.4f);
    Ulia.plusYear();
    Ulia.showStudentInfo();
    Ulia.StNumbPrint();

    // task 2
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

// Task 3
/* 
    Классы для игры в блекджек:
        1) Класс Player с полями: имя игрока, ставка игрока, рука игрока, текущая сумма. 
            Так же в классе должна содержаться информация о количестве игроков. Возможно, еще 
            информация о том, является ли игрок в данный момент активным. Так же, должны быть методы, 
            отвечающие за возможные действия игрока: добор карты в руку (добавление элемента структуры в стек)
            и определение суммы карт, проверка, что сумма не превышает 21,
            окончание хода (игрок перестает быть активным), удвоение ставки, страхование, сдача (игрок перестает быть
            активным, его ставка изменяется и, можно, например, изменить сумму так, что бы он точно проиграл. 
        2) Класс крупье имеет поля: рука крупье, текущая сумма и метод добрать карту.
        3) Класс Колода с информацией о количестве используемых колод в данной игре и количестве карт
            (можно добавить информацию о количестве карт на текущий момент игры). Класс должен содержать
            массив структур со всеми картами, находящимися на текущий момент в колоде 
            (может быть так же еще один массив, содержащий вышедшие из игры карты)
            У класса так же должны быть два метода: заполняющий колоду и удаляющий из нее карты. Добавлять
            и удалять карты можно используя стек. Метод, заполняющий колоду должен получать на вход информацию
            о количестве используемых колод карт и массив структур с информацией обо всех картах в одной колоде.
            В итоговую колоду карты должны добавляться в произвольном порядке. Метод должен работать только когда
            в колоде нет карт (то есть, он не должен генерировать новую колоду, пока существует текущая)
            Метод, удаляющий карты должен удалять последний элемент стека и сообщать информацию об удаляемой карте.
        4) Структура, содержащая информацию о номинале карты, масти и количестве очков, которое она приносит. 
        5) Функция, сравнивающая суммы игроков с суммой крупье и определяющая победителя.
        Классы (1) и (2) наследуют классу (3)

*/
