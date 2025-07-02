#pragma once
#include "mainPage.h"
#include "registerPage.h"
#include "loginPage.h"
#include "viewCinemas.h"
#include "viewMovies.h"
#include "selectCinema.h"
#include "selectCinemaHall.h"
#include "selectSeat.h"
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
	SelectCinemaHall selectCinemaHall;
	SelectSeat selectSeat;
	AddNewCinema addNewCinema;
	PageHandler pages;

	bool running = true;
};
