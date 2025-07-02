#include "../include/mainPage.h"

void MainPage::display() {
	system("cls");
	std::cout << "+==============================+\n";
	std::cout << "|      Welcome to CineMax!     |\n";
	std::cout << "+==============================+\n";
	std::cout << "|    Please select an option:  |\n";
	std::cout << "+------------------------------+\n";
	std::cout << "1. View Cinemas\n";
	std::cout << "2. View Movies\n";
	std::cout << "3. Book Tickets\n";
	std::cout << "4. Add New Cinema\n";
	std::cout << "5. Start Selection Process\n";
	std::cout << "6. Register\n";
	std::cout << "7. Exit\n\n";
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
		pages.selectSeatPageShouldDisplay = true;
		key = 0;
	} else if (key == 4) {
		pages.menuPageShouldDisplay = false;
		pages.addNewCinemaPageShouldDisplay = true;
		key = 0;
	}
	else if (key == 5) {
		pages.menuPageShouldDisplay = false;
		pages.selectCinemaPageShouldDisplay = true;
		key = 0;
	}
	else if (key == 6) {
		pages.menuPageShouldDisplay = false;
		pages.registerPageShouldDisplay = true;
		key = 0;
	}
	else if (key == 7) {
		std::cout << "Thank you for using CineMax!" << std::endl;
		exit(0);
	}
	else if(key >= 8 || key <= 0){
		std::cout << "Invalid option. Please try again." << std::endl;
		return;
	}
}