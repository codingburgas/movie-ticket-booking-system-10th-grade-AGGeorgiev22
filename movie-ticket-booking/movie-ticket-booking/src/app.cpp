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
	if (pages.exitApp) {
		running = false;
		return;
	}
}