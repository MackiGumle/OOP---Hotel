#include "Hotel.h"

Hotel::~Hotel()
{
	for (auto elem : this->rooms)
	{
		delete elem;
	}
}

void Hotel::showInfo() {
	cout << "[Hotel] name: " << this->name << " \trating: " << this->rating << endl;
	for (auto elem : this->rooms)
	{
		elem->showInfo();
		elem->printGuests();
	}
	cout << endl;
}

void Hotel::setRating(int rating) {
	this->rating = rating;
}

void Hotel::addRoom(Room* room) {
	this->rooms.push_back(room);
}


