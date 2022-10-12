#pragma once
#include <string>
#include <vector>
#include "Product.hpp"
class Building
{
    public:
Building(){};
    void setWorkerCosts(double cost)
    {
        workerCost=cost;
    };
    double getConstructionCosts()
    {
        return constructionCosts;
    }
double maxHourlyIncome;
protected:
std::string name;

double workerCost;
double constructionCosts;
};



  