#include "../include/movies.h"

void addMovie(const std::string& title, const std::string& language, const std::string& genre,
	const std::string& releaseDate, double silverPrice, double goldPrice, double platinumPrice,
	const std::vector<std::string>& showtimes) {
	std::ifstream inFile("../../movie-ticket-booking/Data/movies.json");
	ordered_json data;

	if (!inFile) {
		std::cout << "Error opening movies.json file.\n";
		return;
	}

	if (inFile.peek() != std::ifstream::traits_type::eof()) {
		inFile >> data;
	}
	inFile.close();

	// Find next available ID
	int key = 1;
	while (data.contains(std::to_string(key))) {
		key++;
	}
	std::string newKey = std::to_string(key);

	ordered_json newMovie = {
		{"title", title},
		{"language", language},
		{"genre", genre},
		{"releaseDate", releaseDate},
		{"ticketPrice", {
			{"silver", silverPrice},
			{"gold", goldPrice},
			{"platinum", platinumPrice}
		}},
		{"showtimes", showtimes}
	};

	data[newKey] = newMovie;

	std::ofstream outFile("../../movie-ticket-booking/Data/movies.json", std::ios::out | std::ios::trunc);
	if (!outFile) {
		std::cout << "Failed to open movies.json for writing.\n";
		return;
	}

	outFile << data.dump(4);
	outFile.close();

	std::cout << "Movie added successfully under ID " << newKey << ".\n";
}

void deleteMovie(const std::string& movieId) {
	std::ifstream inFile("../../movie-ticket-booking/Data/movies.json");
	ordered_json data;

	if (!inFile) {
		std::cout << "Error opening movies.json file.\n";
		return;
	}

	if (inFile.peek() != std::ifstream::traits_type::eof()) {
		inFile >> data;
	}
	inFile.close();

	if (!data.contains(movieId)) {
		std::cout << "Movie with ID " << movieId << " does not exist.\n";
		return;
	}

	data.erase(movieId);

	std::ofstream outFile("../../movie-ticket-booking/Data/movies.json", std::ios::out | std::ios::trunc);
	if (!outFile) {
		std::cout << "Failed to open movies.json for writing.\n";
		return;
	}

	outFile << data.dump(4);
	outFile.close();

	std::cout << "Movie with ID " << movieId << " deleted successfully.\n";
}


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
				  << "Ticket Price: " << movie["ticketPrice"] << "\n"
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