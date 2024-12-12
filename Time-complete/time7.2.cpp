#include <iostream>
#include <string>
#include <stdexcept> // для std::invalid_argument

// Класс Time для управления временем
class Time {
public:
    int hours, minutes, seconds;

    // Конструктор класса Time, инициализирующий часы, минуты и секунды
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        Normalize(); // Нормализация времени при создании объекта
    }

    // Метод для нормализации времени
    void Normalize() {
        while (seconds >= 60) {
            minutes++;
            seconds -= 60;
        }
        while (minutes >= 60) {
            hours++;
            minutes -= 60;
        }
        while (hours >= 24) {
            hours -= 24;
        }
    }

    // Метод для вывода времени на экран
    void PrintTime() const {
        std::cout << "Current Time: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

// Общий родительский класс для всех часов
class Clock {
public:
    // Конструктор базового класса Clock
    Clock() {
        std::cout << "Clock constructor called." << std::endl;
    }

    // Виртуальный деструктор базового класса Clock
    virtual ~Clock() {
        std::cout << "Clock destructor called." << std::endl;
    }

    // Чисто виртуальная функция для вывода времени, которую должны реализовать все производные классы
    virtual void ShowTime() const = 0;
};

// Класс для кукушкиных часов
class CuckooClock : public Clock {
public:
    Time time; // Используем Time как поле класса

    // Конструктор класса CuckooClock
    CuckooClock(int h, int m, int s) : Clock(), time(h, m, s) {
        std::cout << "CuckooClock constructor called." << std::endl;
    }

    // Деструктор класса CuckooClock
    ~CuckooClock() {
        std::cout << "CuckooClock destructor called." << std::endl;
    }

    // Реализация метода ShowTime для кукушкиных часов
    void ShowTime() const override {
        time.PrintTime();
        std::cout << "Cuckoo! Cuckoo!" << std::endl; // Звук кукушки
    }
};

// Класс для настенных часов
class WallClock : public Clock {
public:
    Time time; // Используем Time как поле класса

    // Конструктор класса WallClock
    WallClock(int h, int m, int s) : Clock(), time(h, m, s) {
        std::cout << "WallClock constructor called." << std::endl;
    }

    // Деструктор класса WallClock
    ~WallClock() {
        std::cout << "WallClock destructor called." << std::endl;
    }

    // Реализация метода ShowTime для настенных часов
    void ShowTime() const override {
        time.PrintTime();
    }
};

// Класс для наручных часов
class Watch : public Clock {
public:
    Time time; // Используем Time как поле класса

    // Конструктор класса Watch
    Watch(int h, int m, int s) : Clock(), time(h, m, s) {
        std::cout << "Watch constructor called." << std::endl;
    }

    // Деструктор класса Watch
    ~Watch() {
        std::cout << "Watch destructor called." << std::endl;
    }

    // Реализация метода ShowTime для наручных часов
    void ShowTime() const override {
        time.PrintTime();
    }
};

// Класс для смарт-часов
class SmartWatch : public Watch {
public:
    // Конструктор класса SmartWatch
    SmartWatch(int h, int m, int s) : Watch(h, m, s) {
        std::cout << "SmartWatch constructor called." << std::endl;
    }

    // Деструктор класса SmartWatch
    ~SmartWatch() {
        std::cout << "SmartWatch destructor called." << std::endl;
    }

    // Реализация метода ShowTime для смарт-часов
    void ShowTime() const override {
        Watch::ShowTime();
        std::cout << "Smart features activated!" << std::endl; // Дополнительные функции
    }
};

int main() {
    // Создание объекта кукушкиных часов и вызов метода ShowTime
    Clock* cuckoo = new CuckooClock(10, 20, 30);
    cuckoo->ShowTime();
    delete cuckoo;

    // Создание объекта настенных часов и вызов метода ShowTime
    Clock* wall = new WallClock(12, 0, 0);
    wall->ShowTime();
    delete wall;

    // Создание объекта наручных часов и вызов метода ShowTime
    Clock* wrist = new Watch(14, 30, 45);
    wrist->ShowTime();
    delete wrist;

    // Создание объекта смарт-часов и вызов метода ShowTime
    Clock* smart = new SmartWatch(16, 15, 0);
    smart->ShowTime();
    delete smart;

    return 0;
}
