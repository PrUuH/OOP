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
    Time() noexcept : hours(0), minutes(0), seconds(0) { // список инициализации конструктора
        std::cout << "Default constructor called. Counter: " << ++counter << std::endl;
    }

// Конструктор с параметрами должен генерировать исключения при недопустимых значениях времени.
// Методы, которые могут привести к недопустимым значениям (например, вычитание), могут быть дополнены проверками и выбросом исключений, если это необходимо.

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        std::cout << "Parametric constructor called. Counter: " << ++counter << std::endl;
        if (h < 0 || m < 0 || s < 0 || m >= 60 || s >= 60) {
            throw std::invalid_argument("Invalid time values");
        }
        Normalize();
    }

    // Конструктор копирования
    Time(const Time& t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds) {
        std::cout << "Copy constructor called. Counter: " << ++counter << std::endl;
    }

    // Time(const Time& t) {
    //     std::copy(&t.hours, &t.seconds + 1, &hours); // +1 для указания на следующий адрес, за t.seconds
    //     std::cout << "Copy constructor called." << std::endl;
    // }

    Time& operator=(const Time& other) {
        std::cout << "Assignment operator called. Counter: " << counter << std::endl;
        if (this == &other) {
            return *this; // Защита от самоприсваивания
        }
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        Normalize();
        return *this;
    }

    ~Time() noexcept {
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

        //Важно всегда вызывать delete для объектов, созданных с помощью new, и delete[] для массивов, созданных с помощью new[], чтобы избежать утечек памяти.
        //Для объектов, созданных на стеке или управляемых умными указателями, вызов delete не требуется, так как они будут автоматически освобождены.

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

        std::shared_ptr<Time> sp(new Time(10, 20, 30));
        std::unique_ptr<Time> up(new Time(10, 20, 30));

        sp->PrintTime();
        up->PrintTime();

        // Проверка конструктора копирования
        std::cout << "\n----- Testing Copy Constructor -----" << std::endl;
        Time t2(1, 2, 3);
        Time t3(t2); // Используем конструктор копирования
        t3.PrintTime();

        // Проверка оператора присваивания
        std::cout << "\n----- Testing Assignment Operator -----" << std::endl;
        Time t4(4, 5, 6);
        t4 = t3; // Используем оператор присваивания
        t4.PrintTime();

        // Намеренное создание исключения
        Time invalidTime(-1, 0, 0); // Это вызовет исключение
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
