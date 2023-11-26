#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include "Transaction.h"

class User {
private:
    std::string accountName;
    std::string rawPassword;

    Money accountValue = 0;
    std::map<year_month_day, Transaction> transactions; // List of transactions here

    // Setters
    void setAccountName(std::string accountNameInput);
    void setPassword(std::string rawPasswordInput); // How do I set this and deal with passwords for financial accounts securely?
public:
    // Constructor
    User(std::string accountNameInput, std::string rawPasswordInput); // Set name and password, should be in constructor?
    
    // Ranged-based for loop
    std::map<year_month_day, Transaction>::iterator begin();
    std::map<year_month_day, Transaction>::iterator end();

    // Interface
    void addTransaction(const Transaction& t); // Remember this also has to update account value to the transaciton total

    // Getters
    Money getAccountValue();
    Transaction getTransactionAtDate(year_month_day date);
    std::string getAccountName();
};

#endif