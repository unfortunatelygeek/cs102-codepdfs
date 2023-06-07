#include <iostream>
#include <cmath>

using namespace std;

class Geometry
{
private:
    float radius;
    float length;
    float breadth;
    float height;

public:
    //First Constructor - Takes no arguments
    Geometry()
    {
        radius = 0;
        length = 0;
        breadth = 0;
        height = 0;
    }

    //Second Constructor - Takes radius as argument
    Geometry (float r)
    {
        radius = r;
        length = 0;
        breadth = 0;
        height = 0;
    }

    //Third Constructor - Takes length and breadth as arguments
    Geometry(float l, float b)
    {
        radius = 0;
        length = l;
        breadth = b;
        height = 0;
    }

    //Fourth Constructor - Takes length, breadth and height as arguments
    Geometry(float l, float b, float h)
    {
        radius = 0;
        length = l;
        breadth = b;
        height = h;
    }

    //calculate area
    float area()
    {
        float area;
        if (radius != 0)
            area = M_PI * radius * radius;
        else if (height == 0)
            area = length * breadth;
        else if (height != 0)
            area = 2 * ((length * breadth)+(height * breadth)+(length * height));
        return area;
    }

    //Display Area of the given shape
    void display()
    {
        cout << "The area of the given object is: " << area() << endl;
    }
};

int main()
{
    cout << "This program was brought to you by Aditi Rao, 2022200003." << endl;
    int choice;
    cout << "Press the listed numbers to get areas of: \n1. Circle\n2. Rectangle\n3. Cuboid\n" << endl;
    cin >> choice;
    float r, l, b, h;
    do
    {
        switch (choice)
        {

        case 1:
            {
                cout << "Kindly enter the radius of the circle. " << endl;
                cin >> r;
                Geometry circle(r);
                cout << "Area of a circle is: ";
                circle.display();
                break;
            }

        case 2:
            {
                cout << "Kindly enter the length and breadth of the rectangle. " << endl;
                cin >> l >> b;
                Geometry rectangle(l, b);
                cout << "Area of the rectangle is: ";
                rectangle.display();
                break;
            }

        case 3:
            {
                cout << "Kindly enter the length, breadth and height of the cuboid. " << endl;
                cin >> l >> b >> h;
                Geometry cuboid(l, b, h);
                cout << "Area of the cuboid is: ";
                cuboid.display();
                break;
            }

        default:
            cout << "Incorrect Input. " << endl;
        }

        cout << "To exit the loop, press 0." << endl;
        cin >> choice;
    }
    while (choice != 0);
    return 0;
}
