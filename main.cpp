#include "ProductionBuildings.hpp"
#include <iostream>
#include "Product.hpp"
#include "ProductsDataBase.hpp"
#include <vector>
#include <iomanip>
void GUI(ProductsDataBase);
int main_menu();
ProductsDataBase uploadDataBaseData();


int main()
{
ProductsDataBase productsDataB=uploadDataBaseData();
GUI(productsDataB);

    return 0;
}





ProductsDataBase uploadDataBaseData()
{
ProductsDataBase productsDataB;

std::vector<double> productPrices;

productPrices.resize(21);
                //seeds, apples, oranges, grapes. grains
productPrices={  0.17,   1.7,    1.79,    2.1,    0.497,
                //cows   pigs   coffebeans,  vegetables,  fodder
                102,    35.5,         0.64,      1.89,       7.7,
                //steaks  sausages  eggs  coffepowder
                34,       9.4,    1.10,   29.75,
                //RC      bricks    planks  CU
                270,        3.6,    17.5,   4125,
                //power  water transport
                0.175,  0.298,     0.4};
productsDataB.updateDataBasePrices(productPrices);
return productsDataB;
}
void GUI(ProductsDataBase productsDataB)
{
switch(main_menu())
{
case 1: 
{

std::cout<<std::endl<<"WATER RESERVOIR"<<std::endl;
WaterReservoir waterReservoir(productsDataB);
waterReservoir.maxHourlyIncome=waterReservoir.countProfit(0);
std::cout<<"profit from water reservoir:"<<std::setprecision(6)<<waterReservoir.maxHourlyIncome<<"$"<<std::endl;
std::cout<<"Building price:"<<waterReservoir.getConstructionCosts()<<std::endl;
std::cout<<"rate of daily return:  "<<2400*waterReservoir.maxHourlyIncome/waterReservoir.getConstructionCosts()<<"%"<<std::endl;

std::cout<<std::endl<<"SLAUGHTER HOUSE"<<std::endl;
SlaughterHouse SlaughterHouseStake(productsDataB);
SlaughterHouseStake.StakeProduction(productsDataB);
SlaughterHouseStake.maxHourlyIncome=SlaughterHouseStake.countProfit(0);
std::cout<<"profit from stake:"<<SlaughterHouseStake.countProfit(0)<<std::endl;
SlaughterHouse SlaughterHouseSausages(productsDataB);
SlaughterHouseSausages.SausageProduction(productsDataB);
std::cout<<"profit from sausage:"<<SlaughterHouseSausages.countProfit(1)<<std::endl;
if(SlaughterHouseStake.maxHourlyIncome<SlaughterHouseSausages.countProfit(1))SlaughterHouseStake.maxHourlyIncome=SlaughterHouseSausages.countProfit(1);

std::cout<<"profit from slaughter:"<<std::setprecision(6)<<SlaughterHouseStake.maxHourlyIncome<<"$"<<std::endl;
std::cout<<"Building price:"<<SlaughterHouseStake.getConstructionCosts()<<std::endl;
std::cout<<"rate of daily return:  "<<2400*SlaughterHouseStake.maxHourlyIncome/waterReservoir.getConstructionCosts()<<"%"<<std::endl;

std::cout<<std::endl<<"POWER PLANT"<<std::endl;
PowerPlant PowerPlantPower(productsDataB);
PowerPlantPower.maxHourlyIncome=PowerPlantPower.countProfit(0);
std::cout<<"profit from power: "<<PowerPlantPower.maxHourlyIncome<<std::endl;

std::cout<<"Building price:"<<PowerPlantPower.getConstructionCosts()<<std::endl;
std::cout<<"rate of daily return:  "<<2400*PowerPlantPower.maxHourlyIncome/PowerPlantPower.getConstructionCosts()<<"%"<<std::endl;

std::cout<<std::endl<<"MILL"<<std::endl;
Mill MillCoffePowder(productsDataB);
MillCoffePowder.CoffePowderProduction(productsDataB);
std::cout<<"profit from coffe powder:"<<MillCoffePowder.countProfit(0)<<std::endl;
Mill MillFodder(productsDataB);
MillFodder.FodderProduction(productsDataB);
std::cout<<"profit from fodder: "<<MillFodder.countProfit(0)<<std::endl;

std::cout<<std::endl<<"FARM"<<std::endl;
Farm EggsProduction(productsDataB);
EggsProduction.EggsProduction(productsDataB);
std::cout<<"profit from eggs "<<EggsProduction.countProfit(0)<<std::endl;
Farm CowsProduction(productsDataB);
CowsProduction.CowsProduction(productsDataB);
std::cout<<"profit from cows "<<CowsProduction.countProfit(1)<<std::endl;
Farm PigsProduction(productsDataB);
PigsProduction.PigsProduction(productsDataB);
std::cout<<"profit from pigs "<<PigsProduction.countProfit(2)<<std::endl;

std::cout<<std::endl<<"PLANTATION"<<std::endl;
Plantation SeedsProduction(productsDataB);
SeedsProduction.SeedsProduction(productsDataB);
std::cout<<"profit from seeds "<<SeedsProduction.countProfit(0)<<std::endl;

Plantation ApplesProduction(productsDataB);
ApplesProduction.ApplesProduction(productsDataB);
std::cout<<"profit from apples "<<ApplesProduction.countProfit(1)<<std::endl;

Plantation OrangesProduction(productsDataB);
OrangesProduction.OrangesProduction(productsDataB);
std::cout<<"profit from oranges "<<OrangesProduction.countProfit(2)<<std::endl;

Plantation GrapesProduction(productsDataB);
GrapesProduction.GrapesProduction(productsDataB);
std::cout<<"profit from grapes "<<GrapesProduction.countProfit(3)<<std::endl;

Plantation GrainProduction(productsDataB);
GrainProduction.GrainProduction(productsDataB);
std::cout<<"profit from grain "<<GrainProduction.countProfit(4)<<std::endl;

Plantation CoffeBeansProduction(productsDataB);
CoffeBeansProduction.CoffeBeansProduction(productsDataB);
std::cout<<"profit from CoffeBeans "<<CoffeBeansProduction.countProfit(5)<<std::endl;

}break;
default: std::cout<<"wrong answer";break;
}      
}


int main_menu()
{
std::cout<<"Hi, what would you like to do?"<<std::endl;
std::cout<<"1)check profitability of buildings"<<std::endl;
std::cout<<"2)something else"<<std::endl;
int main_menu_choose;
std::cin>>main_menu_choose;
return main_menu_choose;
}
