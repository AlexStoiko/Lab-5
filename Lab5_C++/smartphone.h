#pragma once
#include "product.h"
#include <iostream>
#include <string>
using namespace std;

class Smartphone : public Product
{
    private:
    int cameraMp;
    public:
    void input();
    void output();
    string getstr();

    Smartphone(string model, int quantity, int price, int cameraMp);

    Smartphone();

    Smartphone(string model);

    Smartphone(const Smartphone & smart_ref);

    ~Smartphone();

    friend void outsmartp(Smartphone& smartphone, int n_sp);

    void operator = (Product product);

    friend void operator << (ostream& o, Smartphone smartphone);
    friend Smartphone operator >> (istream& i, Smartphone& smartphone);
};
