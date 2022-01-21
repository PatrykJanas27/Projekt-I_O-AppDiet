#include <iostream>
#include <fstream>
#include <string>
#pragma once

class logowanie 
{
	bool szukajUzytkownika(std::string username, std::string password);
	std::string username;
public:
	std::string getLogin();
	bool formularzLogowania();
};

