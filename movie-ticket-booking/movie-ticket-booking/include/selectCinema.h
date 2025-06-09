#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/cinemas.h"
#include "../../BLL/include/userChoices.h"

class SelectCinema {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	bool cinemaSelected = false;
	ordered_json cinemaData;
	std::string lastCinemaId;
	int key;
};