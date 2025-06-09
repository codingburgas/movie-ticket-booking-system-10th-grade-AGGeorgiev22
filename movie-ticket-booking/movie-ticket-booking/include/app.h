#pragma once
#include "mainPage.h"
#include "registerPage.h"
#include "loginPage.h"
#include "viewCinemas.h"
#include "viewMovies.h"
#include "selectCinema.h"
#include "addNewCinema.h"
#include "pageHandler.h"

class App {
public:
	App();
private:
	void pageHandler();
	MainPage mainPage;
	Register reg;
	Login log;
	ViewCinemas viewCinemas;
	ViewMovies viewMovies;
	SelectCinema selectCinema;
	AddNewCinema addNewCinema;
	PageHandler pages;

	bool running = true;
};
