import java.util.LinkedList;

public class mainClass {

    public static void main(String[] args) {
        Customer customer = new Customer("António", 20); // 50 % desconto
        Product product1 = new Product("Batatas", 20); // 20$
        Product product2 = new Product("Carne", 40); // 40$
        Product product3 = new Product("Arroz", 10); // 10$
        
        OrderLine orderLine1 = new OrderLine(product1, 1);
        OrderLine orderLine2 = new OrderLine(product2, 4);
        OrderLine orderLine3 = new OrderLine(product3, 2);
        
        LinkedList<OrderLine> orders = new LinkedList<OrderLine>();
        orders.add(orderLine1);
        orders.add(orderLine2);
        orders.add(orderLine3);
        
        Order order = new Order(orders, customer);
    }
}