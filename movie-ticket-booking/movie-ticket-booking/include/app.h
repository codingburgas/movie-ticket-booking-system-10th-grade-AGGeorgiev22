#pragma once
#include "mainPage.h"
#include "registerPage.h"
#include "loginPage.h"
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
	Register reg;
	Login log;
	ViewCinemas viewCinemas;
	ViewMovies viewMovies;
	AddNewCinema addNewCinema;
	PageHandler pages;

	bool running = true;
};
