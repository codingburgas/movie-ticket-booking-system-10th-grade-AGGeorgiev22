#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/movies.h"
#include "../../DAL/include/cinemas.h"
#include "../../BLL/include/userChoices.h"
#include "../../BLL/include/credentials.h"

class SelectCinemaHall {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	ordered_json cinemaData;
	ordered_json movieData;
	std::string movieID;
	bool hallFound = false;
	int key;
};
