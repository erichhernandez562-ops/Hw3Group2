//code for product struct here
#include <string>
#include "product.h"
using namespace std;

string product::product_info() {
    return "Name: " + name + "\nDescription: " + description + "\nPrice: " + to_string(price);
}