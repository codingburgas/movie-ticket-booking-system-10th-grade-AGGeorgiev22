#include "../include/app.h"

App::App() {
	while (running) {
		pageHandler();
	}
}


void App::pageHandler() {
	if (pages.menuPageShouldDisplay) {
		mainPage.display();
		mainPage.actionHandler(pages);
		return;
	}
	if (pages.registerPageShouldDisplay) {
		reg.display();
		reg.actionHandler(pages);
		return;
	}
	if (pages.loginPageShouldDisplay) {
		log.display();
		log.actionHandler(pages);
		return;
	}
	if (pages.viewCinemasPageShouldDisplay) {
		viewCinemas.display();
		viewCinemas.actionHandler(pages);
		return;
	}
	if (pages.viewMoviesPageShouldDisplay) {
		viewMovies.display();
		viewMovies.actionHandler(pages);
		return;
	}
	if (pages.selectCinemaPageShouldDisplay) {
		selectCinema.display();
		selectCinema.actionHandler(pages);
		return;
	}
	if (pages.selectCinemaHallPageShouldDisplay) {
		selectCinemaHall.display();
		selectCinemaHall.actionHandler(pages);
		return;
	}
	if (pages.selectSeatPageShouldDisplay) {
		selectSeat.display();
		selectSeat.actionHandler(pages);
		return;
	}
	if (pages.addNewCinemaPageShouldDisplay) {
		addNewCinema.display();
		addNewCinema.actionHandler(pages);
		return;
	}
	if (pages.exitApp) {
		running = false;
		return;
	}
}