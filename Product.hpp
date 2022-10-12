#pragma once
#include <string>
#include<vector>
class Product
{   
    public:
    Product(){};
    Product(std::string n,double amount):name(n),marketPrice(0),amountProducedPerHour(amount)
    { };
    void setMarketPrice(double mp)
    {
        marketPrice=mp;
    };
    double getMarketPrice()
    {
        return marketPrice;
    };
    double getProducedHourlyValue()
    {return producedHourlyValue;};
    double getAmountProducedPerHour()
    {return amountProducedPerHour;};




    protected:
    std::string name;
    double amountProducedPerHour;
    double marketPrice;
    double producedHourlyValue=marketPrice*amountProducedPerHour;

};

