package A2ZOnapp;

public class Main
{
	public static void main(String[] args) {
		// New user
		regd_user user = new regd_user();
		// Get user details, validate them and register user
		user.get_user_details();
		
		// Browse Shop Products
        product_info.display_product_details();
        
        // Checkout
        cust_billing.checkout();
	}
}
