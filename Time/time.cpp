#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <memory>

class Time
{
private:
    static int counter; 
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {
        std::cout << "Default constructor called. Counter: " << ++counter << std::endl;
    }
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        std::cout << "Parametric constructor called. Counter: " << ++counter << std::endl;
        Normalize();
    }
    Time(const Time& t)  : Time(t.hours, t.minutes, t.seconds) {}
    
    Time& operator=(const Time& other) {
        std::cout << "Assignment operator called. Counter: " << counter << std::endl;
        hours = other.hours;
        minutes = other.minutes + 10;
        seconds = other.seconds + 30;
        Normalize();
        return *this;
    }
    ~Time() {
        std::cout << "Destructor called. Counter: " << --counter << std::endl;
    }

    int GetHours() const { return hours; }
    int GetMinutes() const { return minutes; }
    int GetSeconds() const { return seconds; }

    void PrintTime() const {
        std::cout << "H:" << GetHours() << " M:" << GetMinutes() << " S:" << GetSeconds() << std::endl;
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
        while (hours < 0) {
            hours += 24;
            minutes += 60;
            seconds += 60;
        }
    }

    int ToSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time operator + (int s) const {
        Time result(*this);
         result = Time(hours, minutes, seconds + s);
         result.Normalize();
         return result;
 }

    Time operator-(const Time& other) const {
        Time result(*this);
        result.hours -= other.hours;
        result.minutes -= other.minutes;
        result.seconds -= other.seconds;
        result.Normalize();
        return result;
    }

    Time& operator+=(const Time& other) {
    hours += other.hours;
    minutes += other.minutes;
    seconds += other.seconds;
    Normalize();
    return *this;
}

    Time& operator-=(const Time& other) {
    hours -= other.hours;
    minutes -= other.minutes;
    seconds -= other.seconds;
    Normalize();
    return *this;
}

    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }
};

int Time::counter = 0;

int main()
{
    // 6.1a - Динамическое создание объектов
    std::cout << "----- 6.1a -----" << std::endl;

    Time* t1 = new Time(10, 20, 30);  // Один объект в динамической памяти
    Time* tArray = new Time[3];   // Массив из 3 объектов в динамической памяти

    // Обращение к членам объектов
    t1->PrintTime();
    for (int i = 0; i < 3; ++i) {
        tArray[i].PrintTime(); 
    }

    // Освобождение памяти
    delete t1;        // Удаляем один объект
    delete[] tArray; // Удаляем массив объектов 

    // 6.1b - Стандартные контейнеры
    std::cout << "\n----- 6.1 b -----" << std::endl;

    std::vector<Time> v(3); // Вектор из 3 объектов
    std::list<Time> l(3);   // Список из 3 объектов

    // Обращение к членам объектов
    for (int i = 0; i < 3; ++i) {
        v[i].PrintTime();
        l.front().PrintTime();
        l.pop_front();
    }

    // 6.1c - Умные указатели
    std::cout << "\n----- 6.1c -----" << std::endl;

    std::shared_ptr<Time> sp(new Time(10, 20, 30)); // shared_ptr
    std::unique_ptr<Time> up(new Time(10, 20, 30)); // unique_ptr

    sp->PrintTime();
    up->PrintTime();

    return 0;
}