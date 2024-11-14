#include <iostream>
#include <string>
#include <stdexcept> // для std::invalid_argument

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        Normalize();
    }

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

    void PrintTime() const {
        std::cout << "Current Time: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

class Clock {
public:
    Clock() {
        std::cout << "Clock constructor called." << std::endl;
    }
    
    virtual ~Clock() {
        std::cout << "Clock destructor called." << std::endl;
    }
    
    virtual void ShowTime() const = 0; // чисто виртуальная функция
};

class CuckooClock : public Clock {
private:
    Time time;

public:
    CuckooClock(int h, int m, int s) : Clock(), time(h, m, s) {
        std::cout << "CuckooClock constructor called." << std::endl;
    }

    ~CuckooClock() {
        std::cout << "CuckooClock destructor called." << std::endl;
    }

    void ShowTime() const override {
        time.PrintTime();
        std::cout << "Cuckoo! Cuckoo!" << std::endl; // Звук кукушки
    }
};

class WallClock : public Clock {
private:
    Time time;

public:
    WallClock(int h, int m, int s) : Clock(), time(h, m, s) {
        std::cout << "WallClock constructor called." << std::endl;
    }

    ~WallClock() {
        std::cout << "WallClock destructor called." << std::endl;
    }

    void ShowTime() const override {
        time.PrintTime();
    }
};

class Watch : public Clock {
private:
    Time time;

public:
    Watch(int h, int m, int s) : Clock(), time(h, m, s) {
        std::cout << "Watch constructor called." << std::endl;
    }

    ~Watch() {
        std::cout << "Watch destructor called." << std::endl;
    }

    void ShowTime() const override {
        time.PrintTime();
    }
};

class SmartWatch : public Watch {
public:
    SmartWatch(int h, int m, int s) : Watch(h, m, s) {
        std::cout << "SmartWatch constructor called." << std::endl;
    }

    ~SmartWatch() {
        std::cout << "SmartWatch destructor called." << std::endl;
    }

    void ShowTime() const override {
        Watch::ShowTime();
        std::cout << "Smart features activated!" << std::endl; // Дополнительные функции
    }
};

int main() {
    Clock* cuckoo = new CuckooClock(10, 20, 30);
    cuckoo->ShowTime();
    delete cuckoo;

    Clock* wall = new WallClock(12, 0, 0);
    wall->ShowTime();
    delete wall;

    Clock* wrist = new Watch(14, 30, 45);
    wrist->ShowTime();
    delete wrist;

    Clock* smart = new SmartWatch(16, 15, 0);
    smart->ShowTime();
    delete smart;

    return 0;
}