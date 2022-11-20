#include "creation.h"

float Creation::taxes = 0;

Creation::Creation(int expenses_rent, int expenses_creation)
{
    this->expenses_rent = expenses_rent;
    this->expenses_creation = expenses_creation;
}

Creation::Creation()
{
    expenses_rent = 0;
    expenses_creation = 0;
}

Creation::Creation(int expenses_rent)
{
    this->expenses_rent = expenses_rent;
    this->expenses_creation = 0;
}

Creation::~Creation() {}

void Creation::set_taxes()
{
    cout << "Введите налоги в %" << endl;
    cin >> taxes;
}

float Creation::get_taxes()
{
    return taxes;
}

void Creation::input_creat()
{
    cout << "Введите постоянные издержки" << endl;
    cin >> expenses_rent;
    cout << "Введите переменные издержки" << endl;
    cin >> expenses_creation;
}

void Creation::output_creat()
{
    cout << "Постоянные издержки = " << expenses_rent << endl;
    cout << "Переменные издержки = " << expenses_creation << endl;
}

int Creation::expenses_creat()
{
    return expenses_rent + expenses_creation;
}