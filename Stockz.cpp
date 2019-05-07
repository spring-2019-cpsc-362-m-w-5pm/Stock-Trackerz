#include <StockPortfolio.h>
#include <iostream>

using namespace std;

int main()
{	
	Stock testStock;
	Stock tempStock;
	StockList testList;
	StockPortfolio testPort;

	cout << "Test 1 - Stock Object" << endl;
	testStock.UpdateStockInfo("MSFT");
	cout << "Ticker: ";
	testStock.PrintName();
	cout << endl << "High Price: ";
	testStock.PrintHighPrice();
	cout << endl << "Test 2 - StockList Search " << endl;
	testList.AddToList("BUTTS");
	tempStock = testList.SearchForName("BUTTS");
	tempStock.PrintName();
	cout << endl << "Test 3 - StockList Output Position" << endl;
	testList.AddToList("TACOS");
	tempStock = testList.OutputStock(1);
	tempStock.PrintName();
	cout << endl << "Test 4 - Portfolio" << endl;
	testPort.AddToList("MSFT", 100, 10.3);
	tempStock = testPort.OutputStock(0);
	cout << "Purchase quantity: ";
	tempStock.PrintPurchaseQuantity();
	cout << endl << "Purchase Price: ";
	tempStock.PrintPurchasePrice();
	cout << endl << "Total cost: ";
	cout << tempStock.GetPurchasePrice() * tempStock.GetPurchaseQuantity();
	cout << endl << "Test 5 - Repeats" << endl;
	for (int i = 0; i < testPort.GetSize(); i++)
	{
		testStock = testPort.OutputStock(i);
		testStock.PrintName();
		testStock.PrintPurchaseQuantity();
		cout << endl;
	}

	testPort.AddToList("TACOS",10,100);
	testPort.AddToList("TACOS",20,100);
	testPort.AddToList("TACOS",30,100);
	testPort.AddToList("TACOS", 40, 100);

	for (int i = 0; i < testPort.GetSize(); i++)
	{
		testStock = testPort.OutputStock(i);
		testStock.PrintName();
		cout << endl;
		testStock.PrintPurchaseQuantity();
		cout << endl;
		testStock.PrintPurchasePrice();
		cout << endl;
	}
}

