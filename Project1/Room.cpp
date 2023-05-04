#include "Hotel.h"


void Room::remGuest(Guest* guest)
{
	int i = 0;

	for (auto elem : this->guests)
	{
		if (elem == guest)
			this->guests.erase(this->guests.begin() + i);

		i++;
	}
}

void Room::addGuest(Guest* guest)
{
	this->guests.push_back(guest);
}

void Room::printGuests()
{
	for (auto elem : this->guests)
		elem->showInfo();

}
