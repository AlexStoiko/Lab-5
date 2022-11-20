#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
    string model;
    int quantity;
    int price;
public:
    void input();
    virtual void output();
    int income();
    string getstr();

    string getmodel();
    int getquantity();
    int getprice();

    Product(string model, int quantity, int price);

    Product();

    Product(string model);

    Product(const Product& smart_ref);

    ~Product();

    friend void operator << (ostream& o, Product product);
    friend Product operator >> (istream& i, Product& product);
};