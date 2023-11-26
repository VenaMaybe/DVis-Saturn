#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include <string>

class Money {
private:
    int64_t centsAmount;
public:
    Money(double amount);
    Money& operator=(double amount);
    Money& operator+=(const Money& amount);
    friend std::ostream& operator<<(std::ostream& os, const Money& money);

    // Getters
    int64_t getCents() const;
    int64_t getDollars() const;
    std::string getStringValue() const;    

    // Setters
    void setCents(int64_t input);
    void setDollars(int64_t input);
    void setStringValue(std::string input);
};

#endif