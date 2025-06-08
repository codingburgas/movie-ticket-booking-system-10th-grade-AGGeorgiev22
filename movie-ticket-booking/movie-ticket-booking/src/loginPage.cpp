#include "../include/loginPage.h"

void Login::display() {
    system("CLS");
    std::cout << "+---------------------------------+\n";
    std::cout << "|     Please Login to continue    |\n";
    std::cout << "+---------------------------------+\n";
    std::cout << "Don't have an account? Press 1 to register. If you do press 0 and continue.\n";
    std::cin >> key;

    if (key != 1) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Login::inputCreds();
    }
}

void Login::inputCreds() {
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

    Login::checkCreds();
}

void Login::checkCreds() {

    if (!loginUser(credentials::email, credentials::password)) {
        system("CLS");
        std::cout << "Welcome back to Gap!\n";
        std::cout << "Incorrect credentials. Try again!\n";
        credentials::firstName = "";
        credentials::lastName = "";
        credentials::email = "";
        credentials::password = "";

        Login::inputCreds();
    }
    else loggedIn = true;
}

void Login::actionHandler(PageHandler& pages) {
    if (loggedIn) {
        pages.loginPageShouldDisplay = false;
        pages.menuPageShouldDisplay = true;
    }
    else if(key == 1){
        pages.loginPageShouldDisplay = false;
        pages.registerPageShouldDisplay = true;
	}
}