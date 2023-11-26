/*doesn't work for 0.04
void Money::setStringValue(string input) {
    std::stringstream ss;
    for(char i : input) {
        if(i == '.') {
            ss >> centsAmount;
            centsAmount *= 100;
            ss.clear();
        } else {
            ss << i;
        }
    }
    int64_t temp = 0;
    ss >> temp;
    if(temp < 10) {
        temp *= 10;
    }
    centsAmount += temp;
}*/



//system clock for dates

//constexpr year_month_day specificDate2 = year_month_day(2022y, January, 30d);
//auto specificDate = std::chrono::year{2023}/std::chrono::month{11}/std::chrono::day{22};