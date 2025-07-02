#include "../include/selectCinema.h"

void SelectCinema::display() {
	cinemaData = fetchCinemasFromJSON();
	fetchLastCinemaID(lastCinemaId);

	system("cls");
	std::cout << "------------------------" << std::endl;
	std::cout << "    SELECT A CINEMA:" << std::endl;
	std::cout << "------------------------" << std::endl;
	displayCinemas(cinemaData);

	if (!cinemaSelected) {
		std::cout << "Enter the cinema ID to select a cinema: ";
		std::cin >> UserChoices::cinemaID;
	}

	if (UserChoices::cinemaID <= lastCinemaId) {
		credentials::email.empty() ? userRegistered = false : userRegistered = true;
			
		if(userRegistered == false){
			std::cout << "You need to register before you can choose a cinema location." << std::endl;
			std::cout << "Enter 'R' to continue to the register page: ";
			std::cin >> continueToRegister;

			if (continueToRegister == 'R' || continueToRegister == 'r') {
				key = 2;
				return;
			}
		}
		else {
			std::cout << "Cinema selected successfully!" << std::endl;
			cinemaSelected = true;
		}
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
		pages.selectCinemaHallPageShouldDisplay = true;
	}
	else if(key == 2){
		pages.selectCinemaPageShouldDisplay = false;
		pages.registerPageShouldDisplay = true;
	}
}