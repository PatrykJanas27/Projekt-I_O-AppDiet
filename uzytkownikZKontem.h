#include "uzytkownikBezKonta.h"
#include <iostream>
#include <conio.h>
#include "uzytkownikBezKonta.h"
#include <fstream>
#include <string>
#include "dobieranieCwiczenia.h"
#include "dobieranieDiety.h"
#pragma once
class uzytkownikZKontem : public uzytkownikBezKonta, public ObliczanieBMI, public dobieranieCwiczenia, public dobieranieDiety
{
private:
	string username, password, name, gender;
	int age;
	int height;
	float weight;
	void napisUZK();
	int wyborUzytkownikaZKontem();
public:
	uzytkownikZKontem();
	void updateUzytkownik(std::string userName);
	int przekierowanieUzytkownikaZKontem();
	void dopiszDoPliku(string varName,float value);
	float getWeight();
	int getHeight();
	string getGender();
	int getAge();
};

