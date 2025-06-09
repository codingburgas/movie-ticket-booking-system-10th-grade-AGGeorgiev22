#include "../include/viewCinemas.h"

void ViewCinemas::display() {
	system("cls");
	std::cout << "----------------" << std::endl;
	std::cout << "    CINEMAS:" << std::setw(88) << "" << "Enter 1 to go back." << std::endl;
	std::cout << "----------------" << std::endl;
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