#pragma once
#include "devices.h"
#include "creation.h"

class Company
{
    private:
    Devices devices;
    Creation creation;
    string brand;
    public:
    void input(int* n_sp, int* n_lt);
    void output(int n_sp, int n_lt);
    void outputstr(int n_sp, int n_lt);
    float income(int n_sp, int n_lt);
    int expenses();
    int profit(int n_sp, int n_lt);
    void writefile();
    Company(string brand, Devices devaces, Creation creation);
    Company();
    Company(string brand);
    Company(const Company& comp);

    ~Company();
};