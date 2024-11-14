#include <iostream>
#include <vector>

// Abstract class GenericCreature
class GenericCreature {
public:
    virtual void eat() = 0; // Чистая виртуальная функция
    virtual void walk() = 0; // Виртуальная функция для ходьбы
    virtual void swim() = 0; // Виртуальная функция для плавания
    virtual void fly() = 0; // вирутальная функция для полета
    virtual ~GenericCreature() {} // Виртуальный деструктор
};


//Ocean creature can swim
class OceanCreature : public GenericCreature {
public:
    void eat() override {
        std::cout << "Ocean creature eats plankton" << std::endl;
    }

    void walk() override {
        std::cout << "Ocean creature cannot walk" << std::endl;
    }

    void swim() override {
        std::cout << "Ocean swims" << std::endl;
    }

    void fly() {
        std::cout << "OceanCreature cannot fly" << std::endl;
    }
};

//Amphibious can swim and walk
class Amphibious : public GenericCreature {
public:
    void eat() override {
        std::cout << "Amphibious eats insects" << std::endl;
    }

    void swim() override {
        std::cout << "Amphibious swims" << std::endl;
    }

    void walk() override {
        std::cout << "Amphibious can walk" << std::endl;
    }

    void fly() {
        std::cout << "Amphibious cannot fly" << std::endl;
    }
};

//Terrestial can walk, but cannot swim
class Terrestrial : public GenericCreature {
public:
    void eat() {
        std::cout << "Terrestrial eats smaller terrestial" << std::endl;
    }

    void walk() {
        std::cout << "Terresrtial only walking" << std::endl;
    }

    void swim() {
        std::cout << "Terrestrial cannot swim" << std::endl;
    }

    void fly() {
        std::cout << "Terrestrial cannot fly" << std::endl;
    }
};

//bird can walk and fly
class Bird : public GenericCreature {
public:
    void eat() {
        std::cout << "Bird eats seeds and insects" << std::endl;
    }

    void walk() {
        std::cout << "Bird walk" << std::endl;
    }

    void fly() {
        std::cout << "Bird flies" << std::endl;
    }

    void swim() {
        std::cout << "Bird cannnot swim" << std::endl;
    }
};

//waterfowl can walk, swim and fly
class Waterfowl : public Bird {
public:
    void eat() override {
        std::cout << "Waterfowl eats fish, seeds and insects" << std::endl;
    }

    void walk() {
        std::cout << "waterfowl walks" << std::endl;
    }

    void swim() {
        std::cout << "Waterfowl swims" << std::endl;
    }

    void fly() {
        std::cout << "Waterfowl flies" << std::endl;
    }
};

int main() {
    //creating M of pointers to GenericCreature
    std::vector<GenericCreature*> creatures;

    //adding objects from different classes
    creatures.push_back(new OceanCreature());
    creatures.push_back(new Amphibious());
    creatures.push_back(new Terrestrial());
    creatures.push_back(new Bird());
    creatures.push_back(new Waterfowl());

for (auto creature : creatures) {
    creature->eat();
    creature->walk();
    creature->swim();
    creature->fly();
}

for (auto creature : creatures) {
    delete creature;
}

return 0;
}