#include "../include/mainPage.h"

void MainPage::display() {
	std::cout << "Welcome to CineMax!" << std::endl;
	std::cout << "Please select an option:" << std::endl;
	std::cout << "1. View Cinemas" << std::endl;
	std::cout << "2. View Movies" << std::endl;
	std::cout << "3. Book Tickets" << std::endl;
	std::cout << "4. Cancel Booking" << std::endl;
	std::cout << "5. Exit" << std::endl << std::endl;
	std::cout << "Enter your choice: ";
}

void MainPage::actionHandler(PageHandler& pages) {
	std::cin >> key;
	if (key == 1) {
		pages.menuPageShouldDisplay = false;
		pages.viewCinemasPageShouldDisplay = true;
		key = 0;
	} else if (key == 2) {
		pages.menuPageShouldDisplay = false;
		pages.viewMoviesPageShouldDisplay = true;
		key = 0;
	} else if (key == 3) {
		pages.menuPageShouldDisplay = false;
		pages.bookTicketsPageShouldDisplay = true;
		key = 0;
	} else if (key == 4) {
		key = 0;
		return;
	} else if (key == 5) {
		std::cout << "Thank you for using CineMax!" << std::endl;
		exit(0);
	}

	system("cls");

	if(key >= 6 || key <= 0){
		system("CLS");
		std::cout << "Invalid option. Please try again." << std::endl;
	}
}