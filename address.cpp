//implementation code for address struct here

#include "address.h"
#include <string>
using namespace std;

string address::address_info(){
    return "\naddress 1: " + address_line1 + ",\naddress 2: " + address_line2 + "\n, city: " + city + "\n, state: " + state + "\n, zip: " + zip;
}