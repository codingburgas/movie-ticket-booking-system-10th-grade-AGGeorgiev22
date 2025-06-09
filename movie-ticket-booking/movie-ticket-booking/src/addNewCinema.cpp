#include "../include/addNewCinema.h"

void AddNewCinema::display() {
	system("cls");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "         ADD NEW CINEMA" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Press 1 to return or 0 to continue.\n";
	std::cin >> key;
	if (key != 1) {

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the name of the cinema: ";
		getline(std::cin, cinemaName);
		while (cinemaName.empty()) {
			std::cout << "The cinema name cannot be empty!\n";
			std::cout << "Enter the name of the cinema: ";
			getline(std::cin, cinemaName);
		}

		std::cout << "Enter the city of the cinema: ";
		getline(std::cin, cinemaCity);
		while (cinemaCity.empty()) {
			std::cout << "The cinema's city cannot be empty!\n";
			std::cout << "Enter the city of the cinema: ";
			getline(std::cin, cinemaCity);
		}

		std::cout << "Enter the number of halls in the cinema: ";
		std::cin >> cinemaNumOfHalls;
		while (cinemaNumOfHalls <= 0) {
			std::cout << "The number of halls must be more than 0!\n";
			std::cout << "Enter the number of halls in the cinema: ";
			std::cin >> cinemaNumOfHalls;
		}

		std::cout << "Enter the number of seats in each hall (minimum 25 seats): ";
		std::cin >> cinemaNumOfSeatsPerHall;
		while (cinemaNumOfSeatsPerHall < 25) {
			std::cout << "The number of seats in each hall must be at least 25!\n";
			std::cout << "Enter the number of seats in each hall: ";
			std::cin >> cinemaNumOfSeatsPerHall;
		}

		addCinema(cinemaName, cinemaCity, cinemaNumOfHalls, cinemaNumOfSeatsPerHall);
		key = 1;
	}
}

void AddNewCinema::actionHandler(PageHandler& pages) {
	if (key == 1) {
		pages.addNewCinemaPageShouldDisplay = false;
		pages.menuPageShouldDisplay = true;
	}
}