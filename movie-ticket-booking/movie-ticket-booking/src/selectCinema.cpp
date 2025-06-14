#include "../include/selectCinema.h"

void SelectCinema::display() {
	cinemaData = fetchCinemasFromJSON();
	fetchLastCinemaID(lastCinemaId);

	system("cls");
	std::cout << "------------------------" << std::endl;
	std::cout << "    SELECT A CINEMA:" << std::endl;
	std::cout << "------------------------" << std::endl;
	displayCinemas(cinemaData);

	std::cout << "Last cinema id is: " << lastCinemaId << std::endl;
	std::cout << "User selected cinema id: " << UserChoices::cinemaID << std::endl;

	if (!cinemaSelected) {
		std::cout << "Enter the cinema ID to select a cinema: ";
		std::cin >> UserChoices::cinemaID;
	}

	if (UserChoices::cinemaID <= lastCinemaId) {
		std::cout << "Cinema selected successfully!" << std::endl;
		cinemaSelected = true;
	}
	else {
		std::cout << "Invalid cinema ID. Please try again." << std::endl;
		return;
	}

	std::cout << "Enter 1 to continue: ";
	std::cin >> key;
}

void SelectCinema::actionHandler(PageHandler& pages) {
	if (key == 1) {
		pages.selectCinemaPageShouldDisplay = false;
		pages.menuPageShouldDisplay = true;
	}
}