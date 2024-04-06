#include "Goods.h"
#include <iostream>
#include<Windows.h>

using namespace std;

Goods::Goods() {}

void Goods::Init() {
    name = "";
    date = "";
    price.Init();
    quantity = 0;
    invoiceNumber = 0;
}

void Goods::Read() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Введіть найменування товару: ";
    cin >> name;
    cout << "Введіть дату оформлення: ";
    cin >> date;
    cout << "Введіть ціну товару (гривні та копійки через пробіл): ";
    price.Read();
    cout << "Введіть номер накладної: ";
    cin >> invoiceNumber;
    cout << "Введіть кількість одиниць товару: ";
    cin >> quantity;
}

void Goods::Display() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Найменування товару: " << name << endl;
    cout << "Дата оформлення: " << date << endl;
    cout << "Ціна товару: " << price.toString() << endl;
    cout << "Кількість одиниць товару: " << quantity << endl;
    cout << "Номер накладної: " << invoiceNumber << endl;
}

void Goods::ChangePrice(double newPrice) {
    price.ChangeAmount(newPrice);
}

void Goods::ChangeQuantity(int newQuantity) {
    quantity = newQuantity;
}

Money Goods::CalculateTotal() {
    Money total;
    total = price * quantity;
    return total;
}

string Goods::toString() {
    return CalculateTotal().toString();
}

void Goods::DiscountProduct(int daysExpired) {
    double discountRate = 1 - (daysExpired * 0.01);
    double discountedPrice = price.getAmount() * discountRate;
    ChangePrice(discountedPrice);
}
