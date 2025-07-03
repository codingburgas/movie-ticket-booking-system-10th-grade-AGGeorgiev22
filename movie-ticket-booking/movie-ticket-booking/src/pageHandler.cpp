#include "../include/pageHandler.h"

PageHandler::PageHandler() {
    exitApp = false;
    menuPageShouldDisplay = true;
    registerPageShouldDisplay = false;
    loginPageShouldDisplay = false;
    viewCinemasPageShouldDisplay = false;
    viewMoviesPageShouldDisplay = false;
    selectCinemaPageShouldDisplay = false;
    selectCinemaHallPageShouldDisplay = false;
    selectSeatPageShouldDisplay = false;
    bookTicketsPageShouldDisplay = false;
    addNewCinemaPageShouldDisplay = false;
    manageMoviesPageShouldDisplay = false;
}

PageHandler pages;
