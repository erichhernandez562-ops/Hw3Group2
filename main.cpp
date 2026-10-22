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
	ifstream creditCardsFile("credit_cards.txt");
	ifstream peopleFile("people.txt");
	// check if it opens or not
	if (!productsFile.is_open()) {
		cout << "Error opening products.txt" << endl;
		return 1;
	}
	if (!creditCardsFile.is_open()) {
		cout << "Error opening credit_cards.txt" << endl;
		return 1;
	}
	if (!peopleFile.is_open()) {
		cout << "Error opening people.txt" << endl;
		return 1;
	}	








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
