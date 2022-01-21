#include "rejestracja.h"
#include "logowanie.h"
#include "uzytkownikZKontem.h"
#include "informacjeOAplikacji.h"
int main()
{
    menu dietApp;
    int state;
    while (true)
    {
        state = dietApp.mainMenu();
        switch (state)
        {
        case 1:
        {
            system("cls");
            rejestracja* newUser = new rejestracja;
            newUser->formularzRejestracyjny();
            delete newUser;
        }
            break;
        case 2:
        {
            system("cls");
            logowanie* existingUser = new logowanie;
            if (existingUser->formularzLogowania()) {
                uzytkownikZKontem* userWithAccount = new uzytkownikZKontem;
                string str = existingUser->getLogin();
                userWithAccount->updateUzytkownik(str);
                userWithAccount->przekierowanieUzytkownikaZKontem();
                delete existingUser;
                delete userWithAccount;        
            }
            break;
        }
        case 3:
        {
            system("cls");
            uzytkownikBezKonta* userWithoutAccount = new uzytkownikBezKonta;
            userWithoutAccount->formularzUzytkownikBezKonta();
            userWithoutAccount->przekierowanieMenuUzytkownikBezKonta();
            delete userWithoutAccount;
            break;
        }

        case 4:
        {
            informacjeOAplikacji* inform = new informacjeOAplikacji;
            inform->wypiszInformacje();
            delete inform;
            break;
        }        
        case 5:
            return 0;
        }
    }
}