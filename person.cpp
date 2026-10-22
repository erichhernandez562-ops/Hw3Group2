//code for person class here
#include <string>
#include "person.h"
#include "address.h"
#include "credit_card.h"

using namespace std;

Person::Person(string name, string phone, address address, credit_card credit)  {
name_ = name;
phone_ = phone;
person_address_ = address;
person_credit_card_ = credit;

}
Person::Person() {
    name_ = "";
    phone_ = "";
    person_address_ = address();
    person_credit_card_ = credit_card();
}

void Person::name(string name) {
    name_ = name;
}
string Person::name() {
    return name_;
}


void Person::phone(string phone) {
    phone_ = phone;
}
string Person::phone() {
    return phone_;

}


void Person::person_address(address address) {
    person_address_ = address;
}
address Person::person_address() {
    return person_address_;
}


void Person::person_credit_card(credit_card credit) {
    person_credit_card_ = credit;
}
credit_card Person::person_credit_card() {
    return person_credit_card_;
}

string Person::person_info() {
    return "Name: " + name_ + ", Phone: " + phone_ + ", Address: " + person_address_.address_info() + ", Credit Card: " + person_credit_card_.credit_card_info();
}
