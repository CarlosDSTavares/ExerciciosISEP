import java.util.LinkedList;
import java.util.List;

public class Order {
    private List<OrderLine> orders;
    private Customer customer;
    private double subTotal = 0.0;

    public Order(List<OrderLine> orders, Customer costumer) {
        this.orders = orders;
        this.customer = costumer;
    }
    
    public void calculatePrice(){
        double sum = 0;
        for (OrderLine ol : orders) {
            double price = ol.calculatePrice();
            calculateBasePrice(price);
        }
    }
    
    private void calculateBasePrice(double price){
        subTotal += price;
    }
    
    public double getBaseValue(){
        return subTotal;
    }
}//end class
