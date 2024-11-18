package A2ZOnapp;

import java.util.Scanner;

public class regd_user {
	public static void main(String[] args) {
	}
	
	private boolean ch_email;
	private String username, mobile, email, address, pincode; 
	private int score = 3;
	
	public regd_user() {
	}
	
	public void get_user_details() {
		Scanner usr_sc = new Scanner(System.in);
		Scanner add_sc = new Scanner(System.in);
		
		System.out.println("Field prompts with '*' next to them are mandatory!");
		// Name
		System.out.print("        Enter Name*: "); this.username = usr_sc.nextLine().trim();
		if (this.username.contains(" ")) {
			String[] words = this.username.split(" ");
			for (int i = 0; i < words.length; i++) {
			    words[i] = words[i].substring(0, 1).toUpperCase() + words[i].substring(1).toLowerCase();
			}
			this.username = String.join(" ", words);
		}
        // Mobile
		System.out.print("      Enter Mobile*: "); this.mobile = usr_sc.next().trim();
		// Email Address
		System.out.print("Do you want to enter Email Address? (true/false): "); this.ch_email = usr_sc.nextBoolean();
		if (ch_email == true) {
			System.out.print("Enter Email Address: "); this.email = usr_sc.next().trim().toUpperCase();
			this.score = 4;
		}
		// Address
		System.out.print("    Enter PIN Code*: "); this.pincode = usr_sc.next().trim();
		System.out.print("     Enter Address*: "); this.address = add_sc.nextLine().trim().toUpperCase();
		// Validate user details
		this.validate_user_details();
		
		usr_sc.close();
		add_sc.close();
	}
	
	public void validate_user_details() {
        System.out.println();
		// 1
		if (this.username.length() > 20 && this.username.matches("[A-Z -][a-z -]+")) {
            System.out.println("Name is too long. Please enter a name with a maximum of 20 characters.");
            this.score -= 1;
        }
		// 2
        if (this.mobile.length() != 10 && this.mobile.matches("\\d+")) {
            System.out.println("Invalid mobile number. Please enter a 10-digit number.");
            this.score -= 1;
        }
		// 3
        if (ch_email && !this.email.matches("(\\w+@\\w+\\.\\w+)?")) {
            System.out.println("Invalid Email address! (Must contain @ and . in that order)");
            this.score -= 1;
        }
		// 4
        if (this.pincode.length() != 6 && this.pincode.matches("\\d+")) {
            System.out.println("Invalid PIN Code. Please enter a 6-digit number.");
            this.score -= 1;
        }

		// Successful Registration OR Input required
		if (ch_email == true && this.score == 4 || ch_email == false && this.score == 3) {
			System.out.printf("%nRegistered USER with the given details successfully!!");
			System.out.printf("%n       Welcome to A-to-Z Online application!!%n%n");
			
			System.out.printf("    User Name: "+ this.username + "%n");
			System.out.printf("       Mobile: "+ this.mobile + "%n");
			System.out.printf("Email address: "+ this.email + "%n");
			System.out.printf("     PIN Code: "+ this.pincode + "%n");	
			System.out.printf("      Address: "+ this.address + "%n");	
			
			return;
		} else {
			this.get_user_details();
		}
	}
}
