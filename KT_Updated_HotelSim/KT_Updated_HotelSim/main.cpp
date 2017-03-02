#include <iostream>
#include <array>
#include <string>
#include "HotelKT.h"

int main()
{
	using namespace std;
	std::array<KT, 140> roomsList;
	//first we initialize our array
	KT Initialize(roomsList);
	cout << "\n\t WELCOME TO THE KRUSTY TOWERS HOTEL!  " << endl;
	cout << "\t ----------------------------------" << endl;
	cout << " \t| WHERE WE SHALL NEVER DENY A GUEST|" << endl;
	cout << "\t| EVEN THE MOST RIDICULOUS REQUEST |" << endl;
	cout << "\t ----------------------------------\n\n";

	KT access; 
	bool exitProgram = false;
	while (exitProgram == false)
	{
		cout << "	 ___________________________\n";
		cout << "\t|1. Book a room		    |" << endl;
		cout << "\t|2. List all rooms	    |" << endl;
		cout << "\t|Q. Quit		    | " << endl;
		cout << "\t|___________________________|\n";
		char input = 'v';
		cout << "\t"; cin >> input;
		switch (toupper(input))
		{
		case '1':
		{
			access.bookRoom(roomsList);
			break;
		}
		case '2':
		{
			bool firstORlast;
			cout << "Enter '1' to print out rooms [1-69]\n OR Enter '0' to print out rooms [70-139] ";
			cin >> firstORlast;
			KT print;
			print.printRooms(roomsList, firstORlast);
		}
		break;
		case '3':

			break;
		case '4':
			break;
		case 'Q':
			exitProgram = true;
			break;
		}
	}
	return 0;
}
