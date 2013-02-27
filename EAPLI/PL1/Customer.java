public class Customer {
    private String name;
    private double discounted;

    public Customer(String name, double discounted) {
        this.name = name;
        this.discounted = discounted;
    }
    
    public double getDiscountedValue(Order o){
        return o.getBaseValue() * (discounted / 100);
    }
}