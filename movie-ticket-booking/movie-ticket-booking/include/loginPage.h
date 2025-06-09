#pragma once
#include "pageHandler.h"
#include "../../DAL/include/users.h"
#include "../../BLL/include/userChecks.h"
#include "../../BLL/include/credentials.h"

class Login {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	void inputCreds();
	void checkCreds();
	int key = 0;
	bool loggedIn = false;
};