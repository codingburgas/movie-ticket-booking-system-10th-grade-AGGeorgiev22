#pragma once
#include <iostream>
#include "pageHandler.h"

class MainPage {
public:
	void display();
	void actionHandler(PageHandler& pages);
};