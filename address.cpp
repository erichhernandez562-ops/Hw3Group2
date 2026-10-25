//implementation code for address struct here

#include "address.h"
#include <string>
using namespace std;

string address::address_info(){
    return "Address:\n " + address_line1 + "\n" + address_line2 + "\n" + city + "\n" + state + "\n" + zip;
}
