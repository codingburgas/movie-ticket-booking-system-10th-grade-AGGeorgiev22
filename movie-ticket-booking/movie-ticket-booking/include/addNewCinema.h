#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/cinemas.h"

class AddNewCinema {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	int key;
	std::string cinemaName;
	std::string cinemaCity;
	int cinemaNumOfHalls;
	int cinemaNumOfSeatsPerHall;
};