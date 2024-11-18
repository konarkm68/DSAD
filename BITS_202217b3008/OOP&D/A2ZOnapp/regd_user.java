package A2ZOnapp;

import java.util.Scanner;

public class regd_user {

	static Scanner scanner = new Scanner(System.in);
	static Scanner name_sc = new Scanner(System.in);
	static Scanner addr_sc = new Scanner(System.in);

	public static void main(String[] args) {
	}

	private boolean ch_email;
	private String username, mobile, email, address, pincode;
	private int score = 3;

	public regd_user() {
	}

	public void get_user_details() {
		System.out.println("Field prompts with '*' next to them are mandatory!");
		// Name
		System.out.print("  Enter First Name*: "); this.username = name_sc.nextLine();
		this.username = this.username.substring(0, 1).toUpperCase() + this.username.substring(1).toLowerCase();
		// Contact Details
		System.out.print("      Enter Mobile*: "); this.mobile = scanner.next();
		System.out.print("Do you want to enter email address? (true/false): "); this.ch_email = scanner.nextBoolean();
		if (ch_email == true) {
			System.out.print("Enter Email address: "); this.email = scanner.next().toUpperCase();
			score = 4;
		}
		// Address Details
		System.out.print("    Enter PIN Code*: "); this.pincode = scanner.next();
		System.out.print("     Enter Address*: "); this.address = addr_sc.nextLine().toUpperCase();
		this.validate_user_details();
	}

	public void validate_user_details() {
		System.out.println();
		// 1 - Validate Name
		if (this.username.length() > 20 && this.username.matches("[A-Z][a-z]+")) {
            System.out.println("Name is too long. Please enter a name with a maximum of 20 characters.");
            score -= 1;
        }
		// 2 - Validate Mobile
        if (this.mobile.length() != 10 && this.mobile.matches("\\d+")) {
            System.out.println("Invalid mobile number. Please enter a 10-digit number.");
            score -= 1;
        }
		// 3 - Validate Email
        if (ch_email && !this.email.matches("(\\w+@\\w+\\.\\w+)?")) {
            System.out.println("Invalid Email address! (Must contain @ and .)");
            score -= 1;
        }
		// 4 - Validate PIN Code
        if (this.pincode.length() != 6 && this.pincode.matches("\\d+")) {
            System.out.println("Invalid PIN Code. Please enter a 6-digit number.");
            score -= 1;
        }
        // Successful Registration OR details needed
		if (ch_email == true && score == 4 || ch_email == false && score == 3) {
			System.out.printf("%nRegistered USER with the given details successfully!!%n");
			System.out.printf("%n       Welcome to A-to-Z Online application!!%n%n");
			
			System.out.printf("    User Name: "+ this.username + "%n");
			System.out.printf("       Mobile: "+ this.mobile + "%n");
			System.out.printf("Email address: "+ this.email + "%n");
			System.out.printf("     PIN Code: "+ this.pincode + "%n");
			System.out.printf("      Address: "+ this.address + "%n");
		} else {
			score = 3;
			this.get_user_details();
		}
	}
}