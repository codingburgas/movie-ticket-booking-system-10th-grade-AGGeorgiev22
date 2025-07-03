#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/movies.h"
#include "../../BLL/include/userChoices.h"
#include "../../BLL/include/credentials.h"

class BookTickets {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	void calculateTotalPrice();
	bool isValidCardFormat(const std::string& cardNumber);
	ordered_json movieData;
	int totalPrice = 0;
	std::string cardNumber;
	int key;
};