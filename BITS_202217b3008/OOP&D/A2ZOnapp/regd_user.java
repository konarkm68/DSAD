package A2ZOnapp;

import java.util.Scanner;

public class regd_user {

	static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		scanner.close();
	}

	private boolean ch_email;
	private String username, mobile, email, address, pincode;
	private int score = 3;

	public regd_user() {
	}

	public void get_user_details() {
		System.out.println("Field prompts with '*' next to them are mandatory!");
		System.out.print("  Enter First Name*: "); this.username = scanner.next();
		this.username = this.username.substring(0, 1).toUpperCase() + this.username.substring(1).toLowerCase();
		System.out.print("      Enter Mobile*: "); this.mobile = scanner.next();
		System.out.print("Do you want to enter email address? (true/false): "); this.ch_email = scanner.nextBoolean();
		if (ch_email == true) {
			System.out.print("Enter Email address: "); this.email = scanner.next().toUpperCase();
			score = 4;
		}
		System.out.print("    Enter PIN Code*: "); this.pincode = scanner.next();
		System.out.print("     Enter Address*: "); this.address = scanner.next().toUpperCase();
		this.validate_user_details();
	}

	public void validate_user_details() {
		// 1
		if (this.username.length() > 20 && this.username.matches("[A-Z][a-z]+")) {
            System.out.printf("%nName is too long. Please enter a name with a maximum of 20 characters.%n%n");
            score -= 1;
        }
		// 2
        if (this.mobile.length() != 10 && this.mobile.matches("\\d+")) {
            System.out.printf("%nInvalid mobile number. Please enter a 10-digit number.%n%n");
            score -= 1;
        }
		// 3
        if (ch_email && !this.email.matches("(\\w+@\\w+\\.\\w+)?")) {
            System.out.printf("%nInvalid Email address! (Must contain @ and . in that order)%n%n");
            score -= 1;
        }
		// 4
        if (this.pincode.length() != 6 && this.pincode.matches("\\d+")) {
            System.out.printf("%nInvalid PIN Code. Please enter a 6-digit number.%n%n");
            score -= 1;
        }

		if (ch_email == true && score == 4 || ch_email == false && score == 3) {
			System.out.printf("%nRegistered USER with the given details successfully!!%n");
			System.out.printf("%n       Welcome to A-to-Z Online application!!%n%n");
			System.out.printf("    User Name: "+ this.username + "%n");
			System.out.printf("       Mobile: "+ this.mobile + "%n");
			System.out.printf("Email address: "+ this.email + "%n");
			System.out.printf("     PIN Code: "+ this.pincode + "%n");
			System.out.printf("      Address: "+ this.address + "%n");
		} else {
			this.get_user_details();
		}
	}
}
