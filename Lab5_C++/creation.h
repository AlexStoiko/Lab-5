#pragma once
#include <iostream>
#include <string>
using namespace std;

class Creation
{
    private:
    int expenses_rent;
    int expenses_creation;
    public:
    static float taxes;
    void input_creat();
    void output_creat();
    int expenses_creat();

    static void set_taxes();
    static float get_taxes();

    int operator + (int expenses_rent)
    {
        return this->expenses_creation + expenses_rent;
    }

    Creation& operator++ ()
    {
        taxes += 3;
        return *this;
    }

    Creation operator++ (int)
    {
        Creation taxes = *this;
        ++* this;
        return taxes;
    }



    Creation(int expenses_rent, int expenses_creation);
    Creation();
    Creation(int expenses_rent);
    ~Creation();
};
