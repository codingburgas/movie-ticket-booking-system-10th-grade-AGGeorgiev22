#include "../include/cinemas.h"

void addCinema(std::string cinemaName, std::string cinemaCity, std::string cinemaNumOfHalls, std::string cinemaNumOfSeatsPerHall) {

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
    ordered_json newEntry = {
        {"cinemaName", cinemaName},
        {"cinemaCity", cinemaCity},
        {"cinemaNumOfHalls", cinemaNumOfHalls},
		{"cinemaNumOfSeatsPerHall", cinemaNumOfSeatsPerHall}
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