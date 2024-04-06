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
    cout << "������ ������������ ������: ";
    cin >> name;
    cout << "������ ���� ����������: ";
    cin >> date;
    cout << "������ ���� ������ (����� �� ������ ����� �����): ";
    price.Read();
    cout << "������ ����� ��������: ";
    cin >> invoiceNumber;
    cout << "������ ������� ������� ������: ";
    cin >> quantity;
}

void Goods::Display() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "������������ ������: " << name << endl;
    cout << "���� ����������: " << date << endl;
    cout << "ֳ�� ������: " << price.toString() << endl;
    cout << "ʳ������ ������� ������: " << quantity << endl;
    cout << "����� ��������: " << invoiceNumber << endl;
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
