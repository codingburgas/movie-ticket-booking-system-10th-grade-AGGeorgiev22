#pragma once
#include "mainPage.h"
#include "viewCinemas.h"
#include "pageHandler.h"

class App {
public:
	App();
private:
	void pageHandler();
	MainPage mainPage;
	ViewCinemas viewCinemas;
	PageHandler pages;

	bool running = true;
};
