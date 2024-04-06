#ifndef MONEY_H
#define MONEY_H

#include <string>

using namespace std;

class Money {
private:
    long hryvnia;
    int kopiyka;

public:
    Money();
    void Init();
    void Read();
    void Display();
    void ChangeAmount(double amount);
    Money operator+(const Money& other);
    Money operator-(const Money& other);
    Money operator*(int multiplier);
    Money operator/(int divisor);
    bool operator==(const Money& other);
    bool operator!=(const Money& other);
    bool operator<(const Money& other);
    bool operator>(const Money& other);
    Money operator/(double divisor);
    Money operator*(double multiplier);
    string toString();
    double getAmount();
    void Discount(int percentage);
};

#endif
