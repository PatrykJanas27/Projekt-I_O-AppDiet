#include "ObliczanieBMI.h"

double ObliczanieBMI::kalkulatorBMI(float weight, int height, std::string argBMI)
{
	if (argBMI == "bez konta") {
		std::cout << "********************************************************************\n\n";
		std::cout << "*********************   UZYTKOWNIK BEZ KONTA   *********************\n\n";
		std::cout << "********************************************************************\n\n";
	}
	if (argBMI == "z kontem") {
		std::cout << "********************************************************************\n\n";
		std::cout << "*********************   UZYTKOWNIK Z KONTEM   **********************\n\n";
		std::cout << "********************************************************************\n\n";
	}
	
	BMI = 10000*(weight / pow(height, 2));
	std::cout << "Twoje BMI wynosi: " << BMI << std::endl;
	system("pause");
	return BMI;
}

double ObliczanieBMI::getBMI()
{
	return BMI;
}

//double ObliczanieBMI::setBMI()
//{
//	return BMI;
//}
