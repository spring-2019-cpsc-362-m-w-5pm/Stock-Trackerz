// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <CkHttp.h>
#include <CkSocket.h>
#include <CkGlobal.h>

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
	const char *localFilePath = "C:\\users\\Alpha\\Desktop\\test.csv";
	bool success = http.Download("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=RX87R5FA22ZGOH0Z&datatype=csv", localFilePath);
	if (success != true) {
		std::cout << http.lastErrorText() << "\r\n";
		return 0;
	}
	std::cout << localFilePath << "\n";
	std::cout << "OK!" << "\r\n";
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
