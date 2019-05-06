#include <Stock.h>
#include <vector>

class StockList
{
public:
	StockList();
	void AddToList(std::string tickerName);
	Stock SearchForName(std::string searchName);
	Stock OutputStock(int position);

private:
	std::vector<Stock> list;
};

