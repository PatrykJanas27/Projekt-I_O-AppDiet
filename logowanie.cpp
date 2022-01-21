#include "logowanie.h"

using namespace std;

bool logowanie::szukajUzytkownika(std::string username, std::string password)
{
	string field_1, field_2, field_3, field_4;
	ifstream file;
	file.open(".\\Users\\" + username + ".csv");
	getline(file, field_1, ',');
	getline(file, field_2, '\n');
	getline(file, field_3, ',');
	getline(file, field_4, '\n');
	file.close();
	//cout << field_1 << "\t" << field_2 << endl;
	//cout << field_3 << "\t" << field_4 << endl;
	if (field_2 == username && field_4 == password) {
		cout << "Zalogowano." << endl;
		system("pause");
		return true;
	}
	else {
		cout << "Bledne dane." << endl;
		system("pause");
		return false;
	}
}

std::string logowanie::getLogin()
{
	return this->username;
}

bool logowanie::formularzLogowania()
{
	bool status = false;
	cout << "********************************************************************\n\n";
	cout << "***************************   LOGOWANIE   **************************\n\n";
	cout << "********************************************************************\n\n";
	string _username, password;
	cout << "Podaj login: "; cin >> _username;
	cout << "Podaj haslo: "; cin >> password;
	if (szukajUzytkownika(_username, password)) {
		status = true;
		this->username = _username;
		return status;
	}
	return status;
}

