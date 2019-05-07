#include <StockList.h>
#include <vector>

class StockPortfolio
{
public:
	StockPortfolio();
	void AddToList(std::string tickerName, int quantity, float price);
	Stock SearchForName(std::string searchName);
	Stock OutputStock(int position);
	int GetSize();

private:
	std::vector<Stock> list;
	int size;
};