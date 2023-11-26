#include "Money.h"

#include <iomanip>  // For setprecision
#include <sstream>  // For stringstream
#include <cmath>    // For modf()

using std::string;

Money::Money(double amount = 0) {
    // Output only stream
    std::ostringstream ss;

    // Ensures that the string has exactly two decimal places
    ss << amount;
    string amountStr = ss.str();

    // Find the position of the decimal point
    size_t dotPos = amountStr.find('.');

    // Check if there are more than two digits after the decimal point
    if (dotPos != string::npos && amountStr.size() > dotPos + 3) {
        throw std::invalid_argument("Fractional cents are not implemented.");
    }

    centsAmount = static_cast<int64_t>(amount * 100);
}

Money& Money::operator=(double amount) {
    // Output only stream
    std::ostringstream ss;

    // Ensures that the string has exactly two decimal places
    ss << amount;
    string amountStr = ss.str();

    // Find the position of the decimal point
    size_t dotPos = amountStr.find('.');

    // Check if there are more than two digits after the decimal point
    if (dotPos != string::npos && amountStr.size() > dotPos + 3) {
        throw std::invalid_argument("Fractional cents are not implemented.");
    }

    centsAmount = static_cast<int64_t>(amount * 100);
    return *this;
}

Money& Money::operator+=(const Money& amount) {
    this->centsAmount += amount.centsAmount;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    // Format the output as desired
    os << money.getStringValue();
    return os;
}

int64_t Money::getCents() const {
    return centsAmount;
}

void Money::setCents(int64_t input) {
    centsAmount = input;
}

int64_t Money::getDollars() const {
    return centsAmount / 100;
}

void Money::setDollars(int64_t input) {
    centsAmount = input * 100;
}

string Money::getStringValue() const {
    // Input and output stream
    std::stringstream ss;
    ss << "$" << getDollars() << "." << std::setfill('0') 
        << std::setw(2) << centsAmount % 100; 
    return ss.str();
}

void Money::setStringValue(string input) {
    size_t dotPos = input.find('.');
    int64_t dollars = 0;
    int64_t cents = 0;

    // Parse dollars
    if (dotPos != string::npos) {
        dollars = std::stoll(input.substr(0, dotPos));
    }

    // Parse cents
    if (dotPos != string::npos && dotPos + 1 < input.size()) {
        cents = std::stoll(input.substr(dotPos + 1));
        // Adjust for the number of digits in cents
        if (input.size() - dotPos - 1 == 1) {
            cents *= 10; // Only one digit for cents, multiply by 10
        }
    } else {
        // No cents part, so the whole input is dollars
        dollars = std::stoll(input);
    }

    // Combine dollars and cents into centsAmount
    centsAmount = dollars * 100 + cents;
}