package A2ZOnapp;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import A2ZOnapp.product_info.Product;

public class cust_billing {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
    }

    public static void checkout() {
    	String chosenProduct;
        boolean itemAdded = false;
        float totalAmount = 0;
        List<Product> cart = new ArrayList<>();

    	do {
            System.out.printf("%nEnter the product name to add to your cart (or 'EXIT' to exit this prompt): ");
            chosenProduct = scanner.nextLine().toLowerCase();

            if (product_info.categories[0].toLowerCase().equals(chosenProduct)) {
                break; // Exit loop if user enters "EXIT" (case-insensitive)
            }

            for (int i = 1; i < product_info.categories.length; i++) {
                for (Product product : product_info.products[i]) {
                	if (product.name.toLowerCase().equals(chosenProduct)) {
                        cart.add(product);
                        itemAdded = true;
                        totalAmount += product.price;
                    	System.out.println("Item IS available and added to your cart!");
                    }
                }
            }

            if (itemAdded == false) {
            	System.out.println("Item IS NOT available!");
            }

            itemAdded = false;

        } while (true); // Continue loop until user enters "EXIT"

        // Display total amount and payment options
        System.out.printf("%nTotal Amount: ₹" + totalAmount + "%n");
        System.out.printf("%nPayment Options: %n");
        System.out.println("1. Cash on Delivery");
        System.out.println("2. Online Payment (PayTM/Google Pay/PhonePe)");

        // Get payment method
        System.out.printf("%nEnter your payment method (1 or 2): "); int paymentMethod = scanner.nextInt();

        // Process payment (simplified)
        if (paymentMethod == 1) {
            System.out.printf("%nPlease pay ₹" + totalAmount + " on delivery.");
        } else if (paymentMethod == 2) {
            System.out.printf("%nOnline payment successful. Thank you!");
        } else {
            System.out.printf("%nInvalid payment method.");
        }
        System.out.printf("%nThank you for shopping with us! Visit our website again.");
    }
}