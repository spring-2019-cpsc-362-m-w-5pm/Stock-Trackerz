#include "StockPortfolio.h"

StockPortfolio::StockPortfolio()
{
}


void StockPortfolio::AddToList(std::string tickerName, int quantity, float price)
{
	Stock newStock;
	newStock.UpdateStockInfo(tickerName);
	newStock.SetPurchaseQuantity(quantity);
	newStock.SetPurchasePrice(price);
	list.insert(list.end(), newStock);
}

Stock StockPortfolio::SearchForName(std::string searchName)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (searchName == list.at(i).GetName())
		{
			return list.at(i);
		}

		Stock NotFound;
		return NotFound;
	}
}

Stock StockPortfolio::OutputStock(int position)
{
	return list.at(position);
}