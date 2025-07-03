#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/cinemas.h"
#include "../../BLL/include/userChoices.h"
#include "../../BLL/include/credentials.h"

class SelectSeat {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	bool isSeatTaken(int seatNumber);
	ordered_json cinemaData;
	int numOfSeats = 0;
	int key;
};
