#pragma once
#include <random>
#include "pch.h"

void addMovie(const std::string& title, const std::string& language, const std::string& genre,
	const std::string& releaseDate, double silverPrice, double goldPrice, double platinumPrice,
	const std::vector<std::string>& showtimes);

void deleteMovie(const std::string& movieId);

int getRandomMovieId();

std::vector<int> assignMoviesToHalls(int numHalls);

ordered_json fetchMoviesFromJson();

void displayMovies(const ordered_json& movieData);


void displayMoviesByField(const std::string& field, const std::string& value);