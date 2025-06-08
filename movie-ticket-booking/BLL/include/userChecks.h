#pragma once
#include "pch.h"

bool checkPassword(std::string password);

bool checkUsername(std::string& username);

bool checkEmail(std::string& email);

bool checkValidity(std::string& username, std::string& email, std::string& password);

void hidePassword(std::string& password, char& ch);