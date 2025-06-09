#include "../include/cinemas.h"

void addCinema(std::string cinemaName, std::string cinemaCity, int cinemaNumOfHalls, int cinemaNumOfSeatsPerHall) {

    std::ifstream inFile("../../movie-ticket-booking/Data/cinemas.json");
    ordered_json data;

    if (!inFile) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> data;
    }
    inFile.close();


    int key = 1;
    while (true) {
        if (!data.contains(std::to_string(key)))
            break;
        key++;
    }
    std::string newKey = std::to_string(key);

    int numHalls = cinemaNumOfHalls;
    int seatsPerHall = cinemaNumOfSeatsPerHall;

    // Assign movies
    std::vector<int> movieIds = assignMoviesToHalls(numHalls);

    // Create halls array
    ordered_json halls = ordered_json::array();
    for (int i = 0; i < numHalls; ++i) {
        ordered_json hall;
        hall["hallNumber"] = i + 1;
        hall["assignedMovieId"] = movieIds[i];

        std::vector<bool> seats(seatsPerHall, false); // all available
        hall["seats"] = seats;

        halls.push_back(hall);
    }

    ordered_json newEntry = {
        {"cinemaName", cinemaName},
        {"cinemaCity", cinemaCity},
        {"cinemaNumOfHalls", cinemaNumOfHalls},
		{"cinemaNumOfSeatsPerHall", cinemaNumOfSeatsPerHall},
        {"halls", halls}
    };
    data[newKey] = newEntry;

    std::ofstream outFile("../../movie-ticket-booking/Data/cinemas.json", std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
        std::cout << "Record inserted successfully." << std::endl;
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

ordered_json fetchCinemasFromJSON() {
	const std::string filePath = "../../movie-ticket-booking/Data/cinemas.json";

    ordered_json cinemaData;

    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cout << "Error opening file." << std::endl;
        return cinemaData;
    }

    if (inFile.peek() != std::ifstream::traits_type::eof()) {
        inFile >> cinemaData;
    }
    inFile.close();

    if (cinemaData.empty()) {
        std::cout << "No events found." << std::endl;
        return cinemaData;
    }

    return cinemaData;
}

void displayCinemas(ordered_json& cinemaData) {
    if (cinemaData.empty()) {
        std::cout << "No cinemas available." << std::endl;
        return;
    }
    for (auto& item : cinemaData.items()) {
        ordered_json cinema = item.value();
        std::cout << "Cinema ID: " << item.key() << ", " << std::endl;
        std::cout << "Name: " << cinema["cinemaName"] << ", " << std::endl;
        std::cout << "City: " << cinema["cinemaCity"] << ", " << std::endl;
        std::cout << "Number of Halls: " << cinema["cinemaNumOfHalls"] << ", " << std::endl;
        std::cout << "Seats per Hall: " << cinema["cinemaNumOfSeatsPerHall"] << ", " << std::endl << std::endl;
    }
}

void fetchLastCinemaID(std::string& lastCinemaID) {
    ordered_json cinemaData = fetchCinemasFromJSON();
    if (cinemaData.empty()) {
        lastCinemaID = "";
        return;
    }
    for (auto& item : cinemaData.items()) {
		lastCinemaID = item.key();
    }
}