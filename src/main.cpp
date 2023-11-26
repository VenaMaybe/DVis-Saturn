// DVis Saturn Accounting ver 0.1.2

#include <iostream>
#include <string>
#include "Money.h"
#include "Transaction.h"
#include "User.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace std::chrono;

typedef year_month_day ymd;

//Money.h
//Transaction.h
//User.h

// Account tracking
// Investment tracking

int main() {
    
    User u("Vena", "1234");

    u.addTransaction(Transaction(500, ymd(2022y, November, 24d), "Deposit"));
    u.addTransaction(Transaction(3000, ymd(2022y, November, 25d), "Deposit"));
    u.addTransaction(Transaction(-300, ymd(2022y, November, 28d), "Withdrawl"));
    u.addTransaction(Transaction(0.42, ymd(2022y, November, 30d), "Deposit"));

    cout << "User: " << u.getAccountName() << endl;

    for(auto& entry : u) {
        cout << entry.first << "\t" << entry.second.getAmount() << endl;
    }
    

    return 0;
}

//Ask about how do you structure a program!