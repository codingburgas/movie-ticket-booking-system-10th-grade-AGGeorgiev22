#pragma once
#include "mainPage.h"
#include "pageHandler.h"

class App {
public:
	App();
private:
	void pageHandler();
	MainPage mainPage;
	PageHandler pages;

	bool running = true;
};
