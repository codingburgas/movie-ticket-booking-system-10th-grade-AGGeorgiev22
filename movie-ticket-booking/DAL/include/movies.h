#pragma once
#include <random>
#include "pch.h"

// Generates a random movie ID between 1 and 20
int getRandomMovieId();

std::vector<int> assignMoviesToHalls(int numHalls);

ordered_json fetchMoviesFromJson();

void displayMovies(const ordered_json& movieData);