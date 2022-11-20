import java.util.Scanner;
public class Creation implements Cloneable {
    private int expenses_rent;
    private int expenses_creation;

    public static float taxes = 0;

    public static void set_taxes()
    {
        Scanner inp = new Scanner(System.in);
        System.out.printf("Введите налоги в процентах ");
        taxes = inp.nextFloat();
    }
    public static float get_taxes()
    {
        return taxes;
    }

    public Creation(int expenses_rent, int expenses_creation)
    {
        this.expenses_rent = expenses_rent;
        this.expenses_creation = expenses_creation;
    }
    public Creation()
    {
        this.expenses_rent = 0;
        this.expenses_creation = 0;
    }
    public void input_creat()
    {
        Scanner inp = new Scanner(System.in);
        System.out.printf("Введите постоянные издержки ");
        this.expenses_rent = inp.nextInt();
        System.out.printf("Введите переменные издержки ");
        this.expenses_creation = inp.nextInt();
    }
    public void output_creat()
    {
        System.out.printf("Постоянные издержки = %d\n", expenses_rent);
        System.out.printf("Переменные издержки = %d\n", expenses_creation);
    }
    public int expenses_creat()
    {
        return expenses_rent + expenses_creation;
    }

    public Object clone()  // перегрузка интерфейса клонирования
    {
        try
        {
            return (Creation)super.clone();
        }
        catch(CloneNotSupportedException e)
        {
        }
        return this;
    }

}
