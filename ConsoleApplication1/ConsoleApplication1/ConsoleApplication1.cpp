// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <istream>
#include <CkHttp.h>
#include <CkSocket.h>
#include <CkGlobal.h>
#include "Stock.h"
#include "StockList.h"
#include "StockPortfolio.h"

int main()
{
    std::cout << "Hello World!\n"; 

	CkHttp http;
	CkGlobal glob;
	bool success1 = glob.UnlockBundle("Anything for 30-day trial");
	if (success1 != true) {
		std::cout << glob.lastErrorText() << "\r\n";
		return 0;
	}

	int status = glob.get_UnlockStatus();
	if (status == 2) {
		std::cout << "Unlocked using purchased unlock code." << "\r\n";
	}
	else {
		std::cout << "Unlocked in trial mode." << "\r\n";
	}

	// The LastErrorText can be examined in the success case to see if it was unlocked in
	// trial more, or with a purchased unlock code.
	std::cout << glob.lastErrorText() << "\r\n";


	// Download a .zip
	const char *localFilePath = "C:\\Users\\Alpha\\Documents\\GitHub\\Stock-Trackerz\\ConsoleApplication1\\ConsoleApplication1\\test1.csv";
	bool success = http.Download("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=RSI&apikey=RX87R5FA22ZGOH0Z&datatype=csv", localFilePath);
	if (success != true) {
		std::cout << http.lastErrorText() << "\r\n";
		return 0;
	}
	std::cout << localFilePath << "\n";
	std::cout << "OK!" << "\r\n";

	Stock testStock;
	Stock tempStock;
	StockList testList;
	StockPortfolio testPort;

	std::cout << "Test 1 - Stock Object" << std::endl;
	testStock.UpdateStockInfo("MSFT");
	std::cout << "Ticker: ";
	testStock.PrintName();
	std::cout << std::endl << "High Price: ";
	testStock.PrintHighPrice();
	std::cout << std::endl << "Test 2 - StockList Search " << std::endl;
	testList.AddToList("BUTTS");
	tempStock = testList.SearchForName("BUTTS");
	tempStock.PrintName();
	std::cout << std::endl << "Test 3 - StockList Output Position" << std::endl;
	testList.AddToList("TACOS");
	tempStock = testList.OutputStock(1);
	tempStock.PrintName();
	std::cout << std::endl << "Test 4 - Portfolio" << std::endl;
	testPort.AddToList("MSFT", 100, 10.3);
	tempStock = testPort.OutputStock(0);
	std::cout << "Purchase quantity: ";
	tempStock.PrintPurchaseQuantity();
	std::cout << std::endl << "Purchase Price: ";
	tempStock.PrintPurchasePrice();
	std::cout << std::endl << "Total cost: ";
	std::cout << tempStock.GetPurchasePrice() * tempStock.GetPurchaseQuantity();
	std::cout << std::endl << "Test 5 - Repeats" << std::endl;
	for (int i = 0; i < testPort.GetSize(); i++)
	{
		testStock = testPort.OutputStock(i);
		testStock.PrintName();
		testStock.PrintPurchaseQuantity();
		std::cout << std::endl;
	}

	testPort.AddToList("TACOS", 10, 100);
	testPort.AddToList("TACOS", 20, 100);
	testPort.AddToList("TACOS", 30, 100);
	testPort.AddToList("TACOS", 40, 100);

	for (int i = 0; i < testPort.GetSize(); i++)
	{
		testStock = testPort.OutputStock(i);
		testStock.PrintName();
		std::cout << std::endl;
		testStock.PrintPurchaseQuantity();
		std::cout << std::endl;
		testStock.PrintPurchasePrice();
		std::cout << std::endl;
	}

	system("PAUSE");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
