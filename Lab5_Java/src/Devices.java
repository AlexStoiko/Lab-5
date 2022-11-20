import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Devices implements Cloneable{
    private Smartphone [] smartphone;
    private Laptop [] laptop;
    private int n_sp = 0;
    private int n_lt = 0;

    public int getN_sp()
    {
        return n_sp;
    }
    public int getN_lp()
    {
        return n_lt;
    }
    public void setN_sp(int n)
    {
        n_sp = n;
    }
    public void setN_lp(int n)
    {
        n_lt = n;
    }
    public Devices(Smartphone smartphone[], Laptop laptop[])
    {
        this.smartphone = smartphone;
        this.laptop = laptop;
    }
    public Devices()
    {
        for (int i = 0; i < 10; i++)
        {
            this.smartphone[i] = new Smartphone("Model", 0, 0, 0);
        }
        for (int i = 0; i < 10; i++)
        {
            this.laptop[i] = new Laptop("Model", 0, 0);
        }
    }
    public void input_dev()
    {
        for (int i = 0; i < n_sp; i++)
        {
            this.smartphone[i].input();
        }
        for (int i = 0; i < n_lt; i++)
        {
            this.laptop[i].input();
        }
    }
    public void output_dev()
    {
        for (int i = 0; i < n_sp; i++)
        {
            this.smartphone[i].output();
        }
        for (int i = 0; i < n_lt; i++)
        {
            this.laptop[i].output();
        }
    }

    public void outstr_dev()
    {
        Scanner inp = new Scanner(System.in);
        for (int i = 0; i < n_sp; i++)
        {
            System.out.printf("%s\n", smartphone[i].toString());
        }
        for (int i = 0; i < n_lt; i++)
        {
            System.out.printf("%s\n", laptop[i].getstr());
        }
    }
    public int income_dev()
    {
        int income_sp = 0, income_lt = 0;
        for (int i = 0; i < n_sp; i++)
            income_sp += smartphone[i].income();
        for (int i = 0; i < n_lt; i++)
            income_lt += laptop[i].income();
        return income_sp + income_lt;
    }
    public void writefile(String namefile)
    {
        File file = new File(namefile);
        try {
            //проверяем, что если файл не существует то создаем его
            if(!file.exists()){
                file.createNewFile();
            }

            //PrintWriter обеспечит возможности записи в файл
            PrintWriter out = new PrintWriter(file.getAbsoluteFile());

            try {
                for (int i = 0; i < n_sp; i++)
                {
                    out.print(smartphone[i].getstr() + "\n");
                }
                for (int i = 0; i < n_lt; i++)
                {
                    out.print(laptop[i].getstr() + "\n");
                }
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
            Devices clone=(Devices)super.clone();
            return clone;
        }
        catch(CloneNotSupportedException e)
        {
        }
        return this;
    }
}
