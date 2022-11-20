import java.util.Scanner;
abstract class Product implements Cloneable
{
    protected String model;
    protected int quantity;
    protected int price;

    public Product(String model, int quantity, int price)
    {
        this.model = model;
        this.quantity = quantity;
        this.price = price;
    }
    public Product()
    {
        this.model = "Model";
        this.quantity = 0;
        this.price = 0;
    }
    public abstract void output();
    public String getstr()
    {
        String smartphone;
        smartphone = model + " " + Integer.toString(quantity) + " " + Integer.toString(price);
        return smartphone;
    }
    public int income()
    {
        int income = 0;
        income = this.price * this.quantity;
        return income;
    }
    public Object clone()
    {
        try
        {
            return (Product)super.clone();
        }
        catch(CloneNotSupportedException e)
        {
        }
        return this;
    }
}

