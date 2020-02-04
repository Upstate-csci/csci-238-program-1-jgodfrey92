/********
 Author: Joshua Godfrey
 Program: Money class - program assignment #1
 Due Date: 2/3/2019
 Purpose: This program handles conversion between different currency formats
 ********/
#include "money.h"

// convert current currency values to a string
string Money::toString() {
    return to_string(hundreds) + " hundred(s) " + to_string(tens) + " ten(s) " + to_string(fives) + " five(s) " + to_string(ones) + " one(s) " + to_string(quarters) + " quarter(s) " + to_string(dimes) + " dime(s) " + to_string(nickels) + " nickel(s) " + to_string(cents) + " penny/ies";
}

// format amount as a local currency and return

string Money::toCurrency(double amount) {
    stringstream ss;

    ss << "$" << left << setfill('0') << setw(4) << amount;
    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
	cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
	convertChange();

    return toString() + " = " + toCurrency(total);
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    cin >> total;
    double temp = total;
    convertFloat(total);

    return toCurrency(temp) + " = " + toString();
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
  return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
	double paidAmount, cost, changeAmount;
	double temp;
	cin >> paidAmount >> cost;
	temp = paidAmount;
	changeAmount = paidAmount - cost;

	convertFloat(changeAmount);
	stringstream ss;
	ss.precision(2);
	ss << fixed << "change back on $" << temp << " for a purchase of $" << cost << " is $" << changeAmount << " which is " << toString();

	return ss.str();
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    double cost, changeAmount;
    string temp;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents >> cost;
    temp = toString();
	convertChange();

	changeAmount = total - cost;
	convertFloat(changeAmount);

	stringstream ss;
	ss.precision(2);
	ss << fixed << "change back on " << temp << " for a purchase of $" << cost << " is $" << changeAmount << " which is " + toString();
	return ss.str();
}

void Money::convertFloat(double amount)
{
		//This converts the double amount into pennies and then grabs each denomination in descending order
		amount *= 100;
	    long int temp = amount; //couldn't quite get casting to work so I am just assigning the type I need to a new variable instead
	    hundreds = temp / 10000;
	    temp %= 10000;
	    tens = temp / 1000;
	    temp %= 1000;
	    fives = temp / 500;
	    temp %= 500;
	    ones = temp / 100;
	    temp %= 100;
	    quarters = temp / 25;
	    temp %= 25;
	    dimes = temp / 10;
	    temp %= 10;
	    nickels = temp / 5;
	    temp %= 5;
	    cents = temp;
}

void Money::convertChange()
{
	
	total = (hundreds * 100) + (tens * 10) + (fives * 5) + ones + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (cents * 0.01);
}

