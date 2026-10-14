#include "store.h"

Store::Store()
{
  num_customers_ = 0;
  num_products_ = 0;
  num_transactions_ = 0;
}

void Store::num_customers(int customer_count)
{
  num_customers_ = customer_count;
}

int Store::num_customers()
{
  return num_customers_;
}

void Store::num_products(int product_count)
{
    num_products_ = product_count;
}

int Store::num_products()
{
    return num_products_;
}

void Store::num_transactions(int transaction_count)
{
  num_transactions_ = transaction_count;
}

int Store::num_transactions()
{
    return num_transactions_;
}

bool Store::add_customer(Person customer)
{
    if (num_customers_ >= 100)
{
  return false;
}

customers_ [num_customers_] = customer;
num_customers_++;

return true;
}

bool Store::update_customer(int index, Person customer)
{
    if (index < 0 || index >= num_customers_)
{
  return false;
}

if (customers_[index].name() != customer.name())
{
  return false;
}

customers_[index] = customer;

return true;
}

Person Store::get_customer(int index)
{
    if (index < 0 || index >= num_customers_)
{
    return Person();
}

return customers_[index];
}

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

product Store::get_product(int index)
{
    if (index < 0 || index >= num_products_)
{
    return product();
}

return products_[index];
}
