#include "ObliczanieZK.h"

void ObliczanieZK::kalkulatorZK(float weight, int height, int age, std::string gender, std::string argZK)
{
    if (argZK == "bez konta") {
        std::cout << "********************************************************************\n\n";
        std::cout << "*********************   UZYTKOWNIK BEZ KONTA   *********************\n\n";
        std::cout << "********************************************************************\n\n";
    }
    if (argZK == "z kontem") {
        std::cout << "********************************************************************\n\n";
        std::cout << "*********************   UZYTKOWNIK Z KONTEM   **********************\n\n";
        std::cout << "********************************************************************\n\n";
    }

    if (gender == "m" || gender == "mezczyzna" || gender == "M" || gender == "Mezczyzna" || gender == "MEZCZYZNA")
    {
        float x = 66 + 13.7 * weight + 5.1 * height - 6.8 * age;
        this->ZK = x;
    }
    if (gender == "k" || gender == "kobieta" || gender == "K" || gender == "Kobieta" || gender == "KOBIETA")
    {
        float x = 655 + 9.6 * weight + 1.8 * height - 4.7 * age;
        this->ZK = x;
    }

    std::cout << "Twoje PODSTAWOWE Zapotrzebowanie Kaloryczne wynosi: " << ZK << " kcal"<< std::endl;
    system("pause");
}

double ObliczanieZK::getZK()
{
    return this->ZK;
}

