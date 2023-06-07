#include <iostream>
using namespace std;

class Exterior  // Base Class
{
  protected:
    float area;
  public:
    void setArea(float a) 
    {
      area = a;
    }
    float getArea() 
    {
      return area;
    }
};

class Paint : public Exterior //Inheriting Exterior Class in Paint Class publicly. Paint class sets the paint type and brand
{
  protected:
    string paintType;
    string brand;
  public:
    void setPaintType(string p) 
    {
      paintType = p;
    }
    void setBrand(string b) 
    {
      brand = b;
    }
    void selectPaint() 
    {
      cout << "Selecting paint type: " << paintType << endl;
      cout << "Selecting brand: " << brand << endl;
    }
};

class Bill : public Paint //Inheriting Paint Class in Bill Class publicly. Bill class calculates the cost of painting the house
{
  private:
    float costPerSqFt;
    float totalCost;
  public:
    void setCostPerSqFt(float c) 
    {
      costPerSqFt = c;
    }
    void calculateCost() 
    {
      totalCost = area * costPerSqFt;
      cout << "The final cost for painting the house is $" << totalCost << endl;
    }
};

int main() 
{
    Bill b;
    b.setArea(1000);
    b.setPaintType("Luxury Emulsion");
    b.setBrand("Nerolac");
    b.setCostPerSqFt(3.50);
    b.selectPaint();
    b.calculateCost();
    return 0;
}
