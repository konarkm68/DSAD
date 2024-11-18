package A2ZOnapp;

import java.util.Scanner;

public class product_info {
    public static void main(String[] args) {
    }
    
    // Product categories and items (using arrays)
    static String[] categories = {"EXIT", "Electronics", "Grocery"};
    static Product[][] products = {
    		{},
            {new Product("Laptop", "(1 pc.)", 80000), new Product("Smartphone", "(1 pc.)", 40000), new Product("Headphones", "(1 pc.)", 5000)},
            {new Product("Rice", "(1 kg.)", 50), new Product("Wheat Flour", "(1 kg.)", 40), new Product("Oil", "(1 l.)", 150)}
    };

    public static class Product {
        String name; String quantity; float price;

        public Product(String name, String quantity, float price) {
            this.name = name;
            this.quantity = quantity;
            this.price = price;
        }
    }

    public static void display_product_details() {
    	Scanner sc = new Scanner(System.in);
    	
        // Display categories
        System.out.printf("%nAvailable Categories:%n");
        for (String category : categories) {
        	if (category.equals("EXIT")) {
        		continue; // Skip category value which is stored as EXIT
        	}
            System.out.println("- " + category);
        }
        System.out.println();

        String chosenCategory;
        // Display products in the chosen category
        do {
            System.out.print("Enter the category you want to explore (or 'EXIT' to exit this prompt): ");
            chosenCategory = sc.nextLine().trim().toLowerCase();

            if (categories[0].toLowerCase().equals(chosenCategory)) {
                break; // Exit loop if user enters "EXIT" (case-insensitive)
            }

            for (int i = 1; i < categories.length; i++) {
                if (categories[i].toLowerCase().equalsIgnoreCase(chosenCategory)) {
                    System.out.printf("%nProducts in " + categories[i] + ": %n");
                    for (Product product : products[i]) {
                        System.out.println("- " + product.name + " " + product.quantity + ": ₹" + product.price);
                    }
                    break;
                } else {
                    System.out.println("Invalid category. Please enter a valid category or 'EXIT'.");
                }
            }
        } while (true);
        
        sc.close();

    }
}