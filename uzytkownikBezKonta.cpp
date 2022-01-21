#include "uzytkownikBezKonta.h"

using namespace std;

string uzytkownikBezKonta::getGender()
{
	return this->gender;
}
float uzytkownikBezKonta::getWeight()
{
	return this->weight;
}
int uzytkownikBezKonta::getHeight()
{
	return this->height;
}
int uzytkownikBezKonta::getAge()
{
	return this->age;
}


void uzytkownikBezKonta::formularzUzytkownikBezKonta() {
	cout << "********************************************************************\n\n";
	cout << "******************   UZYTKOWNIK BEZ UZYTKOWNIKA   ******************\n\n";
	cout << "********************************************************************\n\n";

	cout << "Wpisz swoja plec: "; cin >> gender;
	cout << "Wpisz swoj wiek: "; cin >> age;
	cout << "Wpisz swoj wzrost: "; cin >> height;
	cout << "Wpisz swoja wage: "; cin >> weight;
	this->age = age;
	this->gender = gender;
	this->height = height;
	this->weight = weight;
}

int uzytkownikBezKonta::wyborUzytkownikBezKonta() {
	int position = 1;
	int key = 0;

	while (true) //13 to enter
	{
		system("cls");
		cout << "********************************************************************\n\n";
		cout << "*********************   UZYTKOWNIK BEZ KONTA   *********************\n\n";
		cout << "********************************************************************\n\n";
		menu::arrow(1, position);	 cout << "OBLICZANIE BMI" << endl;
		menu::arrow(2, position);	 cout << "OBLICZANIE ZAPOTRZEBOWANIA KALORYCZNEGO" << endl;


		cout << endl << "Next -> ENTER\t\t\t\t\t\t Back -> ESC" << endl;

		key = _getch();

		if (key == 80 && position != 2) {	//strzalka w dol
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
			return 3;
		}
	}
}

int uzytkownikBezKonta::przekierowanieMenuUzytkownikBezKonta()
{
	int state;
	while (true)
	{
		state = wyborUzytkownikBezKonta();
		switch (state)
		{
			case 1:
			{
				system("cls");
				ObliczanieBMI* newBMI = new	ObliczanieBMI;
				newBMI->kalkulatorBMI(getWeight(), getHeight(), "bez konta");
				delete newBMI;
				break;
			}
			break;
			case 2:
			{
				system("cls");
				ObliczanieZK* newZK = new ObliczanieZK;
				newZK->kalkulatorZK(getWeight(), getHeight(), getAge(), getGender(), "bez konta");
				delete newZK;
				break;
			}
			case 3:
				return 0;
		}
	}
	return 0;
}


