#ifndef GOODS_H
#define GOODS_H

#include <string>
#include "Money.h"

using namespace std;

class Goods {
private:
    string name;
    string date;
    Money price;
    int quantity;
    int invoiceNumber;

public:
    Goods();
    void Init();
    void Read();
    void Display();
    void ChangePrice(double newPrice);
    void ChangeQuantity(int newQuantity);
    Money CalculateTotal();
    string toString();
    void DiscountProduct(int daysExpired);
};

#endif
