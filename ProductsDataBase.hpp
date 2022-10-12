#pragma once
#include <vector>
#include "Product.hpp"
#include <iostream>
class ProductsDataBase
{
public:
std::vector<Product> productsDB;
float economyPhase=1.0;

ProductsDataBase()
{
productsDB.resize(21);
productsDB.at(0)=Product("seeds",907.78*economyPhase);
productsDB.at(1)=Product("apples",206.31*economyPhase);
productsDB.at(2)=Product("oranges",189.81*economyPhase);
productsDB.at(3)=Product("grapes",165.05*economyPhase);
productsDB.at(4)=Product("grain",825.26*economyPhase);
productsDB.at(5)=Product("cows",38.44*economyPhase);
productsDB.at(6)=Product("pigs",84.58*economyPhase);
productsDB.at(7)=Product("coffeeBeans",420.88*economyPhase);
productsDB.at(8)=Product("vegetables",288.84*economyPhase);
productsDB.at(9)=Product("fodder",290.51*economyPhase);
productsDB.at(10)=Product("steak",26.19*economyPhase);
productsDB.at(11)=Product("sausages",78.58*economyPhase);
productsDB.at(12)=Product("eggs",322.93*economyPhase);
productsDB.at(13)=Product("coffeePowder",23.43*economyPhase);
productsDB.at(14)=Product("reinforcedConcrete",192.11*economyPhase);
productsDB.at(15)=Product("bricks",374.85*economyPhase);
productsDB.at(16)=Product("planks",117.47*economyPhase);
productsDB.at(17)=Product("constructionUnits",1.01*economyPhase);
productsDB.at(18)=Product("power",2619.33*economyPhase);
productsDB.at(19)=Product("water",1659.62*economyPhase);
productsDB.at(20)=Product("transport",3238.73*economyPhase);
}

void updateDataBasePrices(std::vector<double> databaseprices)
{
    for(int i=0;i<databaseprices.size();i++)
    {
        productsDB.at(i).setMarketPrice(databaseprices.at(i));
    }
}



};