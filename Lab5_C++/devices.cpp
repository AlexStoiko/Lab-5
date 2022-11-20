#include "devices.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Devices::Devices(Smartphone* smartphone, Laptop* laptop)
{
    this->smartphone = smartphone;
    this->laptop = laptop;
}

Devices::Devices(const Devices& dev_ref)
{
    this->smartphone = new Smartphone(*dev_ref.smartphone);
    this->laptop = new Laptop(*dev_ref.laptop);
}

Devices::Devices()
{
    smartphone = new Smartphone("Model", 0, 0, 0);
    laptop = new Laptop("Model", 0, 0, "None");
}

Devices::Devices(Smartphone* smartphone)
{
    this->smartphone = smartphone;
    this->laptop = new Laptop("Model", 0, 0, "None");
}

Devices::~Devices() {}


void Devices::input_dev(int n_sp, int n_lt)
{
    this->n_sp = n_sp;
    this->n_lt = n_lt;
    
    for (int i = 0; i < this->n_sp; i++)
    {
        smartphone[i].input();
    }
    for (int i = 0; i < this->n_lt; i++)
    {
        laptop[i].input();
    }
}

void Devices::output_dev()
{
    for (int i = 0; i < n_sp; i++)
    {
        smartphone[i].output();
    }
    for (int i = 0; i < n_lt; i++)
    {
        laptop[i].output();
    }
}

void Devices::outstr_dev()
{
    for (int i = 0; i < n_sp; i++)
    {
        cout << smartphone[i];
    }
    for (int i = 0; i < n_lt; i++)
    {
        cout << laptop[i].getstr() << endl;
    }
}

int Devices::income_dev()
{
    int income_sp = 0, income_lt = 0;
    for (int i = 0; i < n_sp; i++)
        income_sp += smartphone[i].income();
    for (int i = 0; i < n_lt; i++)
        income_lt += laptop[i].income();
    return income_sp + income_lt;
}

void outsmartp(Smartphone& smartphone, int n_sp)
{
    for (int i = 0; i < n_sp; i++)
    {
        cout << smartphone.model << "\t|" << smartphone.quantity << "\t|" << smartphone.price << endl;
    }
}

int Devices::get_n_sp()
{
    return n_sp;
}

int Devices::get_n_lt()
{
    return n_lt;
}

void Devices::writefile(string namefile)
{
    //string namefile = "Company.txt";
    ofstream fout(namefile);
    try
    {
        if (!fout.is_open())
            throw 1;
        fout.open(namefile, ios_base::app);
        for (int i = 0; i < n_sp; i++)
        {
            fout << smartphone[i].getstr() << endl;
        }
        for (int i = 0; i < n_lt; i++)
        {
            fout << laptop[i].getstr() << endl;
        }
        fout.close();
    }
    catch (...)
    {
        cout << "Ошибка открытия файла" << endl;
    }
}
