#include "Money.h"
#include <iostream>

using namespace std;

Money::Money() {}

void Money::Init() {
    hryvnia = 0;
    kopiyka = 0;
}

void Money::Read() {
    cin >> hryvnia >> kopiyka;
}

void Money::Display() {
    cout << hryvnia << " " << static_cast<int>(kopiyka) << endl;
}

void Money::ChangeAmount(double amount) {
    hryvnia = static_cast<long>(amount);
    kopiyka = static_cast<unsigned char>((amount - hryvnia) * 100);
}

Money Money::operator+(const Money& other) {
    Money result;
    result.hryvnia = hryvnia + other.hryvnia;
    result.kopiyka = kopiyka + other.kopiyka;
    if (result.kopiyka >= 100) {
        result.hryvnia += 1;
        result.kopiyka -= 100;
    }
    return result;
}

Money Money::operator-(const Money& other) {
    Money result;
    result.hryvnia = hryvnia - other.hryvnia;
    result.kopiyka = kopiyka - other.kopiyka;
    if (result.kopiyka < 0) {
        result.hryvnia -= 1;
        result.kopiyka += 100;
    }
    return result;
}

Money Money::operator*(int multiplier) {
    Money result;
    long totalKopiyky = hryvnia * 100 + kopiyka;
    totalKopiyky *= multiplier;
    result.hryvnia = totalKopiyky / 100;
    result.kopiyka = totalKopiyky % 100;
    return result;
}

Money Money::operator/(int divisor) {
    Money result;
    long totalKopiyky = hryvnia * 100 + kopiyka;
    totalKopiyky /= divisor;
    result.hryvnia = totalKopiyky / 100;
    result.kopiyka = totalKopiyky % 100;
    return result;
}

bool Money::operator==(const Money& other) {
    return hryvnia == other.hryvnia && kopiyka == other.kopiyka;
}

bool Money::operator!=(const Money& other) {
    return !(*this == other);
}

bool Money::operator<(const Money& other) {
    if (hryvnia < other.hryvnia) {
        return true;
    }
    else if (hryvnia == other.hryvnia) {
        return kopiyka < other.kopiyka;
    }
    return false;
}

bool Money::operator>(const Money& other) {
    return !(*this < other || *this == other);
}

Money Money::operator/(double divisor) {
    double amount = hryvnia + kopiyka / 100.0;
    amount /= divisor;
    Money result;
    result.hryvnia = static_cast<long>(amount);
    result.kopiyka = static_cast<unsigned char>((amount - result.hryvnia) * 100);
    return result;
}

Money Money::operator*(double multiplier) {
    double amount = hryvnia + kopiyka / 100.0;
    amount *= multiplier;
    Money result;
    result.hryvnia = static_cast<long>(amount);
    result.kopiyka = static_cast<unsigned char>((amount - result.hryvnia) * 100);
    return result;
}

string Money::toString() {
    // Створення рядка для представлення гривень
    string hryvniaStr = to_string(hryvnia);

    // Перевірка, чи потрібно додати 0 перед копійками, якщо вони менші за 10
    string kopiykaStr;
    if (kopiyka < 10) {
        kopiykaStr = "0" + to_string(kopiyka);
    }
    else {
        kopiykaStr = to_string(kopiyka);
    }

    // Повернення суми у вигляді рядка з розділенням комою
    return hryvniaStr + "," + kopiykaStr;
}

double Money::getAmount() {
    return hryvnia + kopiyka / 100.0;
}

void Money::Discount(int percentage) {
    double discountRate = 1 - (percentage / 100.0);
    double discountedAmount = getAmount() * discountRate;
    ChangeAmount(discountedAmount);
}
