//code for product struct here
#include <string>
#include "product.h"
using namespace std;

string product::product_info() {
    return "\nProduct Name: " + name + "\n, Description: " + description + "\n, Price: " + to_string(price);
}