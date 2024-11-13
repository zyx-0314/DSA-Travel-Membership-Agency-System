#include "TravelData.h"

int TravelData::TravelsListMenu()
{
	int choice = -1;

	do
	{
		std::cout
			<< "1. Check Data of Travels\n"
			<< "0. Exit\n"
			<< "\n"
			<< ":: ::\b\b\b";
		std::cin >> choice;

		if (0 > choice || choice > 1) {
			system("cls");
			std::cout << "Please ake sure to select from choices only\n\n";
			system("pause");
			system("cls");
		}
	} while (0 > choice || choice > 1);

	system("cls");
	return choice;
}

void TravelData::CinString(std::string& storage, std::string instruction)
{
	std::cout << instruction << "\n";
	std::cin >> storage;
}

std::string TravelData::StatusSetter()
{
	int choice;

	do
	{
		std::cout
			<< "-- Status --\n"
			<< "1. Complete\n"
			<< "2. Cancelled\n"
			<< "\n"
			<< ":: ::\b\b\b";
		std::cin >> choice;
		if (0 > choice || choice > 2) {
			system("cls");
			std::cout << "Please ake sure to select from choices only\n\n";
			system("pause");
			system("cls");
		}
	} while (0 > choice || choice > 2);

	switch (choice)
	{
	case 1:
		return "Complete";
		break;
	case 2:
		return "Cancelled";
		break;
	}
}


