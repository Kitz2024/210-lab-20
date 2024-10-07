// Kit Pollinger
//  210 - lab - 20 | Chair Maker

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;

class Chair
{
private:
    int legs;
    double *prices;

public:
    // constructors
    Chair()
    {
        // select 3 or 4 legs
        legs = rand() % 2 + 3;
        // Allocate memory for the prices array
        prices = new double[SIZE];
        // Randomly secret pricess between $100.00 and $999.99
        for (int i = 0; i < SIZE; i++)
        {
            const int MIN = 10000, MAX = 99999;
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double)100;
        }
    }

    Chair(int l, double p1, double p2, double p3)
    {

        // set the number of legs
        legs = 1;
        // Allocate memory for prices array
        prices = new double[SIZE];

        // set prices
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3)
    {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices()
    {
        // Calculate the sum of prices
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += prices[i];
        }
        // Calculate the average price
        return sum / SIZE;
    }

    void print()
    {
        // Print the chair's data
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
        {
            cout << prices[i] << " ";
        }
        cout << endl
             << "Historical avg price: " << getAveragePrices();
        cout << endl
             << endl;
    }
};

int main()
{
    // Seed Random Number gernator once
    srand(time(0));

    cout << fixed << setprecision(2);

    // creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();

    // creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3, 525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    return 0;
}