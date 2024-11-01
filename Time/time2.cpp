#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <memory>
#include <stdexcept> // для std::invalid_argument

class Time
{
private:
    static int counter; // static counter for created objects
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {
        std::cout << "Default constructor called. Counter: " << ++counter << std::endl;
    }

    Time(int h, int m, int s) {
        if (h < 0 || m < 0 || s < 0) {
            throw std::invalid_argument("Negative values are not allowed.");
        }
        hours = h;
        minutes = m;
        seconds = s;
        std::cout << "Parametric constructor called. Counter: " << ++counter << std::endl;
        Normalize();
    }

    Time(const Time& t) : Time(t.hours, t.minutes, t.seconds) {}

    Time& operator=(const Time& other) {
        std::cout << "Assignment operator called. Counter: " << counter << std::endl;
        hours = other.hours;
        minutes = other.minutes + 10; // Изменение для демонстрации
        seconds = other.seconds + 30;  // Изменение для демонстрации
        Normalize();
        return *this;
    }

    ~Time() {
        std::cout << "Destructor called. Counter: " << --counter << std::endl;
    }

    int GetHours() const noexcept { return hours; }
    int GetMinutes() const noexcept { return minutes; }
    int GetSeconds() const noexcept { return seconds; }

    void PrintTime() const noexcept {
        std::cout << "H:" << GetHours() << " M:" << GetMinutes() << " S:" << GetSeconds() << std::endl;
    }

    void Normalize() noexcept {
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

    int ToSeconds() const noexcept {
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

    bool operator==(const Time& other) const noexcept {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }

    bool operator!=(const Time& other) const noexcept {
        return !(*this == other);
    }
};

int Time::counter = 0;

int main()
{
    try {
        std::cout << "----- Creating Time objects -----" << std::endl;

        Time t1(10, 20, 30); // Правильное создание
        t1.PrintTime();

        Time t2(-1, 20, 30); // Неправильное создание, должно вызвать исключение
        t2.PrintTime(); // Этот код не будет выполнен
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}