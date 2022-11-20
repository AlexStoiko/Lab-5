#include "smartphone.h"

Smartphone::Smartphone(const Smartphone& smart_ref)
{
    model = string(smart_ref.model);
    quantity = int(smart_ref.quantity);
    price = int(smart_ref.price);
    cameraMp = int(smart_ref.cameraMp);
}

Smartphone::Smartphone()
{
    model = "Model";
    quantity = 0;
    price = 0;
    cameraMp = 0;
}

Smartphone::Smartphone(string model, int quantity, int price, int cameraMp):Product(model, quantity, price)
{
    this->cameraMp = cameraMp;
}

Smartphone::Smartphone(string model)
{
    this->model = model;
    quantity = 0;
    price = 0;
    cameraMp = 0;
}

Smartphone::~Smartphone() {}


void Smartphone::input()
{
    cout << "Введите модель смартфона" << endl;
    cin >> model;
    cout << "Введите число произведенных смартфонов" << endl;
    cin >> quantity;
    cout << "Ввведите цену одного смартфона" << endl;
    cin >> price;
    cout << "Ввведите Mp камеры смартфона" << endl;
    cin >> cameraMp;
}

void Smartphone::output()
{
    cout << "Модель смартфона: " << model << endl;
    cout << "Число произведенных смарфонов = " << quantity << endl;
    cout << "Цена одного смартфона = " << price << endl;
    cout << "Камера смартфона(Mp) = " << cameraMp << endl;
}

string Smartphone::getstr()
{
    string smartphone;
    smartphone = Product::getstr() + " " + to_string(cameraMp);
    return smartphone;
}

void Smartphone::operator = (Product product)
{
    this->model = product.getmodel();
    this->quantity = product.getquantity();
    this->model = product.getprice();
    this->cameraMp = 0;
}

void operator << (ostream& o, Smartphone smartphone)
{
    cout << smartphone.model << " " << smartphone.quantity << " " << smartphone.price << " " << smartphone.cameraMp << endl;
}

Smartphone operator >> (istream & o, Smartphone & smartphone)
{
    cin >> smartphone.model >> smartphone.quantity >> smartphone.price >> smartphone.cameraMp;
    return smartphone;
}