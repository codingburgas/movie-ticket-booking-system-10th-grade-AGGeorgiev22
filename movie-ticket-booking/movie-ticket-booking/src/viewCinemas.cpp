#include "../include/viewCinemas.h"

void ViewCinemas::display() {
	system("cls");
	displayCinemas(cinemaData);
}

void ViewCinemas::actionHandler(PageHandler& pages) {
	key = 0;
	std::cin >> key;
	if (key == 1) {
		pages.viewCinemasPageShouldDisplay = false;
		pages.menuPageShouldDisplay = true;
	}
	system("cls");
}