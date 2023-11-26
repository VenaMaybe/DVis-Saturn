#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Money.h"
#include <chrono>
#include <string>

using namespace std::chrono;
class Transaction {
public:
    Transaction(Money amount, const year_month_day& date, const std::string& note = "");
    
    // Getters
    Money getAmount() const;
    year_month_day getDate() const;
    std::string getNote() const;

    // Setters
    void setAmount(Money newAmount);
    void setDate(const year_month_day& newDate);
    void setNote(const std::string& newNote);

private:
    Money amount;
    std::chrono::year_month_day date;
    std::string note;

    size_t genUniqueId(); // Implement Later
};
#endif