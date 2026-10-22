//code for product struct here
#include <string>
#include "product.h"
using namespace std;

string product::product_info() {
    return "Product Name:"+ name + "description:" + description+ "price:" + to_string(price);
}