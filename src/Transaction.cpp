#include "Transaction.h"

Transaction::Transaction(Money amount, const year_month_day& date, const std::string& note)
    : amount(amount), date(date), note(note) {
    // Implementation of the constructor
}

// Getters
Money Transaction::getAmount() const {
    return amount;
}

year_month_day Transaction::getDate() const {
    return date;
}

std::string Transaction::getNote() const {
    return note;
}

// Setters
void Transaction::setAmount(Money newAmount) {
    amount = newAmount;
}

void Transaction::setDate(const year_month_day& newDate) {
    date = newDate;
}

void Transaction::setNote(const std::string& newNote) {
    note = newNote;
}

// Placeholder for genUniqueId implementation
size_t Transaction::genUniqueId() {
    // Placeholder implementation
    return 0; // Replace with actual ID generation logic
}
