#include "pch.h"
#include "StockList.h"

StockList::StockList()
{
	size = 0;
}


void StockList::AddToList(std::string tickerName)
{
	if (SearchForName(tickerName).GetName() == "None")
	{
		Stock newStock;
		newStock.UpdateStockInfo(tickerName);
		list.insert(list.end(), newStock);
		size++;
	}
	else
	{
		SearchForName(tickerName).UpdateStockInfo(tickerName);
	}
}

Stock StockList::SearchForName(std::string searchName)
{
	for (int i = 0; i < size; i++)
	{
		if (searchName == list.at(i).GetName())
		{
			return list.at(i);
		}
	}

	Stock NotFound;
	return NotFound;
}

Stock StockList::OutputStock(int position)
{
	return list.at(position);
}

int StockList::GetSize()
{
	return size;
}