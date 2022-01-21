#include "rejestracja.h"
using namespace std;

void rejestracja::wpiszDoPliku(string username, string password, string name, string gender, int age, int height, float weight)
{
	ofstream file;
	file.open(".\\Users\\" + username + ".csv", ios::out | ios::app);
	file << "Username:" << "," << username << endl;
	file << "Password:" << "," << password << endl;
	file << "Name:" << "," << name << endl;
	file << "Gender:" << "," << gender << endl;
	file << "Age:" << "," << age << endl;
	file << "Height:" << "," << height << endl;
	file << "Weight:" << "," << weight << endl;
	file.close();
}

void rejestracja::dopiszDoPliku(string username, string field, float value)
{
	ofstream file;
	file.open(".\\Users\\" + username + ".csv", ios::out | ios::app);
	file << field << ":" << "," << value << endl;
	file.close();
}

bool rejestracja::sprawdzCzyUzytkownikIstnieje(string username)
{
	fstream file;
	file.open(".\\Users\\" + username + ".csv");
		if (file) {
			cout << "Taki uzytkownik juz istnieje, sproboj ponownie." << endl;
			system("pause");
			return true;
		}
		else {
			return false;
		}
}

//rejestracja::rejestracja()
//{
//	fstream fout;
//	fout.open(".\\Users\\users.csv", ios::out | ios::app);
//	fout << "_USERNAME_, _PASSWORD_, _NAME_, _GENDER_, _AGE_, _HEIGHT_, _WEIGHT_ \n";
//	fout.close();
//}
void rejestracja::formularzRejestracyjny()
{
	cout << "********************************************************************\n\n";
	cout << "**************************   REJESTRACJA   *************************\n\n";
	cout << "********************************************************************\n\n";

	string username, password, name, gender;
	int age, height;
	float weight;
	cout << "Wpisz swoj login: "; cin >> username;
	if (sprawdzCzyUzytkownikIstnieje(username))
		return;
	cout << "Wpisz swoje haslo: "; cin >> password;
	cout << "Wpisz swoje imie: "; cin >> name;
	cout << "Wpisz swoja plec: "; cin >> gender;
	cout << "Wpisz swoj wiek: "; cin >> age;
	cout << "Wpisz swoj wzrost: "; cin >> height;
	cout << "Wpisz swoja wage: "; cin >> weight;
	wpiszDoPliku(username, password, name, gender, age, height, weight);
	cout << "Rejestracja powiodla sie. Prosze sie zalogowac." << endl;
	system("pause");
}
