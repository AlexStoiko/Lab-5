import java.util.Scanner;
public class Smartphone extends Product
        implements Product_Interface
{
    private int cameraMp;
    public Smartphone(String model, int quantity, int price, int cameraMp)
    {
        super(model, quantity, price);
        this.cameraMp = cameraMp;
    }
    public Smartphone()
    {
        this.model = "Model";
        this.quantity = 0;
        this.price = 0;
        this.cameraMp = 0;
    }
    public void input()
    {
        Scanner inp = new Scanner(System.in);
        System.out.printf("Введите модель смартфона ");
        this.model = inp.next();
        System.out.printf("Введите число произведенных смартфонов ");
        this.quantity = inp.nextInt();
        System.out.printf("Ввведите цену одного смартфона ");
        this.price = inp.nextInt();
        System.out.printf("Ввведите Mp камеры смартфона ");
        this.cameraMp = inp.nextInt();
    }
    public void output()
    {
        System.out.printf("Модель смартфона: %s\n", this.model);
        System.out.printf("Число произведенных смарфонов = %d\n", this.quantity);
        System.out.printf("Цена одного смартфона = %d\n", this.price);
        System.out.printf("Камера смартфона(Mp) = %d\n", this.cameraMp);
    }

    public String getstr()
    {
        String smartphone;
        smartphone = super.getstr() + " " + Integer.toString(cameraMp);
        return smartphone;
    }

    public String toString()
    {
        return model+" "+quantity+" "+price+" "+cameraMp;
    }
}
