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
#include <string>

using namespace std; 
int main()
{
	Stock testStock;
	Stock tempStock;
	StockList testList;
	StockPortfolio testPort;
	string ticker;
	char response = A;
	char cont;
	cout << "Welcome to Stock Trackerz !!!" << endl << endl;

	//do while loop that will repeatedly as the user if they want to search for a new stock 
	do
	{
		//reads in the ticker to be pulled from API
		cout << "Please input the ticker for the stock you would like see or press Q to quit: ";
		cin >> ticker;
		ticker = std::toupper(ticker);
		
		if(ticker != "Q")
		{
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

		string url = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=" + ticker + "&apikey=RX87R5FA22ZGOH0Z&datatype=csv";
		const char* http1 = url.c_str();;

		// Download a .zip
		string path = "C:\\Users\\areg.tevanyan\\Desktop\\Stock-Trackerz-master\\ConsoleApplication1\\ConsoleApplication1\\" + ticker + ".csv";
		const char* path_char = path.c_str();

		bool success = http.Download(http1, path_char);
		if (success != true)
		{
			std::cout << http.lastErrorText() << "\r\n";
			return 0;
		}
		std::cout << path_char << "\n";
		std::cout << "OK!" << "\r\n";


		//creates and adds stock to list 
		testStock.UpdateStockInfo(ticker);
		testList.AddToList(ticker);
		cout << endl << endl;
		
		if(testStock.GetName() == "None")
		{
			cout << "Invalid Stock Ticker." << endl;
		}
		else
		{
			//display basic info 
			cout << "Ticker: ";
			testStock.PrintName();
			cout << endl << "The current price is: ";
			testStock.PrintClosePrice();
			std::cout << std::endl << "The high for the day is: ";
			testStock.PrintHighPrice();
			cout << endl << "The low for the day is: ";
			testStock.PrintLowPrice();
			cout << endl << "The current Volume is:	";
			testStock.PrintVolume();
			cout << endl << endl;	
		}

		//add stock to portfolio
		cout << "Would you like to add this stock to your portfolio ?? Y/N" << endl;
		cin >> response;
		response = toupper(response);
		if (response == 'Y')
		{
			int quantity;
			float purchase_Price;

			cout << "How many of these stock do you own?  ";
			cin >> quantity;
			cout << endl << endl << "What was your purchase price?  ";
			cin >> purchase_Price;
			cout << endl << endl;
			testPort.AddToList(ticker, quantity, purchase_Price);

			//shows the gain/loss for the current stock 
			cout << "Your current gain/loss for this stock is: ";
			testStock.PrintStockReturn();
			cout << endl;

			cout << "Your return percentage for this stock is: ";
			testStock.PrintStockPercentage();
			std::cout << std::endl;
		}
			do
			{
				response = A;
				cout << "Would you like to view your portfolio (P), search for another stock (S), or quit (Q)?" << endl;
				cin >> response;
				response = std::toupper(response);
				cout << endl;
			
				if(response == 'P')
				{
					if(testPort.GetSize() == 0)
					{
						cout << "Portfolio empty." << endl << endl;
					}
					else
					{
					//loops through and displays the ticker and price of each stock in the users portfolio
					//also this will calculate the running gain/loss on the entire portfolio
					cout << "Portfolio: " << endl;
					for (int i = 0; i < testPort.GetSize(); i++)
					{
						testStock = testPort.OutputStock(i);
						testStock.PrintName();
						cout << " -------------------------" << endl;
						cout << "Shares: ";
						testStock.PrintPurchaseQuantity();
						cout << endl << "Purchase Price: ";
						testStock.PrintPurchasePrice();
						cout << endl << "Current Price: ";
						testStock.PrintClosePrice();
						cout << endl << "Net Gain/Loss: ";
						cout << ( testStock.GetClosePrice() * testStock.GetPurchaseQuantity() ) 
							- ( testStock.GetPurchasePrice() * testStock.GetPurchaseQuantity() );
						cout << endl << endl;			
					}
					}
				}
				else if(response == 'Q')
				{
					cout << "Thank you for using our program!" << endl;
				}
				else if(response == 'S')
				{
					// Loops back to beginning of program
				}
				else
				{
					cout << "Invalid response. Please enter P, S, or Q." << endl;
				}
			} while(response != 'P' && response != 'S' && response != 'Q');
		} // if(ticker != "Q")
	}while(response != 'Q' && ticker != "Q");

	/*std::cout << "Test 1 - Stock Object" << std::endl;
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
	}*/

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
