#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using namespace std;
int main()
{
	Store store1;
	// store store1;
	//import from text files

	// ifstream productsFile("products.txt");
	// ifstream creditCardsFile("credit_cards.txt");
	// ifstream peopleFile("people.txt");
	// // check if it opens or not
	// if (!productsFile.is_open()) {
	// 	cout << "Error opening products.txt" << endl;
	// 	return 1;
	// }
	// if (!creditCardsFile.is_open()) {
	// 	cout << "Error opening credit_cards.txt" << endl;
	// 	return 1;
	// }
	// if (!peopleFile.is_open()) {
	// 	cout << "Error opening people.txt" << endl;
	// 	return 1;
	// }


// to make sure the code actaully works 
// Create address
    address address1;
    address1.address_line1 = "111 Hollywood Lane";
    address1.address_line2 = "";
    address1.city = "Auburn ";
    address1.state = "Alabama";
    address1.zip = "35209";

    // Create credit card
    credit_card card1;
    card1.cc_number = 12345678;
    card1.limit = 5000.00;
    card1.current_balance = 1500.00;

    // Create customer
    Person customer1("John Wick", "123-456-7890", address1, card1);

    // Add customer to store
    store1.add_customer(customer1);

    // Create product
    product item1;
    item1.name = "Laptop";
    item1.description = "A high-performance laptop with 16GB RAM and 512GB SSD.";
    item1.price = 1000.00;

    // Add product to store
    store1.add_product(item1);





	//add to store and other variables
		
	//print store info after you finish importing info

	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	  // Make a purchase
    store1.make_purchase(customer1, item1, 1);

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
