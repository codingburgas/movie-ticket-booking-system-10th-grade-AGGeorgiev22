#include "../include/mainPage.h"

void MainPage::display() {
	loggedUserIsAdmin = credentials::isAdmin;
	system("cls");
	std::cout << "+==============================+\n";
	std::cout << "|      Welcome to CineMax!     |\n";
	std::cout << "+==============================+\n";
	std::cout << "|    Please select an option:  |\n";
	std::cout << "+------------------------------+\n";
	std::cout << "1. View Cinemas\n";
	std::cout << "2. View Movies\n";
	std::cout << "3. Book Tickets\n";
	std::cout << (loggedUserIsAdmin ? "4. Add New Cinema\n" : "");
	std::cout << (loggedUserIsAdmin ? "5. Register\n" : "4. Register\n");
	std::cout << (loggedUserIsAdmin ? "6. Exit\n\n" : "5. Exit\n\n");
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
		pages.selectCinemaPageShouldDisplay = true;
		key = 0;
	} else if (key == 4) {
		if(loggedUserIsAdmin) {
			pages.menuPageShouldDisplay = false;
			pages.addNewCinemaPageShouldDisplay = true;
		}
		else {
			pages.menuPageShouldDisplay = false;
			pages.registerPageShouldDisplay = true;
		}
		key = 0;
	}
	else if (key == 5) {
		if (loggedUserIsAdmin) {
			pages.menuPageShouldDisplay = false;
			pages.registerPageShouldDisplay = true;
		}
		else {
			std::cout << "Thank you for using CineMax!" << std::endl;
			exit(0);
		}
	}
	else if (key == 6 && loggedUserIsAdmin) {
		std::cout << "Thank you for using CineMax!" << std::endl;
		exit(0);
	}
	else if(key >= 8 || key <= 0){
		std::cout << "Invalid option. Please try again." << std::endl;
		return;
	}
}