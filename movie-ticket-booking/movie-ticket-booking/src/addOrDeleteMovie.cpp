#include "../include/addOrDeleteMovie.h"

void AddOrDeleteMovie::display() {
	system("cls");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "          MANAGE MOVIES" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Press 1 to add a new movie, 2 to delete a movie or 0 to go back.\n";
	std::cin >> key;

	if (key == 1) { // Displays the add a movie section

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the title of the movie: ";
		getline(std::cin, movieTitle);
		while (movieTitle.empty()) {
			std::cout << "The movie title cannot be empty!\n";
			std::cout << "Enter the title of the movie: ";
			getline(std::cin, movieTitle);
		}

		std::cout << "Enter the language of the movie: ";
		getline(std::cin, language);
		while (language.empty()) {
			std::cout << "The movie's language cannot be empty!\n";
			std::cout << "Enter the language of the movie: ";
			getline(std::cin, language);
		}

		std::cout << "Enter the genre of the movie: ";
		getline(std::cin, genre);
		while (genre.empty()) {
			std::cout << "The movie's genre cannot be empty!\n";
			std::cout << "Enter the genre of the movie: ";
			getline(std::cin, genre);
		}

		std::cout << "Enter the release date of the movie: ";
		getline(std::cin, releaseDate);
		while (releaseDate.empty()) {
			std::cout << "The movie's release date cannot be empty!\n";
			std::cout << "Enter the release date of the movie: ";
			getline(std::cin, releaseDate);
		}

		std::cout << "Enter the silver ticket price for the movie: ";
		std::cin >> silverPrice;
		std::cout << "Enter the gold ticket price for the movie: ";
		std::cin >> goldPrice;
		std::cout << "Enter the platinum ticket price for the movie: ";
		std::cin >> platinumPrice;

		std::cout << "How many show times will the movie have?\n";
		std::cin >> numOfShows;

		std::cout << "Enter the show times for the movie: ";
		for (int i = 0; i < numOfShows; i++) {
			std::cin >> showtimeInput;
			showtimes.push_back(showtimeInput);
		}

		addMovie(movieTitle, language
			, genre, releaseDate
			, silverPrice, goldPrice
			, platinumPrice, showtimes);
	}
	else if (key == 2){ // Displays the delete a movie sections
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Enter the movie ID you wish to delete: ";
		getline(std::cin, movieID);
		while (movieID.empty()) {
			std::cout << "The movie ID cannot be empty!\n";
			std::cout << "Enter the movie ID you wish to delete: ";
			getline(std::cin, movieID);
		}

		deleteMovie(movieID);
	}

	std::cout << "To go back enter 0: ";
	std::cin >> key;
}

void AddOrDeleteMovie::actionHandler(PageHandler& pages) {
	if (key == 0) {
		pages.manageMoviesPageShouldDisplay = false;
		pages.menuPageShouldDisplay = true;
	}
}