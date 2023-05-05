#include "Hotel.h"

Room::~Room()
{
	for (auto elem : this->guests)
	{
		delete elem;
	}
}

void Room::remGuest(Person* guest)
{
	int i = 0;

	for (auto elem : this->guests)
	{
		if (elem == guest)
		{
			delete elem;
			elem = nullptr;
			this->guests.erase(this->guests.begin() + i);
			return;
		}

		i++;
	}
}

void Room::addGuest(Person* guest)
{
	this->guests.push_back(guest);
}

void Room::printGuests()
{
	if (this->guests.empty())
	{
		cout << "   >    \033[31mEmpty\033[0m" << endl;
		return;
	}

	for (auto elem : this->guests)
	{
		cout << "   >   ";
		elem->showInfo();

	}
}

Person* Room::getGuest(string name)
{
	for (auto elem : this->guests)
	{
		if (elem->getName() == name)
			return elem;
	}

	return nullptr;
}


void Room::showInfo() {
	cout << "\033[32m" << "[Room] number: " << this->number << " \tprice: " << this->price << "\tguests: " << this->getGuestsCount() << "\033[0m" << endl;
}

