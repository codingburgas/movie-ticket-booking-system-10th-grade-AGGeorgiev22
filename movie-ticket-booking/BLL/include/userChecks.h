#pragma once
#include "pch.h"

bool checkPassword(std::string password);

bool checkName(std::string& name);

bool checkEmail(std::string& email);

bool checkValidity(std::string& username, std::string& email, std::string& password);

void hidePassword(std::string& password);