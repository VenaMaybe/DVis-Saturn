#include "User.h"
#include <stdexcept>

using std::string;

// Constructor

User::User(string accountNameInput, string rawPasswordInput) {
    setAccountName(accountNameInput);
    setPassword(rawPasswordInput); // Ensure this is secure as mentioned above
    // Initialize other members as needed
}

// Interface

void User::addTransaction(const Transaction& t) {
    auto [iter, inserted] = transactions.emplace(t.getDate(), t);

    if (inserted) {
        // Transaction was successfully inserted
        accountValue += iter->second.getAmount();  // Assuming += is valid for Money type
    } else {
        // Handle the case where the transaction was not inserted (e.g., a duplicate date)
    }
}

// Range-based for loop on map of transaction
std::map<year_month_day, Transaction>::iterator User::begin() {
    return transactions.begin();
}

std::map<year_month_day, Transaction>::iterator User::end() {
    return transactions.end();
}


// Setters

void User::setAccountName(string accountNameInput) {
    accountName = accountNameInput;
}

void User::setPassword(string rawPasswordInput) {
    // Hash the password with a salt
    // Store the hashed password

    // For now
    rawPassword = rawPasswordInput;
}

// Getters

Money User::getAccountValue() {
    return accountValue;
}

Transaction User::getTransactionAtDate(year_month_day date) {
    auto it = transactions.find(date);
    if (it != transactions.end()) {
        return it->second;
    } else {
        // Handle the case where the transaction doesn't exist
        throw std::runtime_error("Transaction not found for the given date");
    }
}

string User::getAccountName() {
    return accountName;
}