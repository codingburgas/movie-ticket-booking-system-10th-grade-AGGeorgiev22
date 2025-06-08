#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/cinemas.h"

class ViewCinemas {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	int key;
	ordered_json cinemaData = fetchCinemasFromJSON();
};