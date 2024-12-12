#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <memory>
#include <stdexcept> // для std::invalid_argument

// Класс Time, представляющий время в формате часы-минуты-секунды
class Time {
private:
    static int counter; // Счетчик созданных объектов Time
    int hours, minutes, seconds; // Члены класса, представляющие время

public:
    // Конструктор по умолчанию, инициализирующий время как 00:00:00
    Time() : hours(0), minutes(0), seconds(0) {
        std::cout << "Default constructor called. Counter: " << ++counter << std::endl;
    }

    // Параметризированный конструктор, инициализирующий время заданными значениями
    Time(int h, int m, int s) {
        if (h < 0 || m < 0 || s < 0) {
            throw std::invalid_argument("Negative values are not allowed.");
        }
        hours = h;
        minutes = m;
        seconds = s;
        std::cout << "Parametric constructor called. Counter: " << ++counter << std::endl;
        Normalize(); // Нормализация времени
    }

    // Копирующий конструктор, создаваемый при копировании объекта Time
    Time(const Time& t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds) {
        std::cout << "Copy constructor called. Counter: " << ++counter << std::endl;
    }

    // Оператор присваивания, копирующий значения из другого объекта Time
    Time& operator=(const Time& other) {
        std::cout << "Assignment operator called. Counter: " << counter << std::endl;
        if (this != &other) {
            hours = other.hours;
            minutes = other.minutes;
            seconds = other.seconds;
            Normalize(); // Нормализация времени
        }
        return *this;
    }

    // Деструктор, вызываемый при удалении объекта Time
    ~Time() {
        std::cout << "Destructor called. Counter: " << --counter << std::endl;
    }

    // Геттеры для получения значений часов, минут и секунд
    int GetHours() const noexcept { return hours; }
    int GetMinutes() const noexcept { return minutes; }
    int GetSeconds() const noexcept { return seconds; }

    // Метод для вывода времени в формате HH:MM:SS
    void PrintTime() const noexcept {
        std::cout << "H:" << GetHours() << " M:" << GetMinutes() << " S:" << GetSeconds() << std::endl;
    }

    // Метод для нормализации времени (обеспечение корректного формата)
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
        while (seconds < 0) {
            seconds += 60;
            minutes--;
        }
        while (minutes < 0) {
            minutes += 60;
            hours--;
        }
        while (hours < 0) {
            hours += 24;
        }
    }

    // Метод для преобразования времени в секунды
    int ToSeconds() const noexcept {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // Оператор сложения, добавляющий заданное количество секунд к времени
    Time operator + (int s) const {
        Time result(*this);
        result.seconds += s;
        result.Normalize();
        return result;
    }

    // Оператор вычитания, вычитающий время из другого объекта Time
    Time operator-(const Time& other) const {
        Time result(*this);
        result.hours -= other.hours;
        result.minutes -= other.minutes;
        result.seconds -= other.seconds;
        result.Normalize();
        return result;
    }

    // Оператор сложения, добавляющий время из другого объекта Time
    Time& operator+=(const Time& other) {
        hours += other.hours;
        minutes += other.minutes;
        seconds += other.seconds;
        Normalize();
        return *this;
    }

    // Оператор вычитания, вычитающий время из другого объекта Time
    Time& operator-=(const Time& other) {
        hours -= other.hours;
        minutes -= other.minutes;
        seconds -= other.seconds;
        Normalize();
        return *this;
    }

    // Дружественные классы
    friend class SimpleWatch;
    friend class Watch;
};

// Определение статического члена
int Time::counter = 0;

// Класс SimpleWatch, дружественный к классу Time
class SimpleWatch {
public:
    // Метод для вывода времени из объекта Time
    void ShowTime(const Time& t) const {
        int h = t.GetHours();
        int m = t.GetMinutes();
        int s = t.GetSeconds();
        std::cout << "Current Time: " << h << ":" << m << ":" << s << std::endl;
    }

    // Метод для установки времени в объекте Time
    void SetTime(Time& t, int h, int m, int s) {
        t.hours = h;
        t.minutes = m;
        t.seconds = s;
        t.Normalize(); // Нормализация времени
    }
};

// Класс Watch, дружественный к классу Time
class Watch {
private:
    int format; // Формат вывода времени (12 или 24 часа)

public:
    // Конструктор, инициализирующий формат вывода времени
    Watch(int fmt = 24) : format(fmt) {}

    // Метод для установки формата вывода времени
    void SetFormat(int fmt) {
        assert(fmt == 12 || fmt == 24);
        format = fmt;
    }

    // Метод для вывода времени из объекта Time
    void ShowTime(const Time& t) const {
        int h = t.GetHours();
        int m = t.GetMinutes();
        if (format == 12) {
            std::string ampm = (h >= 12) ? " PM" : " AM";
            h = (h % 12 == 0) ? 12 : h % 12;
            std::cout << "Current Time: " << h << ":" << m << ampm << std::endl;
        } else {
            std::cout << "Current Time: " << h << ":" << m << std::endl;
        }
    }

    // Метод для установки времени в объекте Time
    void SetTime(Time& t, int h, int m, int s) {
        t.hours = h;
        t.minutes = m;
        t.seconds = s;
        t.Normalize(); // Нормализация времени
    }
};

int main() {
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

    try {
        Time t1(10, 20, 30);
        SimpleWatch sw;
        sw.ShowTime(t1);

        Watch w(12);
        w.ShowTime(t1);

        w.SetTime(t1, 15, 45, 0);
        w.ShowTime(t1);

        sw.SetTime(t1, 23, 59, 59);
        sw.ShowTime(t1);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
