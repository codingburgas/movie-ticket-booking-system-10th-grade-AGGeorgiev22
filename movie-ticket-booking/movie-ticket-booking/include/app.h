#pragma once
#include "mainPage.h"
#include "viewCinemas.h"
#include "addNewCinema.h"
#include "pageHandler.h"

class App {
public:
	App();
private:
	void pageHandler();
	MainPage mainPage;
	ViewCinemas viewCinemas;
	AddNewCinema addNewCinema;
	PageHandler pages;

	bool running = true;
};
