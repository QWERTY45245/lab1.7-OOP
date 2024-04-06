#include <iostream>
#include "Goods.h"
#include<Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Goods goods;
    goods.Read();

    cout << "≤нформац≥€ про товар:\n";
    goods.Display();

    // ќтриманн€ вартост≥ товару
    Money total = goods.CalculateTotal();
    cout << "¬арт≥сть товару: " << total.toString() << endl;

    // «м≥на ц≥ни товару
    double newPrice;
    cout << "¬вед≥ть нову ц≥ну товару: ";
    cin >> newPrice;
    goods.ChangePrice(newPrice);

    // «м≥на к≥лькост≥ товару
    int newQuantity;
    cout << "¬вед≥ть нову к≥льк≥сть товару: ";
    cin >> newQuantity;
    goods.ChangeQuantity(newQuantity);

    // ќтриманн€ вартост≥ товару п≥сл€ зм≥ни
    total = goods.CalculateTotal();
    cout << "¬арт≥сть товару п≥сл€ зм≥н: " << total.toString() << endl;

    // ”ц≥нка товару
    int daysExpired;
    cout << "¬вед≥ть к≥льк≥сть дн≥в простроченн€: ";
    cin >> daysExpired;
    goods.DiscountProduct(daysExpired);
    cout << "÷≥на п≥сл€ уц≥нки: " << goods.CalculateTotal().toString() << endl;

    return 0;
}