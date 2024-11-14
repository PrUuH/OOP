#include <iostream>

// Общий родительский класс
class Creature {
public:
    void breathe() {
        std::cout << "Creature is breathing." << std::endl;
    }
};

// Класс для морских существ
class OceanCreature : virtual public Creature {
public:
    void swim() {
        std::cout << "Ocean creature is swimming." << std::endl;
    }
};

// Класс для амфибий
class Amphibious : public OceanCreature {
public:
    void walk() {
        std::cout << "Amphibious creature is walking." << std::endl;
    }
};

// Класс для наземных существ
class TerrestrialCreature : virtual public Creature {
public:
    void walk() {
        std::cout << "Terrestrial creature is walking." << std::endl;
    }
};

// Класс для птиц
class Bird : virtual public Creature {
public:
    void fly() {
        std::cout << "Bird is flying." << std::endl;
    }

    void walk() {
        std::cout << "Bird is walking." << std::endl;
    }
};

// Класс для водоплавающих птиц
class Waterfowl : public Bird, public OceanCreature {
public:
    void quack() {
        std::cout << "Waterfowl is quacking." << std::endl;
    }
};

int main() {
    Amphibious frog;
    frog.breathe();
    frog.swim();
    frog.walk();

    Waterfowl duck;
    duck.breathe();
    duck.fly();
    duck.walk();
    duck.swim();
    duck.quack();

    return 0;
}