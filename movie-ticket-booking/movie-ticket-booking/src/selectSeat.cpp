#include "../include/selectSeat.h"

void SelectSeat::display() {
	system("cls");

	std::cout << "------------------------" << std::endl;
	std::cout << "      SELECT SEATS:" << std::endl;
	std::cout << "------------------------" << std::endl;

    displaySeats(UserChoices::cinemaID, UserChoices::cinemaHall);

	numOfSeats = cinemaData[UserChoices::cinemaID]["cinemaNumOfSeatsPerHall"];

	std::cout << "Enter the amount of seats you want to book: ";
	std::cin >> UserChoices::cinemaNumOfBookedSeats;
	if(UserChoices::cinemaNumOfBookedSeats < 1 || UserChoices::cinemaNumOfBookedSeats > numOfSeats) {
		std::cout << "You must book at least one seat." << std::endl;
		return;
	}

	std::cout << "Enter the seat numbers you want to book: ";
	for(int i = 0; i < UserChoices::cinemaNumOfBookedSeats; i++) {
		int seatNumber;
		std::cin >> seatNumber;
		if(seatNumber < 1 || seatNumber > numOfSeats) {
			std::cout << "Invalid seat number. Please enter a number between 1 and " << numOfSeats << "." << std::endl;
			i--; // Decrement to retry this seat
		} else {
			UserChoices::cinemaSeat[i] = seatNumber;
		}
	}

	updateSelectedSeats(UserChoices::cinemaID, UserChoices::cinemaHall, UserChoices::cinemaSeat, UserChoices::cinemaNumOfBookedSeats);

}


void SelectSeat::actionHandler(PageHandler& pages) {

}