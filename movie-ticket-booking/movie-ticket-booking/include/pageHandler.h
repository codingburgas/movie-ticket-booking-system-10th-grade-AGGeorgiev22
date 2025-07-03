#pragma once
class PageHandler {
public:
    PageHandler();
    bool exitApp;
    bool menuPageShouldDisplay;
	bool registerPageShouldDisplay;
    bool loginPageShouldDisplay;
	bool viewCinemasPageShouldDisplay;
    bool viewMoviesPageShouldDisplay;
	bool selectCinemaPageShouldDisplay;
    bool selectCinemaHallPageShouldDisplay;
    bool selectSeatPageShouldDisplay;
    bool bookTicketsPageShouldDisplay;
    bool addNewCinemaPageShouldDisplay;
    bool manageMoviesPageShouldDisplay;
};