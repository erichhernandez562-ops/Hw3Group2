//implementation code for credit_card struct here
#include "credit_card.h"
#include <string>
using namespace std;

bool credit_card::make_purchase(double purchase_amount) {
    if(purchase_amount >0 && current_balance +purchase_amount <= limit) { 
        current_balance += purchase_amount;
        return true;
    } else {
        return false;
    }
}
bool credit_card::make_payment(double payment_amount) {
    if(payment_amount >0&& payment_amount <= current_balance) {
        current_balance -= payment_amount;
        return true;
    } else {
        return false;
 
   }

}
string credit_card::credit_card_info() {
    string info = "\nCredit Card Number: " + to_string(cc_number) + "\n Credit card Limit: " + to_string(limit) + "\nCurrent Balance: " + to_string(current_balance) ;
    return info;

}
