#include "dobieranieCwiczenia.h"


int dobieranieCwiczenia::wyborStopniaCwiczen()
{
	int position = 1;
	int key = 0;

	while (true) //13 to enter
	{
		system("cls");
		cout << "********************************************************************\n\n";
		cout << "*******   UZYTKOWNIK Z KONTEM WYBOR STOPNIA ZAAWANSOWANIA   ********\n\n";
		cout << "********************************************************************\n\n";
		std::cout << "Wybierz stopien zaawansowania: \n";
		menu::arrow(1, position);	 cout << "1. Poczatkujacy" << endl;
		menu::arrow(2, position);	 cout << "2. Sredniozaawansowany" << endl;
		menu::arrow(3, position);	 cout << "3. Zaawansowany" << endl;


		cout << endl << "Next -> ENTER\t\t\t\t\t\t Back -> ESC" << endl;

		key = _getch();

		if (key == 80 && position != 3) {	//strzalka w dol
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
			return 4;
		}
	}

	return 0;
}

int dobieranieCwiczenia::przekierowanieWyborStopniaCwiczen()
{
	int state;
	while (true)
	{
		state = wyborStopniaCwiczen();
		if (state == 1) {
			ifstream file;
			file.open("Trening\\treningPoczatkujacy.csv", ios::out | ios::app);
			cout << endl;
			for (int i = 1; i <= 21; i++) {
				string field = to_string(i);
				getline(file, field, '\n');
				cout << field << endl;
			}
			file.close();
			system("pause");
		}
		if (state == 2) {
			ifstream file;
			file.open("Trening\\treningSredniozaawansowany.csv", ios::out | ios::app);
			cout << endl;
			for (int i = 1; i <= 21; i++) {
				string field = to_string(i);
				getline(file, field, '\n');
				cout << field << endl;
			}
			file.close();
			system("pause");
		}
		if (state == 3) {
			ifstream file;
			file.open("Trening\\treningZaawansowany.csv", ios::out | ios::app);
			cout << endl;
			for (int i = 1; i <= 19; i++) {
				string field = to_string(i);
				getline(file, field, '\n');
				cout << field << endl;
			}
			file.close();
			system("pause");
		}
		if (state == 4) {
			return 0;
		}
		
	}
	return 0;
}