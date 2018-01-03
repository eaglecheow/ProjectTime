#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <ctime>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main()
{
	time_t startTime = time(0);
	
	while (true)
	{
		time_t now = time(0);
		string dateTime = ctime(&now);
		cout << "Start Time	: " << ctime(&startTime) << endl;
		cout << "Current Time	: " << dateTime << endl;
		int timeDifference = difftime(now, startTime);
		int hour = timeDifference / 3600;
		int minute = ((timeDifference % 3600) / 60) - (hour * 60);
		int second = (timeDifference % 3600) - (minute * 60);
		cout << "Time absent	: " << hour << " : " << minute << " : " << second << endl << endl;
		cout << "Owner has went for a short break. BRB" << endl;
		sleep_for(milliseconds(250));
		system("cls");
	}

	//Exits the program
	system("pause");
	return 0;
}