#include "dobieranieDiety.h"

int dobieranieDiety::wyborIlosciPosilkow()
{
	int position = 1;
	int key = 0;
	cout<<"Hello";
	while (true) //13 to enter
	{
		system("cls");
		cout << "********************************************************************\n\n";
		cout << "**********   UZYTKOWNIK Z KONTEM WYBOR ILOSCI POSILKOW   ***********\n\n";
		cout << "********************************************************************\n\n";
		std::cout << "Wybierz ilosc posilkow dziennie: \n";
		menu::arrow(1, position);	 cout << "3 posilki dziennie" << endl;
		menu::arrow(2, position);	 cout << "4 posilki dziennie" << endl;
		menu::arrow(3, position);	 cout << "5 posilkow dziennie" << endl;

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
			return 5;
		}
	}

	return 0;
}

int dobieranieDiety::przekierowanieWyborIlosciPosilkow()
{
	int state;
	while (true)
	{
		state = wyborIlosciPosilkow();
		if (state == 1) {
			ifstream file;
			file.open("Dieta\\3posilkow.csv", ios::out | ios::app);
			cout << endl;
			for (int i = 1; i <= 55; i++) {
				string field = to_string(i);
				getline(file, field, '\n');
				cout << field << endl;
			}
			file.close();
			system("pause");
		}
		if (state == 2) {
			ifstream file;
			file.open("Dieta\\4posilkow.csv", ios::out | ios::app);
			cout << endl;
			for (int i = 1; i <= 69; i++) {
				string field = to_string(i);
				getline(file, field, '\n');
				cout << field << endl;
			}
			file.close();
			system("pause");
		}
		if (state == 3) {
			ifstream file;
			file.open("Dieta\\5posilkow.csv", ios::out | ios::app);
			cout << endl;
			for (int i = 1; i <= 83; i++) {
				string field = to_string(i);
				getline(file, field, '\n');
				cout << field << endl;
			}
			file.close();
			system("pause");
		}
		if (state == 5) {
			return 0;
		}
	}
	return 0;
}
