#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime> // using to give rand a diff starting seed for each run

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

	ifstream productsFile("products.txt");
	ifstream creditCardsFile("credit_card.txt"); //Butterfield - fixed file name
	ifstream peopleFile("people.txt");
	// check if it opens or not
	if (!productsFile.is_open()) {
		cout << "Error opening products.txt" << endl;
		return 1;
	}
	if (!creditCardsFile.is_open()) {
		cout << "Error opening credit_card.txt" << endl; //Butterfield - fixed file name
		return 1;
	}
	if (!peopleFile.is_open()) {
		cout << "Error opening people.txt" << endl;
		return 1;
	}	

// product count of products.txt
int product_count;
productsFile >> product_count;
//removing new line after product count
productsFile.ignore(); 

// read products
for (int index = 0; index < product_count; index++)
	{
		product item;
		//name and desc may have spaces
		getline(productsFile, item.name);
		getline(productsFile, item.description);

		// product price
		productsFile >> item.price;
		productsFile.ignore();

		// store product
		store1.add_product(item);
	}

// people and addresses
	//max 100 customers
Person people[100];
	int people_count;
	//removing new line after read people count
	peopleFile >> people_count;
	peopleFile.ignore();

	// get peoples info
		for (int index = 0; index < people_count; index++)
		{
			string person_name;
			string person_phone;
			address person_address;

			getline(peopleFile, person_name);
			getline(peopleFile, person_phone);
			getline(peopleFile, person_address.address_line1);
			getline(peopleFile, person_address.address_line2);
			getline(peopleFile, person_address.city);
			getline(peopleFile, person_address.state);
			getline(peopleFile, person_address.zip);

	//will assign correct card after
			credit_card empty_card;
			empty_card.cc_number = 0;
			empty_card.limit = 0.0;
			empty_card.current_balance = 0.0;
	// creating person and storing it in temp array
			people[index] = Person(person_name, person_phone, person_address, empty_card);
		}

	//store card owner names and credit cards seperately
	string card_names[100];
	credit_card cards[100];

	int card_count;

	//read number of records and ignore newline after count
	creditCardsFile >> card_count;
	creditCardsFile.ignore();

	// read all cards owners names
	for (int index = 0; index < card_count; index++)
		{
			getline(creditCardsFile, card_names[index]);

			creditCardsFile >> cards[index].cc_number;
			creditCardsFile >> cards[index].limit;
			creditCardsFile >> cards[index].current_balance;
			creditCardsFile.ignore(); //remove newline after balance
		}

	//now going to match each person with their credit card by name
	for (int person_index = 0; person_index < people_count; person_index++)
		{
			bool card_found = false;
			for (int card_index = 0; card_index < card_count; card_index++)
				{
					if (people[person_index].name() == card_names[card_index])
					{
						//give that person their matching card
						people[person_index].person_credit_card(cards[card_index]);
						card_found = true;
						break;
					}
				}
			if (card_found)
			{
				//add completed customer to Store
				store1.add_customer(people[person_index]);
			}
			else
			{
				cout << "No credit card found for: " <<people[person_index].name() << endl;
			}
		}




	//add to store and other variables
		
	//print store info after you finish importing info

	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	  // Make a purchase

	//random # of purchase attempts
	// make sure cust and prod loaded
	if (store1.num_costers() == 0 || store1.num_products() == 0)
	{
		cout << "Cannot make purchases because Store data is missing." << endl;
		return 1;
	}

	//use current time so random choices change
	srand(time(0));
	// Generate 11-99 purchase attempts
	int transaction_attempts = rand() % 89 + 11;
	for (int attempt = 0; attempt < transaction_attempts; attempt++)
		{
			//randomly select stored cust and prod
			int customer_index = rand() % store1.num_customers();
			int product_index = rand() % store1.num_products();
			//Generate purch amount between 1 through 10
			int quantity = rand() % 10 + 1;

			person selected_customer = store1.get_customer(customer_index);
			product selected_product = store1.get_product(product_index);
			//attempt purchase
			bool purchase_successful = store1.make_purchase(selected_customer, selected_product, quantity);
			if (purchase_successful)
			{
				cout << "Successful transaction!" << endl;
				cout << "Transaction Details:" << endl;
				// store successful transaction
				cout << store1.get_transaction(store1.num_transactions() - 1).transaction_info() << endl;
			}
			else
			{
				cout << "Unsuccessful transation!" << endl;
				cout << "Transaction Details:" << endl;
				cout << "Person:" << endl;
				cout << selected_customer.person_info() << endl;
				cout << "Product:" << endl;
				cout << selected_product.product_info() << endl;
				cout << "Purchase Quantity: " << quantity << endl;
			}
			cout << endl;
		}

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
