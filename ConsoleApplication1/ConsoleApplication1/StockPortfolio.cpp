#include "pch.h"
#include "StockPortfolio.h"

StockPortfolio::StockPortfolio()
{
	size = 0;
}


void StockPortfolio::AddToList(std::string tickerName, int quantity, float price)
{
	Stock newStock;
	if (SearchForName(tickerName).GetName() == "None")
	{
		newStock.UpdateStockInfo(tickerName);
		newStock.SetPurchaseQuantity(quantity);
		newStock.SetPurchasePrice(price);
		list.insert(list.end(), newStock);
		size++;
	}
	else
	{
		SearchForName(tickerName).UpdateStockInfo(tickerName);
		SearchForName(tickerName).SetPurchasePrice(price);
		SearchForName(tickerName).SetPurchaseQuantity(quantity);
	}
}

Stock StockPortfolio::SearchForName(std::string searchName)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (searchName == list.at(i).GetName())
		{
			return list.at(i);
		}
	}

	Stock NotFound;
	return NotFound;
}

Stock StockPortfolio::OutputStock(int position)
{
	return list.at(position);
}

int StockPortfolio::GetSize()
{
	return size;
}