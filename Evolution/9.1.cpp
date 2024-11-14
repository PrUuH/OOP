#include <iostream>

// Общий родительский класс
class Creature {
public:
    void move() {
        std::cout << "Creature moves." << std::endl;
    }
};

// Класс для морских существ
class OceanCreature : public Creature {
public:
    void swim() {
        std::cout << "Ocean creature swims." << std::endl;
    }
};

// Класс для амфибий
class Amphibious : public OceanCreature {
public:
    void walk() {
        std::cout << "Amphibious creature walks." << std::endl;
    }
};

// Класс для наземных существ
class TerrestrialCreature : public Creature {
public:
    void walk() {
        std::cout << "Terrestrial creature walks." << std::endl;
    }
};

// Класс для птиц
class Bird : public TerrestrialCreature {
public:
    void fly() {
        std::cout << "Bird flies." << std::endl;
    }
};

// Класс для водоплавающих птиц
class Waterfowl : public Bird {
public:
    void swim() {
        std::cout << "Waterfowl swims." << std::endl;
    }
};

int main() {
    Creature c;
    OceanCreature oc;
    Amphibious a;
    TerrestrialCreature tc;
    Bird b;
    Waterfowl wf;

    c.move();        // Creature moves.
    oc.move();      // Creature moves.
    oc.swim();      // Ocean creature swims.

    a.move();       // Creature moves.
    a.swim();       // Ocean creature swims.
    a.walk();       // Amphibious creature walks.

    tc.move();      // Creature moves.
    tc.walk();      // Terrestrial creature walks.

    b.move();       // Creature moves.
    b.walk();       // Terrestrial creature walks.
    b.fly();        // Bird flies.

    wf.move();      // Creature moves.
    wf.walk();      // Terrestrial creature walks.
    wf.fly();       // Bird flies.
    wf.swim();      // Waterfowl swims.

    return 0;
}