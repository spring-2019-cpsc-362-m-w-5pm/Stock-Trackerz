#include <Stock.h>

Stock::Stock()
{
	name = "None";
	openPrice = 0;
	highPrice = 0;
	lowPrice = 0;
	closePrice = 0;
	volume = 0;
	lastUpdated = "Never";
	purchasePrice = 0;
	purchaseQuantity = 0;
}
void Stock::UpdateStockInfo(std::string tickerName)
{
	name = tickerName;
	std::string fileName;
	std::string temp;
	fileName = "daily_" + tickerName + ".csv";
	std::ifstream inFile;
	inFile.open(fileName);

	if (!inFile)
	{
		std::cout << "STOCK DATA UNAVAILABLE" << std::endl;
	}
	else
	{
		std::getline(inFile, temp);

		std::getline(inFile, lastUpdated, ',');
		std::getline(inFile, temp, ',');
		openPrice = stof(temp);
		std::getline(inFile, temp, ',');
		highPrice = stof(temp);
		std::getline(inFile, temp, ',');
		lowPrice = stof(temp);
		std::getline(inFile, temp, ',');
		closePrice = stof(temp);
		std::getline(inFile, temp, ',');
		volume = stof(temp);

		inFile.close();
	}
}
void Stock::SetPurchaseQuantity(int quantity)
{
	purchaseQuantity = quantity;	
}
void Stock::SetPurchasePrice(float price)
{
	purchasePrice = price;
}
std::string Stock::GetName()
{
	return name;
}
float Stock::GetOpenPrice()
{
	return openPrice;
}
float Stock::GetHighPrice()
{
	return highPrice;
}
float Stock::GetLowPrice()
{
	return lowPrice;
}
float Stock::GetClosePrice()
{
	return closePrice;
}

double Stock::GetVolume()
{
	return volume;
}
std::string Stock::GetLastUpdated()
{
	return lastUpdated;
}
int Stock::GetPurchaseQuantity()
{
	return purchaseQuantity;
}
float Stock::GetPurchasePrice()
{
	return purchasePrice;
}
void Stock::PrintName()
{
	std::cout << name;
}
void Stock::PrintOpenPrice()
{
	std::cout << openPrice;
}
void Stock::PrintHighPrice()
{
	std::cout << highPrice;
}
void Stock::PrintLowPrice()
{
	std::cout << lowPrice;
}
void Stock::PrintClosePrice()
{
	std::cout << closePrice;
}
void Stock::PrintVolume()
{
	std::cout << volume;
}
void Stock::PrintLastUpdated()
{
	std::cout << lastUpdated;
}
void Stock::PrintPurchaseQuantity()
{
	std::cout << purchaseQuantity;
}
void Stock::PrintPurchasePrice()
{
	std::cout << purchasePrice;
}