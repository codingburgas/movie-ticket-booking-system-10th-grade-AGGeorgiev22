#pragma once
#include "pch.h"
#include "movies.h"

void addCinema(std::string cinemaName, std::string cinemaCity, int cinemaNumOfHalls, int cinemaNumOfSeatsPerHall);

ordered_json fetchCinemasFromJSON();

void displayCinemas(ordered_json& cinemas);

void fetchLastCinemaID(std::string& lastCinemaID);