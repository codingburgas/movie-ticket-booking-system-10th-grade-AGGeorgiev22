#include "../include/bookTickets.h"

void BookTickets::display() {
	movieData = fetchMoviesFromJson();

	system("cls");
	std::cout << "---------------------------" << std::endl;
	std::cout << "   SELECT A CINEMA HALL:" << std::endl;
	std::cout << "---------------------------" << std::endl;

	if (totalPrice == 0) calculateTotalPrice();
	
	std::cout << "Your total price is: " << totalPrice << std::endl;

	if(credentials::cardNumber == "") {
		std::cout << "Please enter your card number: ";
		std::cin >> credentials::cardNumber;
	}

	if (!isValidCardFormat(credentials::cardNumber)) {
		std::cout << "Invalid card number format. Please enter a 16-digit card number." << std::endl;
		return;
	}

	std::cout << "Please enter your security code (CVV): ";
	std::cin >> credentials::securityCode;

	std::string securityCode = std::to_string(credentials::securityCode);
	if (securityCode.length() != 3 && securityCode.length() != 4) {
		std::cout << "Invalid security code. Please enter the 3 or 4 digit code on the back of your card: ";
		return;
	}

	std::cout << "Tickets booked successfully! Thank you for your purchase!\n";
	std::cout << "Enter 1 to go back to the menu: ";
	std::cin >> key;
}

void BookTickets::calculateTotalPrice() {
	for (int i = 0; i < UserChoices::cinemaNumOfBookedSeats; i++) {
		if (UserChoices::cinemaSeat[i] <= 10) {
			totalPrice += movieData[UserChoices::movieID]["ticketPrice"]["silver"];
		}
		else if (UserChoices::cinemaSeat[i] >= 10 && UserChoices::cinemaSeat[i] <= 20) {
			totalPrice += movieData[UserChoices::movieID]["ticketPrice"]["gold"];
		}
		else totalPrice += movieData[UserChoices::movieID]["ticketPrice"]["platinum"];
	}
}

bool BookTickets::isValidCardFormat(const std::string& cardNumber) {
	// Check if it has 16 characters
	if (cardNumber.length() != 16)
		return false;

	// Check if all characters are digits
	return std::all_of(cardNumber.begin(), cardNumber.end(), ::isdigit);
}

void BookTickets::actionHandler(PageHandler& pages) {
	if (key == 1) {
		pages.bookTicketsPageShouldDisplay = false;
		pages.menuPageShouldDisplay = true;
	}
}