#include "../include/pageHandler.h"

PageHandler::PageHandler() {
    exitApp = false;
    menuPageShouldDisplay = true;
    registerPageShouldDisplay = false;
    loginPageShouldDisplay = false;
    viewCinemasPageShouldDisplay = false;
    viewMoviesPageShouldDisplay = false;
    selectCinemaPageShouldDisplay = false;
    bookTicketsPageShouldDisplay = false;
    addNewCinemaPageShouldDisplay = false;
}

PageHandler pages;
