/*generic creature - общий родитель
ocean creature - наследник умеющий плавать
amphibious - наследник умеющий плавать и ходить
terrestrial creature - не умеет плавать, но умеет ходить
bird - умеет ходить и летать
waterfowl - водоплавающая птица. Умеет ходить, летать и плавать.*/


class generic {
public:
    generic() {
        std::cout << "Generic Constructor called" << std::endl;
    }
    virtual ~generic() {
        std::cout << "Generic Deconstructor called" << std::endl;
    }
};

class ocean : public generic {
public:
    ocean() {
        std::cout << "Ocean creatures Constructor called" << std::endl;
    }
    ~ocean() override {
        std::cout << "Ocean creatures Deconstructor called" << std::endl;
    }
    void swim() {
        std::cout << "I can swim" << std::endl;
    }
};

class amphibious : public ocean {
public:
    amphibious() {
        std::cout << "Amphibious creatures Constructor called" << std::endl;
    }
    ~amphibious() override {
        std::cout << "Amphibious creatures Deconstructor called" << std::endl;
    }
    void walk() {
        std::cout << "I can walk" << std::endl;
    }
};

class terrestrial : public amphibious {
public:
    terrestrial() {
        std::cout << "Terrestrial creatures Constructor called" << std::endl;
    }
    ~terrestrial() override {
        std::cout << "Terrestrial creatures Deconstructor called" << std::endl;
    }
    void swim() const = delete;
};

class bird : public terrestrial {
public:
    bird() {
        std::cout << "Bird creatures Constructor called" << std::endl;
    }
    ~bird() override {
        std::cout << "Bird creatures Deconstructor called" << std::endl;
    }
    void fly() {
        std::cout << "I can fly" << std::endl;
    }
};

class waterfowl : public bird {
public:
    waterfowl() {
        std::cout << "Waterfowl creatures Constructor called" << std::endl;
    }
    ~waterfowl() override {
        std::cout << "Waterfowl creatures Deconstructor called" << std::endl;
    }
    using ocean::swim;
};
