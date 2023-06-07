#include <iostream>

using namespace std;

class Rectangle 
{
protected:
    double length;
    double width;

public:
    Rectangle(double length, double width) 
    {
        this->length = length;
        this->width = width;
    }

    double computeArea() 
    {
        return length * width;
    }
};

class Block : public Rectangle 
{
private:
    double height;

public:
    Block(double length, double width, double height) : Rectangle(length, width) 
    {
        this->height = height;
    }

    double computeVolume() 
    {
        return length * width * height;
    }
};

int main() 
{
    Rectangle rectangle(5.0, 3.0);
    cout << "Rectangle Area: " << rectangle.computeArea() << endl;

    Block block(4.0, 2.0, 3.0);
    cout << "Block Volume: " << block.computeVolume() << endl;

    return 0;
}
