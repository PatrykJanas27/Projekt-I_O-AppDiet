#include "menu.h"

void menu::arrow(int currentPosition, int arrowPosition)
{
	if (currentPosition == arrowPosition) {
		cout << "-->  ";
	}
	else {
		cout << " ";
	}
}

int menu::mainMenu()
{
	int position = 1;
	int key = 0;

	while (true) //13 to enter
	{
		system("cls");
		cout << "********************************************************************\n\n";
		cout << "**********************   Welcome to dietAPP   **********************\n\n";
		cout << "*****************************   MENU   *****************************\n\n";
		arrow(1, position);	 cout << "REJESTRACJA" << endl;
		arrow(2, position);	 cout << "LOGOWANIE" << endl;
		arrow(3, position);	 cout << "KONTYNUUJ BEZ KONTA" << endl;
		arrow(4, position);	 cout << "INFORMACJE O APLIKACJI" << endl;
		arrow(5, position);	 cout << "WYJDZ" << endl;

		cout << endl << "Next -> ENTER\t\t\t\t\t\t Back -> ESC" << endl;

		key = _getch();

		if (key == 80 && position != 5) {	//strzalka w dol
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
