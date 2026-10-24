//code for transaction struct here
#include <string>
#include "transaction.h"
#include "person.h"
using namespace std;

string transaction::transaction_info()
{
    string info=  "transaction #: " + to_string(transaction_number) + "\ncustomer:\n " + customer.person_info() + "\nproduct:\n " + purchased_item.product_info() + "\nquantity: " + to_string(quantity);
    return info;
}
