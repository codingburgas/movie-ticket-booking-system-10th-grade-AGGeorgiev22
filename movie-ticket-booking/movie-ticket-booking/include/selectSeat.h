#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/cinemas.h"
#include "../../BLL/include/userChoices.h"
#include "../../BLL/include/credentials.h"
#include "registerPage.h"

class SelectSeat {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	ordered_json cinemaData = fetchCinemasFromJSON();
	int numOfSeats = 0;
};
