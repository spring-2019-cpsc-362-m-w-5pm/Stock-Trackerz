#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Stock
{
public:
	Stock();
	void UpdateStockInfo(std::string tickerName);
	void SetPurchaseQuantity(int quantity);
	void SetPurchasePrice(float price);
	std::string GetName();
	float GetOpenPrice();
	float GetHighPrice();
	float GetLowPrice();
	float GetClosePrice();
	double GetVolume();
	std::string GetLastUpdated();
	int GetPurchaseQuantity();
	float GetPurchasePrice();
	void PrintName();
	void PrintOpenPrice();
	void PrintHighPrice();
	void PrintLowPrice();
	void PrintClosePrice();
	void PrintVolume();
	void PrintLastUpdated();
	void PrintPurchaseQuantity();
	void PrintPurchasePrice();
	void PrintStockReturn();
	void PrintStockEquity();
	void PrintStockPercentage();

private:
	std::string name;
	float openPrice;
	float highPrice;
	float lowPrice;
	float closePrice;
	float stock_Equity;
	float stock_Return;
	double volume;
	std::string lastUpdated;
	int purchaseQuantity;
	float purchasePrice;
	float stock_Percent;
};
