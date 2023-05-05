#include "Hotel.h"

int main()
{
	Room* pokoj1 = new Room(1, 3400);
	Room* pokoj2 = new Room(2, 6000);
	vector<Room*> pokoje;
	pokoje.push_back(pokoj1);
	pokoje.push_back(pokoj2);
	
	Hotel* hotel = new Hotel("HotelName", pokoje, 3);

	// Pridani guestu do pokoju
	// Polymorfismus [Guest] a [Manager] jako [Person]
	pokoj1->addGuest(new Guest("Pepa", true));
	pokoj1->addGuest(new Guest("Honza", true));
	pokoj2->addGuest(new Guest("Repa"));
	pokoj2->addGuest(new Manager("Lojza", (float)7550.9, "Hotel"));
	pokoj2->addGuest(new Guest("Zdepa"));

	hotel->showInfo();

	// Odstraneni guesta a preskladani pokoje
	cout << "Hotel po odstraneni Pepy, Repy a Honzy: " << endl;
	pokoj1->remGuest(pokoj1->getGuest("Pepa"));
	pokoj1->remGuest(pokoj1->getGuest("Honza"));
	pokoj2->remGuest(pokoj2->getGuest("Repa"));
	hotel->showInfo();

	cout << "Odstraneni hotelu:" << endl;
	delete hotel;

	return 0;
}