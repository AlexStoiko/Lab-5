import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Company implements Cloneable
{
    private String brand;
    private Devices devices;
    private Creation creation;
    public Company(String brand, Devices devices, Creation creation)
    {
        this.brand = brand;
        this.devices = devices;
        this.creation = creation;
    }
    public Company()
    {
        this.devices = new Devices();
        this.creation = new Creation();
        this.brand = "Brand";
    }
    public void input()
    {
        int n_sp, n_lt;
        Scanner inp = new Scanner(System.in);
        System.out.printf("Введите название компании ");
        brand = inp.next();
        System.out.printf("Введите число моделей смартфонов вашей компании ");
        n_sp = inp.nextInt();
        devices.setN_sp(n_sp);
        System.out.printf("Введите число моделей ноутбуков вашей компании ");
        n_lt = inp.nextInt();
        devices.setN_lp(n_lt);
        devices.input_dev();
        creation.input_creat();
    }
    public void output()
    {
        System.out.printf("Название компании: %s\n", brand);
        this.devices.output_dev();
        this.creation.output_creat();
    }
    public void outputstr()
    {
        devices.outstr_dev();
    }
    public float income()
    {
        float income, taxes;
        taxes = creation.get_taxes();
        income = (float)devices.income_dev() * (100 - taxes) / 100;
        return income;
    }
    public int expenses()
    {
        return creation.expenses_creat();
    }
    public float profit()
    {
        return income() - expenses();
    }

    public void writefile()
    {
        Scanner inp = new Scanner(System.in);
        System.out.printf("Введите название файла ");
        String namefile = inp.next();
        File file = new File(namefile);
        try {
            //проверяем, что если файл не существует то создаем его
            if(!file.exists()){
                file.createNewFile();
            }

            //PrintWriter обеспечит возможности записи в файл
            PrintWriter out = new PrintWriter(file.getAbsoluteFile());

            try
            {
                out.print(brand + "\n");
                out.close();
                devices.writefile(namefile);
            } finally {
                out.close();
            }
        } catch(IOException e) {
            throw new RuntimeException(e);
        }
    }
    public Object clone()  // перегрузка интерфейса клонирования
    {
        try
        {
            Company clone=(Company)super.clone();
            clone.devices=(Devices)devices.clone();
            clone.creation=(Creation)creation.clone();
            return clone;
        }
        catch(CloneNotSupportedException e)
        {
        }
        return this;
    }
}
