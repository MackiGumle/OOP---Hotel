#include "Hotel.h"

int main()
{
	Room pokoj(1, 100);
	Guest* pepa = new Guest("Pepa");
	Guest* repa = new Guest("Repa");
	Guest* zdepa = new Guest("Zdepa");
	Guest* jozo= new Guest("Jozo");

	pokoj.addGuest(pepa);
	pokoj.addGuest(repa);
	pokoj.addGuest(zdepa);
	pokoj.addGuest(jozo);
	
	pokoj.printGuests();

	pokoj.remGuest(zdepa);

	pokoj.printGuests();

	return 0;
}