#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/cinemas.h"
#include "../../BLL/include/userChoices.h"
#include "../../BLL/include/credentials.h"
#include "registerPage.h"

class SelectCinema {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	Register reg;

	ordered_json cinemaData;
	std::string lastCinemaId;

	bool cinemaSelected = false;
	bool userRegistered = false;
	char continueToRegister = ' ';
	int key;

};