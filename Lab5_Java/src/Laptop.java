import java.util.Scanner;
public class Laptop extends Product
        implements Product_Interface
{
    private String videocard;
    public Laptop(String model, int quantity, int price)
    {
        super(model, quantity, price);
        this.videocard = "None";
    }
    public Laptop()
    {
        this.model = "Model";
        this.quantity = 0;
        this.price = 0;
        this.videocard = "None";
    }
    public void input()
    {
        Scanner inp = new Scanner(System.in);
        System.out.printf("Введите модель ноутбука ");
        this.model = inp.next();
        System.out.printf("Введите число произведенных ноутбуков ");
        this.quantity = inp.nextInt();
        System.out.printf("Ввведите цену одного ноутбука ");
        this.price = inp.nextInt();
        System.out.printf("Введите модель видеокарты ноутбука ");
        this.videocard = inp.next();
    }
    public void output()
    {
        System.out.printf("Модель ноутбука: %s\n", this.model);
        System.out.printf("Число произведенных ноутбуков = %d\n", this.quantity);
        System.out.printf("Цена одного ноутбука = %d\n", this.price);
        System.out.printf("Модель видеокарты ноутбука = %s\n", this.videocard);
    }

    public String getstr()
    {
        String smartphone;
        smartphone = super.getstr() + " " + videocard;
        return smartphone;
    }
    public String toString()
    {
        return model + " " + quantity + " " + price + " " + videocard;
    }
}
