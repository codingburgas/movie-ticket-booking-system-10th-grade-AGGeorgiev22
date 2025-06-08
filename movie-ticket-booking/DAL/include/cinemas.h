#pragma once
#include "pch.h"

void addCinema(std::string cinemaName, std::string cinemaCity, std::string cinemaNumOfHalls);

ordered_json fetchCinemasFromJSON();

void displayCinemas(ordered_json& cinemas);