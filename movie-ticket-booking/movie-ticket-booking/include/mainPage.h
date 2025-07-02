#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../BLL/include/credentials.h"

class MainPage {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	bool loggedUserIsAdmin = false;
	int key;
};