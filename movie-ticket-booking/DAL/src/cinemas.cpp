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

    // Assign movies
    std::vector<int> movieIds = assignMoviesToHalls(cinemaNumOfHalls);

    std::vector<std::string> types = { "silver", "gold", "platinum" };

    // Create halls array
    ordered_json halls = ordered_json::array();
    for (int i = 0; i < cinemaNumOfHalls; ++i) {
        ordered_json hall;
        hall["hallNumber"] = i + 1;
        hall["assignedMovieId"] = movieIds[i];

        ordered_json seats = ordered_json::array();
        for (int j = 0; j < cinemaNumOfSeatsPerHall; ++j) {
            ordered_json seat;

            // Assign type by position
            if (j < 10) seat["type"] = "silver";
            else if (j < 20) seat["type"] = "gold";
            else seat["type"] = "platinum";

            seat["taken"] = false;
            seats.push_back(seat);
        }

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

void displaySeats(std::string cinemaId, int hallNumber) {
    std::ifstream inFile("../../movie-ticket-booking/Data/cinemas.json");
    if (!inFile.is_open()) {
        std::cout << "Error opening file.\n";
        return;
    }

    ordered_json data;
    inFile >> data;
    inFile.close();

    std::string cinemaKey = cinemaId;
    if (!data.contains(cinemaKey)) {
        std::cout << "Cinema ID not found.\n";
        return;
    }

    const auto& halls = data[cinemaKey]["halls"];
    const auto it = std::find_if(halls.begin(), halls.end(),
        [hallNumber](const auto& hall) {
            return hall["hallNumber"] == hallNumber;
        });

    if (it == halls.end()) {
        std::cout << "Hall number not found in cinema.\n";
        return;
    }

    const auto& seats = (*it)["seats"];
    std::cout << "Showing seats for " << data[cinemaKey]["cinemaName"]
        << " hall #" << hallNumber << "\n\n";

    for (size_t i = 0; i < seats.size(); ++i) {
        std::string type = seats[i]["type"];
        bool taken = seats[i]["taken"];

        char shortType = toupper(type[0]); // S, G, or P
        std::string label;

        if (taken)
            label = "[ X ]";
        else {
            label = "[" + std::string(i + 1 < 10 ? "0" : "") +
                std::to_string(i + 1) + shortType + "]";
        }

        std::cout << label << " ";

        if ((i + 1) % 6 == 0) std::cout << "\n\n"; 
    }

    std::cout << "\n[X] - Taken | [01S] - Silver | [11G] - Gold | [21P] - Platinum\n\n";
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

void updateSelectedSeats(const std::string& cinemaID, int hallNumber, int selectedSeats[], int numSeats) {
    std::ifstream inFile("../../movie-ticket-booking/Data/cinemas.json");
    if (!inFile.is_open()) {
        std::cout << "Failed to open JSON file.\n";
        return;
    }

    ordered_json data;
    inFile >> data;
    inFile.close();

    if (!data.contains(cinemaID)) {
        std::cout << "Cinema ID not found.\n";
        return;
    }

    auto& halls = data[cinemaID]["halls"];
    auto hallIt = std::find_if(halls.begin(), halls.end(), [&](const ordered_json& hall) {
        return hall["hallNumber"] == hallNumber;
        });

    if (hallIt == halls.end()) {
        std::cout << "Hall number not found.\n";
        return;
    }

    for (int i = 0; i < numSeats; ++i) {
        int seatIndex = selectedSeats[i] - 1;
        if (seatIndex >= 0 && seatIndex < static_cast<int>((*hallIt)["seats"].size())) {
            (*hallIt)["seats"][seatIndex]["taken"] = true;
        }
        else {
            std::cout << "Invalid seat index: " << selectedSeats[i] << "\n";
        }
    }

    std::ofstream outFile("../../movie-ticket-booking/Data/cinemas.json", std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
        std::cout << "Failed to write to file.\n";
        return;
    }

    outFile << data.dump(4);
    outFile.close();

    std::cout << "Seats updated successfully.\n";
}