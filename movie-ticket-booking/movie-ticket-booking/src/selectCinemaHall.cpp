#include "../include/selectCinemaHall.h"

void SelectCinemaHall::display() {
	cinemaData = fetchCinemasFromJSON();
	movieData = fetchMoviesFromJson();

	system("cls");
	std::cout << "---------------------------" << std::endl;
	std::cout << "   SELECT A CINEMA HALL:" << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::cout << cinemaData[UserChoices::cinemaID]["cinemaName"] << "halls:" << std::endl;

	for (const auto& hall : cinemaData[UserChoices::cinemaID]["halls"]) {
		movieID = std::to_string(hall["assignedMovieId"].get<int>());
		std::cout << "Hall number: " << hall["hallNumber"] 
			<< "\nMovie title: " << movieData[movieID]["title"]  
			<< "\nGenre: " << movieData[movieID]["genre"]
			<< "\nLanguage: " << movieData[movieID]["language"]
			<< "\nTicket price: " << movieData[movieID]["ticketPrice"] << "BGN"
			<< "\nShow times: " << movieData[movieID]["showtimes"];
		std::cout << "\n\n";
	}

	if (!hallFound) {
		std::cout << "Enter the hall number for the movie you want to watch: ";
		std::cin >> UserChoices::cinemaHall;
	}

	for (const auto& hall : cinemaData[UserChoices::cinemaID]["halls"]) {
		if (hall["hallNumber"] == UserChoices::cinemaHall) {
			UserChoices::movieID = std::to_string(hall["assignedMovieId"].get<int>());
			hallFound = true;
			break; // found the hall, no need to continue
		}
	}

	if (!hallFound) {
		std::cout << "Invalid hall number.\n";
		return;
	}
	else {
		std::cout << "You have selected hall number: " << UserChoices::cinemaHall << std::endl;
		std::cout << "Enter 1 to continue: ";
		std::cin >> key;
	}
}

void SelectCinemaHall::actionHandler(PageHandler& pages) {
	if (key == 1) {
		pages.selectCinemaHallPageShouldDisplay = false;
		pages.selectSeatPageShouldDisplay = true;
	}
}