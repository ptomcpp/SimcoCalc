#pragma once
#include "Building.hpp"
#include <vector>
#include "ProductsDataBase.hpp"
#include "Subproduct.hpp"
#include <iostream>

class ProductionBuilding:public Building
{
public:
    ProductionBuilding(){
    };

    
    
    float countCostsOfIncome(int numberOnProductingList)
    {
        float costs{};
        Product ProducingProduct=ProducingList.at(numberOnProductingList);
            int i=0;
            do
            {
        costs+=ProducingProduct.getAmountProducedPerHour()*subProductAmount.at(i)*
        Subproducts.at(i).getMarketPrice();
        i++;
            } while (i<Subproducts.size());
        costs+=workerCost;
        return costs;
    };

    double countProfit(int numberOnProductingList)
    {
        double profit;
        Product ProducingProduct=ProducingList.at(numberOnProductingList);
        profit=ProducingProduct.getAmountProducedPerHour()*ProducingProduct.getMarketPrice()*0.97;
        profit-=countCostsOfIncome(numberOnProductingList);
        return profit;
    };

protected:
std::vector<Product> ProducingList;
std::vector<float> subProductAmount;
std::vector<Product> Subproducts;
};

class WaterReservoir:public ProductionBuilding
{
    public:
    WaterReservoir(ProductsDataBase &database)
    {   name="Water Reservoir";
        ProducingList.push_back(database.productsDB.at(19));
        subProductAmount.push_back(0.2);
        Subproducts.push_back(database.productsDB.at(18));
        setWorkerCosts(345);
        constructionCosts=(4*database.productsDB.at(14).getMarketPrice()+
                        55*database.productsDB.at(15).getMarketPrice()+
                        16*database.productsDB.at(15).getMarketPrice()+
                        database.productsDB.at(17).getMarketPrice())*6;
    }
};

class SlaughterHouse:public ProductionBuilding
{
    public:
    SlaughterHouse(ProductsDataBase &database)
    {  name="Salughter House";
        ProducingList.push_back(database.productsDB.at(10));
    ProducingList.push_back(database.productsDB.at(11));
                setWorkerCosts(414);
    constructionCosts=(4*database.productsDB.at(14).getMarketPrice()+
    55*database.productsDB.at(15).getMarketPrice()+
    16*database.productsDB.at(15).getMarketPrice()+
    database.productsDB.at(17).getMarketPrice())*6;
    }

    void StakeProduction(ProductsDataBase &database)
    {
        
        subProductAmount.push_back(0.125);
        Subproducts.push_back(database.productsDB.at(5));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));

    }
        void SausageProduction(ProductsDataBase &database)
    {
        
        subProductAmount.push_back(0.0625);
        Subproducts.push_back(database.productsDB.at(6));
        subProductAmount.push_back(0.1);
        Subproducts.push_back(database.productsDB.at(20));
    }
};

class PowerPlant:public ProductionBuilding
{   
    public:
    PowerPlant(ProductsDataBase &database)
    { 
        name="Power Plant";
        ProducingList.push_back(database.productsDB.at(18));
        setWorkerCosts(414);
        subProductAmount.push_back(0);
        Subproducts.push_back(database.productsDB.at(0));    
        constructionCosts=(4*database.productsDB.at(14).getMarketPrice()+
        55*database.productsDB.at(15).getMarketPrice()+
        16*database.productsDB.at(15).getMarketPrice()+
        database.productsDB.at(17).getMarketPrice())*15;
    }
};

class Mill:public ProductionBuilding
{
    public:
    Mill(ProductsDataBase &database)
    {  name="Mill";
    ProducingList.push_back(database.productsDB.at(13));
    ProducingList.push_back(database.productsDB.at(9));
                setWorkerCosts(380);
    constructionCosts=(4*database.productsDB.at(14).getMarketPrice()+
    55*database.productsDB.at(15).getMarketPrice()+
    16*database.productsDB.at(15).getMarketPrice()+
    database.productsDB.at(17).getMarketPrice())*8;
    }

    void CoffePowderProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(10);
        Subproducts.push_back(database.productsDB.at(7));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));
    }
        void FodderProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(0.5);
        Subproducts.push_back(database.productsDB.at(9));
        subProductAmount.push_back(10);
        Subproducts.push_back(database.productsDB.at(4));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));
    }
};

class Farm:public ProductionBuilding
{
    public:
    Farm(ProductsDataBase &database)
    {  name="Farm";
    ProducingList.push_back(database.productsDB.at(12));
    ProducingList.push_back(database.productsDB.at(5));
    ProducingList.push_back(database.productsDB.at(6));
                setWorkerCosts(138);
    constructionCosts=(4*database.productsDB.at(14).getMarketPrice()+
    55*database.productsDB.at(15).getMarketPrice()+
    16*database.productsDB.at(15).getMarketPrice()+
    database.productsDB.at(17).getMarketPrice())*3;
    }

    void EggsProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(0.4);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(0.5);
        Subproducts.push_back(database.productsDB.at(4));
        subProductAmount.push_back(0.1);
        Subproducts.push_back(database.productsDB.at(20));
    }
        void CowsProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(16);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(12);
        Subproducts.push_back(database.productsDB.at(9));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));
    }
        void PigsProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(4);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(4);
        Subproducts.push_back(database.productsDB.at(9));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));
    }
};

class Plantation:public ProductionBuilding
{
    public:
    Plantation(ProductsDataBase &database)
    {  name="Plantation";
    setWorkerCosts(104);
    ProducingList.push_back(database.productsDB.at(0));
    ProducingList.push_back(database.productsDB.at(1));
    ProducingList.push_back(database.productsDB.at(2));
    ProducingList.push_back(database.productsDB.at(3));
    ProducingList.push_back(database.productsDB.at(4));
    ProducingList.push_back(database.productsDB.at(7));
    ProducingList.push_back(database.productsDB.at(8));
    constructionCosts=(4*database.productsDB.at(14).getMarketPrice()+
    55*database.productsDB.at(15).getMarketPrice()+
    16*database.productsDB.at(15).getMarketPrice()+
    database.productsDB.at(17).getMarketPrice())*2;
    }

    void SeedsProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(0.1);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(0.1);
        Subproducts.push_back(database.productsDB.at(20));
    }
    void ApplesProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(3);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(0));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));
    }
    void OrangesProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(3);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(0));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));
    }
    void GrapesProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(4);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(0));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(20));
    }
    void GrainProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(0.5);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(0));
        subProductAmount.push_back(0.5);
        Subproducts.push_back(database.productsDB.at(20));
    }
    void CoffeBeansProduction(ProductsDataBase &database)
    {
        subProductAmount.push_back(0.5);
        Subproducts.push_back(database.productsDB.at(19));
        subProductAmount.push_back(1);
        Subproducts.push_back(database.productsDB.at(0));
        subProductAmount.push_back(0.1);
        Subproducts.push_back(database.productsDB.at(20));
    }
      
};