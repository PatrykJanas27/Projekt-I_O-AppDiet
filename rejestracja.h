#pragma once
#include <fstream>
#include <string>
#include <iostream>

class rejestracja 
{
	void wpiszDoPliku(std::string username, std::string password, std::string name, std::string gender, int age, int height, float weight);
	void dopiszDoPliku(std::string username, std::string field, float value);
	bool sprawdzCzyUzytkownikIstnieje(std::string username);
public:
//	rejestracja();
	void formularzRejestracyjny();

};

