#include "store.h"

// empty Store with counts set to 0
Store::Store()
{
  num_customers_ = 0;
  num_products_ = 0;
  num_transactions_ = 0;
}

// set customer count to customers stored
void Store::num_customers(int customer_count)
{
  num_customers_ = customer_count;
}
//return number currently stored
int Store::num_customers()
{
  return num_customers_;
}
// set # products curr stored
void Store::num_products(int product_count)
{
    num_products_ = product_count;
}
// return numb prod curr store
int Store::num_products()
{
    return num_products_;
}
// # of successful transactions currently stored
void Store::num_transactions(int transaction_count)
{
  num_transactions_ = transaction_count;
}
// return # succ trans currently stored
int Store::num_transactions()
{
    return num_transactions_;
}
// customer mang:
// return false if array is full
bool Store::add_customer(Person customer)
{
    if (num_customers_ >= 100)
{
  return false;
}
// current count = next available index
customers_ [num_customers_] = customer;
num_customers_++;

return true;
}
// replace exist cust with update copy
//index needs to be valid and customer names need to match as well
bool Store::update_customer(int index, Person customer)
{
    if (index < 0 || index >= num_customers_)
{
  return false;
}
// prevent customer from replacing a diff customer
if (customers_[index].name() != customer.name())
{
  return false;
}

customers_[index] = customer;

return true;
}
// return cust @ request index
// return empty person if index = invalid
Person Store::get_customer(int index)
{
    if (index < 0 || index >= num_customers_)
{
    return Person();
}

return customers_[index];
}
// search customer by name
// return matching index, -1 if no match found
int Store::find_customer(Person cust)
{
  for (int index = 0; index < num_customers_; index++)
{
  if (customers_[index].name() == cust.name())
{
  return index;
}
}

return -1;
}
//product management
// return false if array is full
bool Store::add_product(product item)
{
  if (num_products_ >= 100)
{
  return false;
}
  products_[num_products_] = item;
  num_products_++;

  return true;
}
//return product at requested index
// empty product if index invalid
product Store::get_product(int index)
{
    if (index < 0 || index >= num_products_)
{
    return product();
}

return products_[index];
}
//transaction management
//record successful transaciton in next open position
//return false if array is full
bool Store::add_transaction(transaction new_transaction)
{
  if (num_transactions_ >= 100)
{
  return false;
}

transactions_[num_transactions_] = new_transaction;
num_transactions_++;

return true;
}
//return transaction @ requested index
//return empty transaction if invalid
transaction Store::get_transaction(int index)
{
    if (index < 0 || index >= num_transactions_)
{
    return transaction();
}

return transactions_[index];
}
// purchase processsing
//attempt to charge stored customers credit card
//successful purchase updates customer stored balance and creates transaction. failed = nothing
bool Store::make_purchase(Person customer, product item, int amount)
{
  // reject inval quant or full transaction array
  if (amount <= 0 || num_transactions_ >= 100)
{
    return false;
}
// find cutomers position in Store
int customer_index = find_customer(customer);

if (customer_index == -1)
{
    return false;
}
// copy stored customer and credit card to update without changing the store too soon
Person updated_customer = customers_[customer_index];
credit_card card = updated_customer.person_credit_card();

// calculate cost of requested quantity
double purchase_total = item.price * amount;
// object checks whether sufficient credit remains and update balance if it does
if (!card.make_purchase(purchase_total))
{
  return false;
}
// save changed card back into the customer, then replace customer stored in Store
updated_customer.person_credit_card(card);
update_customer(customer_index, updated_customer);
// builds record of successful purchase
transaction new_transaction;
new_transaction.transaction_number = num_transactions_ + 1;
new_transaction.customer = updated_customer;
new_transaction.purchased_item = item;
new_transaction.quantity = amount;
//save completed transaction and return result
return add_transaction(new_transaction);
}
//Store output
//combine formatted information for every stored product
string Store:: product_info()
{
      string info = "Products:\n";
      for (int index = 0; index < num_products_; index++)
{
      info += products_[index].product_info();
      info += "\n";
}

return info;
}
// combine formatted information for every stored customer
string Store::customer_info()
{
  string info = "Customers:\n";

  for (int index = 0; index < num_customers_; index++)
{
    info += customers_[index].person_info();
    info += "\n";
}

return info;
}
// combine formatted information for every successful transaction recorded by Store
string Store::transaction_info()
{
    string info = "All Transactions:\n";
    for (int index = 0; index < num_transactions_; index++)
{
    info += transactions_[index].transaction_info();
    info += "\n";
}

return info;
}
// build complete Store report by reusing customer, product, and transaction output functions
string Store::store_info()
{
    string info;

  info += customer_info();
  info += "\n";
  info += product_info();
  info += "\n";
  info += transaction_info();

  return info;
}

// return only completed transations for one customer, names used to identify matching customers
string Store::purchase_history(Person customer)
{
  string info = "Purchase History for " + customer.name() + ":\n";

  for (int index = 0; index < num_transactions_; index++)
{
  if (transactions_[index].customer.name() == customer.name())
{
  info += transactions_[index].transaction_info();
  info += "\n";
}
}

  return info;
}
