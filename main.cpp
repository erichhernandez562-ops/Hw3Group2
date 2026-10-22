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
productsFile.ignore(); //removing new line after product count

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




	//add to store and other variables
		
	//print store info after you finish importing info

	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	  // Make a purchase

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
