#pragma once
#include "smartphone.h"
#include "laptop.h"

class Devices
{
    private:
    Smartphone* smartphone;
    Laptop* laptop;
    int n_sp;
    int n_lt;
    public:
    void input_dev(int n_sp, int n_lt);
    void output_dev();
    int income_dev();
    void outstr_dev();
    int get_n_sp();
    int get_n_lt();
    void writefile(string namefile);

    Devices(Smartphone* smartphone, Laptop* laptop);
    friend void outsmartp(Smartphone& smartphone, int n_sp);
    Devices();

    Devices(Smartphone* smartphone);

    Devices(const Devices & dev_ref);

    ~Devices();
};