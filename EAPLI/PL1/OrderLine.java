public class OrderLine {
    private Product product;
    private int quantity;

    public OrderLine(Product product, int quantity) {
        this.product = product;
        this.quantity = quantity;
    }
    
    public double calculatePrice(){
        return product.getPrice(quantity);
    }
}
