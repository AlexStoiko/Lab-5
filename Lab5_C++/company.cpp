#define _CRT_SECURE_NO_WARNINGS
#include "company.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Company::Company(const Company& company)
{
    brand = string(company.brand);
    devices = Devices(company.devices);
    creation = Creation(company.creation);
}

Company::Company(string brand, Devices devices, Creation creation)
{
    this->brand = brand;
    this->devices = devices;
    this->creation = creation;
}

Company::Company()
{
    devices = Devices();
    creation = Creation();
    brand = "Brand";
}

Company::Company(string brand)
{
    this->brand = brand;
    devices = Devices();
    creation = Creation();
}

Company::~Company() {}

void Company::input(int* n_sp, int* n_lt)
{
    cout << "Введите название компании" << endl;
    cin >> brand;
    cout << "Введите число моделей смартфонов вашей компании" << endl;
    cin >> *n_sp;
    cout << "Введите число моделей ноутбуков вашей компании" << endl;
    cin >> *n_lt;
    devices.input_dev(*n_sp, *n_lt);
    creation.input_creat();
}

void Company::output(int n_sp, int n_lt)
{
    cout << brand << endl;
    devices.output_dev();
    creation.output_creat();
}

void Company::outputstr(int n_sp, int n_lt)
{
    devices.outstr_dev();
}

float Company::income(int n_sp, int n_lt)
{
    float income;
    income = devices.income_dev() * (100 - creation.taxes) / 100;
    return income;
}

int Company::expenses()
{
    return creation.expenses_creat();
}

int Company::profit(int n_sp, int n_lt)
{
    return income(n_sp, n_lt) - expenses();
}

void Company::writefile()
{
    string namefile;
    cout << "Введите название файла" << endl;
    cin >> namefile;
    ofstream fout(namefile);
    try
    {
        if (!fout.is_open())
            throw 1;
        fout.open(namefile, ios_base::trunc);
        fout << brand << endl;
        fout.close();
        devices.writefile(namefile);
    }
    catch (...)
    {
        cout << "Ошибка открытия файла" << endl;
    }
}