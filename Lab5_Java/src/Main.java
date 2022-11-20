import java.util.*;
public class Main {
    public static void main(String[] args) {

        int exit = 1, n_sp, n_lt, n;
        Smartphone [] smartphone = new Smartphone[10];
        for (int i = 0; i < 10; i++)
        {
            smartphone[i] = new Smartphone("Model", 0, 0, 0);
        }
        Laptop [] laptop = new Laptop[10];
        for (int i = 0; i < 10; i++)
        {
            laptop[i] = new Laptop("Model", 0, 0);
        }
        Devices devices = new Devices(smartphone, laptop);
        Creation creation = new Creation(0, 0);
        Company company = new Company("Brand", devices, creation);
        company.input();
        do {
            n = 0;
            System.out.println ("Выберите действие:\nВыход из программы (0)\nПосчитать доход с продаж (1)\nПосчитать издержки компании (2)\nПосчитать прибыль компании (3)\nВывести все данные компании (4)\nУказать налоги (5)\nВывести данные о продуктах этой компании(6)\nЗапись в файл(7)\nКлонирование компании(8)\n");
            Scanner inp = new Scanner(System.in);
            n = inp.nextInt();
            switch (n) {
                case 0:
                    exit = 0;
                    break;
                case 1:
                    System.out.printf("Доход с продаж = %f\n", company.income());
                    break;
                case 2:
                    System.out.printf("Издержки компании = %d\n", company.expenses());
                    break;
                case 3:
                    System.out.printf("Прибыль компании = %f\n", company.profit());
                    break;
                case 4:
                    company.output();
                    break;
                case 5:
                    creation.set_taxes();
                    break;
                case 6:
                    company.outputstr();
                    break;
                case 7:
                    company.writefile();
                    break;
                case 8:
                    Company company1;
                    company1=(Company)company.clone();
                    company1.output();
                    break;
                default:
                    break;
            }
        } while (exit == 1);
    }
}