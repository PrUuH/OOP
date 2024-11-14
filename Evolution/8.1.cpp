#include <iostream>

// Общий родительский класс для всех существ
class GenericCreature {
public:
    void breathe() {
        std::cout << "I breathe." << std::endl;
    }
};

// Наследник, умеющий плавать
class OceanCreature : public GenericCreature {
public:
    void swim() {
        std::cout << "I swim." << std::endl;
    }
};

// Наследник, умеющий плавать и ходить
class Amphibious : public OceanCreature {
public:
    void walk() {
        std::cout << "I walk." << std::endl;
    }
};

// Наследник, который не умеет плавать, но умеет ходить
class TerrestrialCreature : public GenericCreature {
public:
    void walk() {
        std::cout << "I walk." << std::endl;
    }
};

// Наследник, умеющий ходить и летать
class Bird : public TerrestrialCreature {
public:
    void fly() {
        std::cout << "I fly." << std::endl;
    }
};

// Водоплавающая птица, умеющая ходить, летать и плавать
class Waterfowl : public Bird, public OceanCreature {
public:
    using OceanCreature::breathe;

    void swim() {
        std::cout << "I swim like waterfowl." << std::endl;
    }
};

int main() {
    Waterfowl duck;
    duck.OceanCreature::breathe();  // Call breathe from OceanCreature
    duck.Bird::walk();               // Call walk from Bird
    duck.Bird::fly();                // Call fly from Bird
    duck.OceanCreature::swim();      // Call swim from OceanCreature
    duck.Waterfowl::swim();
    
    return 0;
}

