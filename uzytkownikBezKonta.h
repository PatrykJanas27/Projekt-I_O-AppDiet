#include "menu.h"
#include <iostream>
#include <conio.h>
#include "ObliczanieBMI.h"
#include "ObliczanieZK.h"

#pragma once
class uzytkownikBezKonta : public menu
{
private:
    string gender;
    int age = NULL;
    int height = NULL;
    float weight = NULL;
    int wyborUzytkownikBezKonta();
public:
    string getGender();
    float getWeight();
    int getHeight();
    int getAge();
    void formularzUzytkownikBezKonta();
    int przekierowanieMenuUzytkownikBezKonta();
};

