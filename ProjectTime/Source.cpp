#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <ctime>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <ctype.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	time_t startTime = time(0);
	char shortMessage[1000];
	cout << "Please insert short message to be shown : ";
	cin.getline(shortMessage, sizeof shortMessage);
	cout << "Hold (shift + e) to terminate later." << endl;
	system("pause");
	while (true)
	{
		//Clears scrren
		sleep_for(milliseconds(250));
		system("cls");

		time_t now = time(0);
		string dateTime = ctime(&now);
		cout << "Start Time	: " << ctime(&startTime) << endl;
		cout << "Current Time	: " << dateTime << endl;
		int timeDifference = difftime(now, startTime);
		int hour = timeDifference / 3600;
		int minute = ((timeDifference % 3600) / 60) - (hour * 60);
		int second = (timeDifference % 3600) - (minute * 60);
		cout << "Time Absent	: " << hour << " : " << minute << " : " << second << endl << endl;
		cout << "Message Left	: " << shortMessage << endl << endl << endl;

		cout << "	BBBBBBBB		RRRRRRRR		BBBBBBBB" << endl;
		cout << "	BBB    BBB		RRR    RRR		BBB    BBB" << endl;
		cout << "	BBB    BBB		RRR    RRR		BBB    BBB" << endl;
		cout << "	BBBBBBBBB		RRRRRRRRR		BBBBBBBBB" << endl;
		cout << "	BBB    BBB		RRR  RRR		BBB    BBB" << endl;
		cout << "	BBB    BBB		RRR   RRR		BBB    BBB" << endl;
		cout << "	BBBBBBBBB		RRR    RRR		BBBBBBBBB" << endl;

		if (GetAsyncKeyState('E') & 0x8000)
		{
			break;
		}
	}

	system("cd /");
	system("rundll32.exe user32.dll, LockWorkStation");

	//Exits the program
	system("pause");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, 0);
	return 0;
}