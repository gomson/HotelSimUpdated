#pragma once
#include <string>
#include <array>
class KT
{
private:
	//data
	std::string guestName;
	int m_roomNum, m_bedrooms;
	bool m_pets, m_luxury;
	bool available;
	double priceofStay;

public:
	//constructors
	KT::KT();
	KT::KT(std::array<KT, 140> &rooms);

	//Accessors
	void showRoomInfo(const bool roomStatus);
	void printRooms(std::array<KT, 140> &rooms, const bool firstLast);
	bool checkAvailable(std::array<KT, 140> &rooms, const int roomNum);

	//mutators
	void bookRoom(std::array<KT, 140> &rooms);
	void setRoomInfo(std::string gname, int roomNum, bool bpets, int nights);

};