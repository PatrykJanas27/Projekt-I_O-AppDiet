#include "uzytkownikZKontem.h"
using namespace std;
uzytkownikZKontem::uzytkownikZKontem()
{
	this->username = "-";
	this->password = "-";
	this->name = "-";
	this->gender = "-";
	int age = NULL;
	int height = NULL;
	float weight = NULL;
}
void uzytkownikZKontem::napisUZK()
{
	cout << "********************************************************************\n\n";
	cout << "*********************   UZYTKOWNIK Z KONTEM   **********************\n\n";
	cout << "********************************************************************\n\n";
}
void uzytkownikZKontem::updateUzytkownik(std::string userName)
{
	string field_1, field_2, field_3, field_4;
	fstream file;
	file.open(".\\Users\\" + userName + ".csv");
	while (file)
	{
		getline(file, field_1, ',');
		getline(file, field_2, '\n');
		if (field_1 == "Username:")
			this->username = field_2;
		if (field_1 == "Password:")
			this->password = field_2;
		if (field_1 == "Name:")
			this->name = field_2;
		if (field_1 == "Gender:")
			this->gender = field_2;
		if (field_1 == "Age:")
			this->age = std::stoi(field_2);
		if (field_1 == "Height:")
			this->height = std::stoi(field_2);
		if (field_1 == "Weight:")
			this->weight = std::stof(field_2);
	}	
	/*else {
		cout << "Plik nie zosta³ otwarty." << endl;
	}*/
}

int uzytkownikZKontem::wyborUzytkownikaZKontem()
{
	int position = 1;
	int key = 0;

	while (true) //13 to enter
	{
		system("cls");
		napisUZK();

		menu::arrow(1, position);	 cout << "OBLICZANIE BMI" << endl;
		menu::arrow(2, position);	 cout << "OBLICZANIE ZAPOTRZEBOWANIA KALORYCZNEGO" << endl;
		menu::arrow(3, position);	 cout << "DOBIERANIE DIETY" << endl;
		menu::arrow(4, position);	 cout << "DOBIERANIE CWICZEN" << endl;

		cout << endl << "Next -> ENTER\t\t\t\t\t\t Back -> ESC" << endl;

		key = _getch();

		if (key == 80 && position != 4) {	//strzalka w dol
			position++;
		}
		else if (key == 72 && position != 1) { //strzalka w gore

			position--;
		}
		else {
			position = position;
		}

		if (key == 13)
		{
			return position;
		}

		if (key == 27)
		{
			return 5;
		}
	}
}

int uzytkownikZKontem::przekierowanieUzytkownikaZKontem()
{
	int state;
	while (true)
	{
		state = wyborUzytkownikaZKontem();
		switch (state)
		{
		case 1:
		{	//OBLICZANIE BMI
			system("cls");
			ObliczanieBMI* newBMI = new	ObliczanieBMI;
			newBMI->kalkulatorBMI(uzytkownikZKontem::getWeight(), uzytkownikZKontem::getHeight(),"z kontem");
			uzytkownikZKontem::dopiszDoPliku("BMI", newBMI->getBMI());
			break;
		}
		
		case 2:
		{	//OBLICZANIE ZAPOTRZEBOWANIA KALORYCZNEGO
			system("cls");
			ObliczanieZK* newZK = new ObliczanieZK;
			newZK->kalkulatorZK(uzytkownikZKontem::getWeight(), uzytkownikZKontem::getHeight(), uzytkownikZKontem::getAge(), uzytkownikZKontem::getGender(), "z kontem");
			uzytkownikZKontem::dopiszDoPliku("Zapotrzebowanie kaloryczne", newZK->getZK());
			break;
		}
		case 3:
		{
			system("cls");
			dobieranieDiety* newDieta=new dobieranieDiety;
			newDieta->przekierowanieWyborIlosciPosilkow();

			break;
		}
		case 4:
		{
			system("cls");
			dobieranieCwiczenia* newCwiczenia = new dobieranieCwiczenia;
			newCwiczenia->przekierowanieWyborStopniaCwiczen();
			
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		}
	}
	return 0;
}

void uzytkownikZKontem::dopiszDoPliku(string varName,float value)
{
	ofstream file;
	file.open(".\\Users\\" + this->username + ".csv", std::ios::app);
	file << varName << ":" << "," << value << endl;
	file.close();
}

float uzytkownikZKontem::getWeight()
{
	return this->weight;
}

int uzytkownikZKontem::getHeight()
{
	return this->height;
}

string uzytkownikZKontem::getGender()
{
	return this->gender;
}

int uzytkownikZKontem::getAge()
{
	return this->age;
}
