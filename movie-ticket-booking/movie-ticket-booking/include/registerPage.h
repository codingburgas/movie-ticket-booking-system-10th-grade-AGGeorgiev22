#pragma once
#include "pageHandler.h"
#include "../../DAL/include/users.h"
#include "../../BLL/include/userChecks.h"
#include "../../BLL/include/credentials.h"

class Register {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	void insertCreds();
	void checkAndInsertCreds();
	int key = 0;
	bool registered = false;
};