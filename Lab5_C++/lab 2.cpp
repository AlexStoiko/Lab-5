#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

#include "company.h"
#include "devices.h"
#include "creation.h"
#include "laptop.h"
#include "smartphone.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int exit = 1, n_sp = 0, n_lt = 0, n;
    Smartphone* smartphone = new Smartphone[10];
    Laptop* laptop = new Laptop[10];
    Devices devices(smartphone, laptop);
    Creation creation(0, 0);
    Company company("Brand", devices, creation);
    company.input(&n_sp, &n_lt);
    do
    {
        n = 0;
        system("cls");
        cout << "Выберите действие:\nВыход из программы (0)\nПосчитать доход с продаж (1)\nПосчитать издержки компании (2)\nПосчитать прибыль компании (3)\nВывести все данные компании (4)\nУказать налоги (5)\nВывести данные о продуктах этой компании(6)\nИнфляция 3%(7)\nЗапись в файл(8)\n" << endl;
        cin >> n;
        cin.clear();
        switch (n)
        {
        case 0:
            exit = 0;
            break;
        case 1:
            cout << "Доход с продаж =" << company.income(n_sp, n_lt) << endl;
            _getch();
            break;
        case 2:
            cout << "Издержки компании =" << company.expenses() << endl;
            _getch();
            break;
        case 3:
            cout << "Прибыль компании =" << company.profit(n_sp, n_lt) << endl;
            _getch();
            break;
        case 4:
            company.output(n_sp, n_lt);
            _getch();
            break;
        case 5:
            creation.set_taxes();
            break;
        case 6:
            company.outputstr(n_sp, n_lt);
            _getch();
            break;
        case 7:
            creation.taxes++;
            break;
        case 8:
            company.writefile();
            _getch();
            break;
        default:
            break;
        }
    } while (exit);
    delete[] smartphone;
    delete[] laptop;
    return (0);
}