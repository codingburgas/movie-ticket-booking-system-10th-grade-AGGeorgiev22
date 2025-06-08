#pragma once
#include <iostream>
#include "pageHandler.h"
#include "../../DAL/include/movies.h"
#include "../../DAL/include/cinemas.h"

class ViewMovies {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	int key;
	ordered_json movieData = fetchMoviesFromJson();
};