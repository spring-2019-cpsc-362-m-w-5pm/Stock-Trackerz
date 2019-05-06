#include <StockList.h>
#include <vector>

class StockPortfolio
{
public:
	StockPortfolio();
	void AddToList(std::string tickerName, int quantity, float price);
	Stock SearchForName(std::string searchName);
	Stock OutputStock(int position);

private:
	std::vector<Stock> list;
};