#include "../include/viewMovies.h"

void ViewMovies::display() {
	system("cls");
	std::cout << "--------------------------------\n";
	std::cout << "       AVAILABLE MOVIES:\n";
	std::cout << "--------------------------------\n";

	displayMovies(movieData);
}

void ViewMovies::actionHandler(PageHandler& pages) {
	key = 0;
	std::cin >> key;
	if (key == 1) {
		pages.viewMoviesPageShouldDisplay = false;
		pages.menuPageShouldDisplay = true;
	}
	system("cls");
}
