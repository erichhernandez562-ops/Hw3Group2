//code for transaction struct here
#include <string>
#include "transaction.h"
#include "person.h"
using namespace std;

string transaction::transaction_info()
{
    string info=  " transaction_number: " + to_string(transaction_number) + "customer: " + customer.person_info() + " purchased_item: " + purchased_item.product_info() + " quantity: " + to_string(quantity);
    return info;
}
