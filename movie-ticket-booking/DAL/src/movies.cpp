#include "../include/movies.h"

int getRandomMovieId(){
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> distrib(1, 20);
	return distrib(gen);
}

std::vector<int> assignMoviesToHalls(int numHalls) {
	std::set<int> assignedMovies;
	std::vector<int> movieIds;

	while (assignedMovies.size() < numHalls) {
		int id = getRandomMovieId();
		if (!assignedMovies.count(id)) {
			assignedMovies.insert(id);
			movieIds.push_back(id);
		}
	}

	return movieIds;
}