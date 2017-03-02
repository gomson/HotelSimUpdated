#include "HotelKT.h"
#include <iostream>
#include <array>
#include <string>

KT::KT()
{

}

void KT::printRooms(std::array<KT, 140> &rooms, const bool firstLast)
{
	bool roomStatus;
	if (firstLast == 1)
	{
		for (int x = 1; x < 70; x++)
		{
			if (rooms[x].available == true)
				roomStatus = 1;
			else
				roomStatus = 0;

			rooms[x].showRoomInfo(roomStatus);
		}
	}
	else {
		for (int x = 70; x < 140; x++) //print out the rooms from 70-140
		{
			if (rooms[x].available == true) // and if the room is available
				roomStatus = 1; //set the roomstatus to true (available)
			else
				roomStatus = 0;

			rooms[x].showRoomInfo(roomStatus);
		}
	}


}
bool KT::checkAvailable(std::array<KT, 140>& rooms, const int roomNum)
{
	if (rooms[roomNum].available == true)
		return true;
	else
		return false;
}

void KT::bookRoom(std::array<KT, 140>& rooms)
{
	std::string gname;
	int roomNum, nights;
	char pets;
	bool bpets;

	std::cout << "\n__Please enter your guest information below__ " << std::endl; std::cin.ignore();
	std::cout << "Guest Name: "; getline(std::cin, gname);
	KT check;
	do {
		std::cout << "Desired Room# : "; std::cin >> roomNum;
		if (check.checkAvailable(rooms, roomNum) == false)
			std::cout << "Sorry. This room is currently booked by another guest." << std::endl;
	} while (check.checkAvailable(rooms, roomNum) == false);
	std::cout << "How many nights will you stay with us? "; std::cin >> nights;
	std::cout << "Will any pets accompany you during your stay? <y/n> "; std::cin >> pets;
	(toupper(pets) == 'Y') ? (bpets = true) : (bpets = false);
	//Update array at point roomNum by setRoomInfo()
	rooms[roomNum].setRoomInfo(gname, roomNum, bpets, nights);
}

void KT::setRoomInfo(std::string gname, int roomNum, bool bpets, int nights)
{
	this->guestName = gname;
	this->m_roomNum = roomNum;
	this->m_pets = bpets;
	this->available = false;
	//price of stay
	if (roomNum >= 120)
		this->priceofStay = 200 * nights;
	else if ((roomNum > 70) && (roomNum < 120))
		this->priceofStay = 150 * nights;
	else
		this->priceofStay = 100 * nights;
	if (bpets == true)
		this->priceofStay += 40;
}

KT::KT(std::array<KT, 140> &rooms)
{
	// Initialize roomsList with room#'s and availability
	for (int it = 0; it < 140; it++)
	{
		rooms[it].m_roomNum = it;
		rooms[it].available = true;
		rooms[it].m_pets = false;
		rooms[it].m_luxury = false;
	}

	//Initialize Room Sizes
	for (int it = 0; it < 70; it++)
		rooms[it].m_bedrooms = 1;
	for (int it = 70; it < 120; it++)
		rooms[it].m_bedrooms = 2;
	for (int it = 120; it < 140; it++)
	{
		rooms[it].m_bedrooms = 4;
		rooms[it].m_luxury = true;
	}
}

void KT::showRoomInfo(const bool roomStatus)
{
	//if statements for string status
	std::string room, pets, luxury;
	(this->m_pets == true) ? (pets = "Yes") : (pets = "No");
	(this->m_luxury == true) ? (luxury = "Yes") : (luxury = "No");
	roomStatus ? (room = "Available") : (room = "Booked");
	//print
	std::cout << "---------------------" << std::endl;
	std::cout << "Room #" << m_roomNum << " |" << room << "|" << std::endl;
	std::cout << "Bedrooms: " << m_bedrooms << std::endl;
	std::cout << "Pets: " << pets << " | Luxury Suite: " << luxury << "\n";
	if (!this->available)
		std::cout << "Guest: " << this->guestName << std::endl;
	if (this->priceofStay > 0)
		std::cout << "Price of stay: $" << this->priceofStay << std::endl;

}