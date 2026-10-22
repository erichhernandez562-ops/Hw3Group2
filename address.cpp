//implementation code for address struct here

#include "address.h"
#include <string>
using namespace std;

string address::address_info(){
    return "address 1: " + address_line1 + ", address 2: " + address_line2 + ", city: " + city + ", state: " + state + ", zip: " + zip;
}