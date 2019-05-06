#include "StockList.h"

StockList::StockList()
{
}


void StockList::AddToList(std::string tickerName)
{
	Stock newStock;
	newStock.UpdateStockInfo(tickerName);
	list.insert(list.end(), newStock);
}

Stock StockList::SearchForName(std::string searchName)
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

Stock StockList::OutputStock(int position)
{
	return list.at(position);
}