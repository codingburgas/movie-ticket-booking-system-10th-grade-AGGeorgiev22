#include "../include/registerPage.h"

void Register::display() {
    system("CLS");
    std::cout << "+-----------------------------------------------+\n";
    std::cout << "|       Please Register before continuing!      |\n";
    std::cout << "+-----------------------------------------------+\n";
	std::cout << "Already have an account? Press 1 to login. If not press 0 and continue.\n";
    std::cin >> key;
    if (key != 1) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    insertCreds();

        checkAndInsertCreds();
    }

}

void Register::insertCreds() {
    std::cout << "First name: ";
    getline(std::cin, credentials::firstName);
    while (credentials::firstName.empty()) {
        std::cout << "First name cannot be empty!\n";
        std::cout << "First name: ";
        getline(std::cin, credentials::firstName);
    }

    std::cout << "Last name: ";
    getline(std::cin, credentials::lastName);
    while (credentials::lastName.empty()) {
        std::cout << "Last name cannot be empty!\n";
        std::cout << "Last name: ";
        getline(std::cin, credentials::lastName);
    }

    std::cout << "Email: ";
    getline(std::cin, credentials::email);
    while (!checkEmail(credentials::email)) {
        std::cout << "Input valid email!\n";
        std::cout << "Email: ";
        getline(std::cin, credentials::email);
    }

    std::cout << "Password: ";
    hidePassword(credentials::password);
    while (!checkPassword(credentials::password)) {
        std::cout << "Invalid password!\n";
        std::cout << "Password: ";
        hidePassword(credentials::password);
    }

}

void Register::checkAndInsertCreds() {
    if (!checkValidity(credentials::firstName, credentials::email, credentials::password)) std::cout << "Invalid credentials!\n";
    else {
        insertRecord(credentials::firstName, credentials::lastName, credentials::email, credentials::password);
        registered = true;
    }
}

void Register::actionHandler(PageHandler& pages) {
    if (registered) {
        std::cout << "Registration successful!\n";
        pages.registerPageShouldDisplay = false;
        pages.menuPageShouldDisplay = true;
    }
    else if (key == 1) {
		pages.registerPageShouldDisplay = false;
		pages.loginPageShouldDisplay = true;
    }
}