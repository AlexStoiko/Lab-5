#include "product.h"

Product::Product(string model, int quantity, int price)
{
    this->model = model;
    this->quantity = quantity;
    this->price = price;
}

Product::Product(const Product& smart_ref)
{
    model = string(smart_ref.model);
    quantity = int(smart_ref.quantity);
    price = int(smart_ref.price);
}

Product::Product()
{
    model = "Model";
    quantity = 0;
    price = 0;
}

Product::Product(string model)
{
    this->model = model;
    quantity = 0;
    price = 0;
}

Product::~Product() {}

void Product::input()
{
    cout << "Введите модель товара" << endl;
    cin >> model;
    cout << "Введите число произведенных  товаров" << endl;
    cin >> quantity;
    cout << "Ввведите цену одного товара" << endl;
    cin >> price;
}

void Product::output()
{
    cout << "Модель товара: " << model << endl;
    cout << "Число произведенных товаров = " << quantity << endl;
    cout << "Цена одного товара = " << price << endl;
}

string Product::getstr()
{
    string Product;
    Product = model + " " + to_string(quantity) + " " + to_string(price);
    return Product;
}

int Product::income()
{
    return price * quantity;
}

string Product::getmodel()
{
    return model;
}

int Product::getquantity()
{
    return quantity;
}
int Product::getprice()
{
    return price;
}

void operator << (ostream& o, Product product)
{
    cout << product.model << " " << product.quantity << " " << product.price << endl;
}

Product operator >> (istream& o, Product& product)
{
    cin >> product.model >> product.quantity >> product.price;
    return product;
}
