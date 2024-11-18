package A2ZOnapp;

import java.util.Scanner;

public class product_info {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
    }
    
    // Product categories and items (using arrays)
    static String[] categories = {"EXIT", "Electronics", "Grocery"};
    static Product[][] products = {
    		{},
            {new Product("Laptop", 80000), new Product("Smartphone", 40000), new Product("Headphones", 5000)},
            {new Product("Rice", 50), new Product("Wheat", 40), new Product("Oil", 150)}
    };

    public static class Product {
        String name;
        int price;

        public Product(String name, int price) {
            this.name = name;
            this.price = price;
        }
    }

    public static void display_product_details() {
        // Display categories
        System.out.printf("%nAvailable Categories:%n");
        for (String category : categories) {
        	if (category.equals("EXIT")) {
        		continue;
        	}
            System.out.println("- " + category);
        }
        System.out.println();

        String chosenCategory;

        // Display products in the chosen category
        do {
            System.out.print("Enter the category you want to explore (or 'EXIT' to quit): ");
            chosenCategory = scanner.nextLine().toLowerCase();

            if (categories[0].toLowerCase().equals(chosenCategory)) {
                break; // Exit loop if user enters "EXIT!!" (case-insensitive)
            }

            for (int i = 0; i < categories.length; i++) {
                if (categories[i].toLowerCase().equalsIgnoreCase(chosenCategory)) {
                    System.out.printf("%nProducts in " + categories[i] + ": %n");
                    for (Product product : products[i]) {
                        System.out.println("- " + product.name + ": ₹" + product.price);
                    }
                    break; // Exit inner loop after displaying products
                }
            }
        } while (true); // Continue loop until user enters "EXIT!!"
    }
}