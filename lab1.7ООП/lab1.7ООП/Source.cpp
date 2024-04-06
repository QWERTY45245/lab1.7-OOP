#include <iostream>
#include "Goods.h"
#include<Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Goods goods;
    goods.Read();

    cout << "���������� ��� �����:\n";
    goods.Display();

    // ��������� ������� ������
    Money total = goods.CalculateTotal();
    cout << "������� ������: " << total.toString() << endl;

    // ���� ���� ������
    double newPrice;
    cout << "������ ���� ���� ������: ";
    cin >> newPrice;
    goods.ChangePrice(newPrice);

    // ���� ������� ������
    int newQuantity;
    cout << "������ ���� ������� ������: ";
    cin >> newQuantity;
    goods.ChangeQuantity(newQuantity);

    // ��������� ������� ������ ���� ����
    total = goods.CalculateTotal();
    cout << "������� ������ ���� ���: " << total.toString() << endl;

    // ������ ������
    int daysExpired;
    cout << "������ ������� ��� ������������: ";
    cin >> daysExpired;
    goods.DiscountProduct(daysExpired);
    cout << "ֳ�� ���� ������: " << goods.CalculateTotal().toString() << endl;

    return 0;
}