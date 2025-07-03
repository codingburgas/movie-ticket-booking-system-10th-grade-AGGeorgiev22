#include "../include/viewMovies.h"

void ViewMovies::display() {
	movieData = fetchMoviesFromJson();
	system("cls");
	std::cout << "--------------------------------\n";
	std::cout << "        AVAILABLE MOVIES:\n";
	std::cout << "--------------------------------\n";

	displayMovies(movieData);

	std::cout << "To go back enter 1.\n";
	std::cout << "If you wish to search for a movie enter 2.\n";
	std::cin >> key;
}

void ViewMovies::searchMovies() {
	system("cls");
	std::cout << "--------------------------------\n";
	std::cout << "       SEARCH FOR A MOVIE\n";
	std::cout << "--------------------------------\n\n";

	std::cout << "How would you like to search for a movie?\n";
	std::cout << "1. By title\n";
	std::cout << "2. By language\n";
	std::cout << "3. By genre\n";
	std::cout << "4. By release date\n";
	std::cout << "Enter your choice: ";
	std::cin >> searchChoice;
	
	displayCategorisedSearch();
	std::cout << "\nTo go back enter 1: ";
	std::cin >> key;

}

void ViewMovies::displayCategorisedSearch() {
	if (searchChoice == 1) {
		std::cout << "Search for a movie by the title.\n";
		std::cout << "Enter your search:";
		std::cin >> userSearch;
		displayMoviesByField("title", userSearch);
		return;
	}
	else if (searchChoice == 2) {
		std::cout << "Search for a movie by the language.\n";
		std::cout << "Enter your search:";
		std::cin >> userSearch;
		displayMoviesByField("language", userSearch);
		return;
	}
	else if (searchChoice == 3) {
		std::cout << "Search for a movie by the genre.\n";
		std::cout << "Enter your search:";
		std::cin >> userSearch;
		displayMoviesByField("genre", userSearch);
		return;
	}
	else if (searchChoice == 4) {
		std::cout << "Search for a movie by the release date (format: YYYY-MM-DD).\n";
		std::cout << "Enter your search:";
		std::cin >> userSearch;
		displayMoviesByField("releaseDate", userSearch);
		return;
	}
}

void ViewMovies::actionHandler(PageHandler& pages) {
	if (key == 1) {
		pages.viewMoviesPageShouldDisplay = false;
		pages.menuPageShouldDisplay = true;
	}
	else if (key == 2) {
		searchMovies();
	}
}
