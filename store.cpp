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
