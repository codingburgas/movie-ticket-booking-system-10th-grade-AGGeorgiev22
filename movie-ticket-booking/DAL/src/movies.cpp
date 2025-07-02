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

ordered_json fetchMoviesFromJson() {
	const std::string filePath = "../../movie-ticket-booking/Data/movies.json";

	ordered_json movieData;

	std::ifstream inFile(filePath);
	if (!inFile) {
		std::cout << "Error opening file." << std::endl;
		return movieData;
	}

	if (inFile.peek() != std::ifstream::traits_type::eof()) {
		inFile >> movieData;
	}
	inFile.close();

	if (movieData.empty()) {
		std::cout << "No events found." << std::endl;
		return movieData;
	}

	return movieData;
}

void displayMovies(const ordered_json& movieData){
	if (movieData.empty()) {
		std::cout << "No movies to show." << std::endl;
		return;
	}

	for (auto& item : movieData.items()) {
		ordered_json movie = item.value();
		std::cout << "Movie ID: " << item.key() << "\n"
				  << "Title: " << movie["title"] << "\n"
				  << "language: " << movie["language"] << "\n"
				  << "Genre: " << movie["genre"] << "\n"
				  << "Release Date: " << movie["releaseDate"] << "\n"
				  << "Ticket Price: " << movie["ticketPrice"] << "BGN\n"
				  << "Show times: " << movie["showtimes"] << "\n\n";
	}
}


void displayMoviesByField(const std::string& field, const std::string& value) {
	ordered_json movieData = fetchMoviesFromJson();

	if (movieData.empty()) {
		std::cout << "No movie data available.\n";
		return;
	}

	bool found = false;

	for (const auto& item : movieData.items()) {
		const auto& movie = item.value();

		if (!movie.contains(field) || movie[field].is_null())
			continue;

		std::string fieldValue = movie[field].get<std::string>();
		bool match = false;

		// Allow partial match for releaseDate
		if (field == "releaseDate") {
			if (fieldValue.find(value) == 0)
				match = true;
		}
		else if (fieldValue == value) {
			match = true;
		}

		if (match) {
			found = true;
			std::cout << "\nTitle: " << movie["title"] << "\n";
			std::cout << "Language: " << movie["language"] << "\n";
			std::cout << "Genre: " << movie["genre"] << "\n";
			std::cout << "Release Date: " << movie["releaseDate"] << "\n";

			std::cout << "Showtimes: ";
			for (const auto& times : movie["showtimes"]) {
				std::cout << times << " ";
			}
			std::cout << "\n";

		}
	}

	if (!found) {
		std::cout << "No movies found for " << field << ": " << value << "\n";
	}
}