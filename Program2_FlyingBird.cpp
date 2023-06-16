#include <iostream>
#include <stdexcept>

class Bird {
public:
    virtual void display() = 0; 
};

class FlyingBird : public Bird {
public:
    void display() override {
        std::cout << "PEACOCK IS FLYING BIRD" << std::endl;
    }
};

class NonFlyingBird : public Bird {
public:
    void display() override {
        std::cout << "PENGUIN IS NON FLYING BIRD" << std::endl;
    }
};

int main() {
    try {
        Bird* birds[2]; 

        FlyingBird peacock; 
        NonFlyingBird penguin; 

        birds[0] = &peacock; 
        birds[1] = &penguin; 

        birds[0]->display();
        birds[1]->display();

        throw std::runtime_error("This is an exception");

    } catch (const std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
