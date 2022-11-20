#pragma once
#include "product.h"
#include <iostream>
#include <string>
using namespace std;

class Laptop : public Product
{
    private:
    string videocard;
    public:
    void input();
    void output();
    string getstr();

    Laptop(string model, int quantity, int price, string videocard);

    Laptop();

    Laptop(string model);

    Laptop(const Laptop& lap_ref);

    ~Laptop();

    void operator = (Product product);

    friend void operator << (ostream& o, Laptop laptop);
    friend Laptop operator >> (istream& i, Laptop& laptop);
};
