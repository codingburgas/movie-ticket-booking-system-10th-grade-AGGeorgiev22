#include "../include/pageHandler.h"

PageHandler::PageHandler() {
    exitApp = false;
    menuPageShouldDisplay = true;
    viewCinemasPageShouldDisplay = false;
    viewMoviesPageShouldDisplay = false;
    bookTicketsPageShouldDisplay = false;
    addNewCinemaPageShouldDisplay = false;
}

PageHandler pages;
