#pragma once
#include "mainPage.h"
#include "viewCinemas.h"
#include "viewMovies.h"
#include "addNewCinema.h"
#include "pageHandler.h"

class App {
public:
	App();
private:
	void pageHandler();
	MainPage mainPage;
	ViewCinemas viewCinemas;
	ViewMovies viewMovies;
	AddNewCinema addNewCinema;
	PageHandler pages;

	bool running = true;
};
