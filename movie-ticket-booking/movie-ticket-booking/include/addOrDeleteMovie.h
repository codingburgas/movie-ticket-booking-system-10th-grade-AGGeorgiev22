#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/cinemas.h"

class AddOrDeleteMovie {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	int key;

	std::string movieTitle;
	std::string language;
	std::string genre;
	std::string releaseDate;
	double silverPrice;
	double goldPrice;
	double platinumPrice;
	int numOfShows;
	std::string showtimeInput;
	std::vector<std::string> showtimes;

	std::string movieID;
};