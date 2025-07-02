#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"

using nlohmann::ordered_json;
using json = nlohmann::json;

void insertRecord(std::string firstName, std::string lastName, std::string email, std::string password, bool isAdmin);

bool loginUser(std::string email, std::string password);

void editUserInfo(std::string firstName, std::string lastName, std::string email, std::string password);
