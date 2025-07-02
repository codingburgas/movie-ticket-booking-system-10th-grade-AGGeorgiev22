#include "../include/selectCinemaHall.h"

void SelectCinemaHall::display() {
	hallFound = false;
	showtimeExists = false;

	cinemaData = fetchCinemasFromJSON();
	movieData = fetchMoviesFromJson();

	system("cls");
	std::cout << "---------------------------" << std::endl;
	std::cout << "   SELECT A CINEMA HALL:" << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::cout << cinemaData[UserChoices::cinemaID]["cinemaName"] << " halls:" << std::endl;

	for (const auto& hall : cinemaData[UserChoices::cinemaID]["halls"]) {
		movieID = std::to_string(hall["assignedMovieId"].get<int>());

		if (!movieData.contains(movieID)) {
			std::cout << "Error: Movie ID " << movieID << " not found.\n";
			continue;
		}

		std::cout << "Hall number: " << hall["hallNumber"] 
			<< "\nMovie title: " << movieData[movieID]["title"]  
			<< "\nGenre: " << movieData[movieID]["genre"]
			<< "\nLanguage: " << movieData[movieID]["language"]
			<< "\nTicket price: " << movieData[movieID]["ticketPrice"] << "BGN"
			<< "\nShow times: ";

		for (const auto& time : movieData[movieID]["showtimes"]) {
			std::cout << time << " ";
		}

		std::cout << "\n\n";
	}

	if (!hallFound) {
		std::cout << "Enter the hall number for the movie you want to watch: ";
		std::cin >> UserChoices::cinemaHall;

		std::cout << "Enter the show time (format: 00:00): ";
		std::cin >> UserChoices::movieShowTime;
	}

	for (const auto& hall : cinemaData[UserChoices::cinemaID]["halls"]) {
		if (hall["hallNumber"] == UserChoices::cinemaHall) {
			UserChoices::movieID = std::to_string(hall["assignedMovieId"].get<int>());
			hallFound = true;
			break; 
		}
	}

	if (!hallFound) {
		std::cout << "Invalid hall number.\n";
		UserChoices::cinemaHall = 1;
		return;
	}


	if (!movieData.contains(UserChoices::movieID)) {
		std::cout << "Error: Selected movie not found.\n";
		return;
	}

	const auto& showtimes = movieData[UserChoices::movieID]["showtimes"];
	for (const auto& time : showtimes) {
		if (time == UserChoices::movieShowTime) {
			showtimeExists = true;
			break;
		}
	}


	if(!showtimeExists) {
		std::cout << "Invalid show time.\n";
		UserChoices::movieShowTime = "00:00";
		std::cout << "Enter 2 to try again: ";
		std::cin >> key;
		if (key == 2) {
			key = 0;
			return;
		}
	}

	std::cout << "You have selected hall number: " << UserChoices::cinemaHall << " at " << UserChoices::movieShowTime << std::endl;
	
	std::cout << "Enter 1 to continue: ";
	std::cin >> key;
	
}

void SelectCinemaHall::actionHandler(PageHandler& pages) {
	if (key == 1) {
		pages.selectCinemaHallPageShouldDisplay = false;
		pages.selectSeatPageShouldDisplay = true;
	}
}