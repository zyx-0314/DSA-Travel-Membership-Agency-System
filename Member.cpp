#include "Member.h"

void Member::RegisterNewMember(MemberData& temp, int idNumber) {
	TravelData::CinString(temp.fName, "Enter First Name: ");
	TravelData::CinString(temp.lName, "Enter Last Name: ");
	temp.id = idNumber;

	system("cls");

	std::cout << "Member Registered\n\n";

	system("pause");
	system("cls");
}

void Member::ListOfMembers(MemberListNode* head) {
	if (head != nullptr)
	{
		DisplayStrippedMemberList(head);

		switch (MembersListMenu())
		{
		case 0:
			system("cls");
			return;
		case 1:
			// not needed for return
			MemberListNode * selected = SearchMember(head);
			if (selected != nullptr) {
				TravelsList(selected);
			}
			break;
		}
	}
	else {
		std::cout << "No data available to view yet!\n\n";
	}

	system("pause");
	system("cls");
}

void Member::UpdateMemberData(MemberListNode* head) {
	// we need to have the value of the pointer to edit
	MemberListNode* selected = SearchMember(head);

	switch (UpdateMemberMenu())
	{
	case 1:
		TravelData::CinString(selected->memberData.fName, "Enter First Name: ");
		break;
	case 2:
		TravelData::CinString(selected->memberData.lName, "Enter Last Name: ");
		break;
	}

	system("cls");
	std::cout << "Information has been updated!\n\n";
	system("pause");
	system("cls");
}

void Member::DeleteMemberData(MemberListNode*& head, MemberListNode*& tail) {
	// we need to have the value of the pointer to edit
	MemberListNode* selected = SearchMember(head);
	std::string choice;

	std::cout << "Do you want to continue [y/n] : ";
	std::cin >> choice;

	if (choice[0] == 'y')
	{
		if (head == selected) {
			// set the next node after the head to forget head
			head->afterMe->beforeMe = nullptr;
			head = head->afterMe;
		}
		if (tail == selected) {
			// set the before node before the tail to forget tail
			tail->beforeMe->afterMe = nullptr;
			tail = tail->beforeMe;
		}
		if (tail != selected && head != selected) {
			// set the node after the selected to remember who is before the selected
			selected->afterMe->beforeMe = selected->beforeMe;
			selected->beforeMe->afterMe = selected->afterMe;
		}
		delete selected;
	}

	system("cls");
}

int Member::MembersListMenu() {
	int choice = -1;

	do
	{
		std::cout
			<< "1. Check Data of User\n"
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

int Member::UpdateMemberMenu() {
	int choice = -1;

	do
	{
		std::cout
			<< "\n"
			<< "-- Update User Informations --\n\n"
			<< "1. First Name\n"
			<< "2. Last Name\n"
			<< "0. Exit\n"
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

	system("cls");
	return choice;
}

int Member::TravelDataMenu() {
	int choice = -1;

	do
	{
		std::cout
			<< "\n"
			<< "-- User Travel Informations --\n\n"
			<< "1. Display Travel Data List\n"
			<< "2. Add Travel Data\n"
			<< "3. Update Travel Data\n"
			<< "4. Delete Travel Data\n"
			<< "0. Exit\n"
			<< "\n"
			<< ":: ::\b\b\b";
		std::cin >> choice;

		if (0 > choice || choice > 4) {
			system("cls");
			std::cout << "Please ake sure to select from choices only\n\n";
			system("pause");
			system("cls");
		}
	} while (0 > choice || choice > 4);

	system("cls");
	return choice;
}

int Member::TypeOfTravelMenu(int totalTravel) {
	int choice = -1;

	do
	{
		std::cout
			<< "-- Total Travel: " << totalTravel << " --\n"
			<< "1. Land\n"
			<< "2. Water\n"
			<< "3. Air\n"
			<< "0. Exit\n"
			<< "\n"
			<< ":: ::\b\b\b";
		std::cin >> choice;

		if (0 > choice || choice > 3) {
			system("cls");
			std::cout << "Please ake sure to select from choices only\n\n";
			system("pause");
			system("cls");
		}
	} while (0 > choice || choice > 3);

	system("cls");
	return choice;
}

void Member::TravelsList(MemberListNode* selected) {
	int total = selected->memberData.travelCounterByAir + selected->memberData.travelCounterByLand + selected->memberData.travelCounterByWater;

	while (true) {
		switch (TravelDataMenu()) {
		case 1:
			switch (TypeOfTravelMenu(total))
			{
			case 1:
				ListOfTravelsByLand(selected->memberData.travelByLandhead);
				break;
			case 2:
				ListOfTravelsByWater(selected->memberData.travelByWaterhead);
				break;
			case 3:
				ListOfTravelsByAir(selected->memberData.travelByAirhead);
				break;
			case 0:
				return;
			}
			break;
		case 2:
			switch (TypeOfTravelMenu(total))
			{
			case 1:
				AddTravelsByLand(selected->memberData.travelByLandhead, selected->memberData.travelByLandtail, selected->memberData.travelCounterByLand);
				break;
			case 2:
				AddTravelsByWater(selected->memberData.travelByWaterhead, selected->memberData.travelByWatertail, selected->memberData.travelCounterByWater);
				break;
			case 3:
				AddTravelsByAir(selected->memberData.travelByAirhead, selected->memberData.travelByAirtail, selected->memberData.travelCounterByAir);
				break;
			case 0:
				return;
			}
			break;
		case 3:
			switch (TypeOfTravelMenu(total))
			{
			case 1:
				UpdateLandTravelData(selected->memberData.travelByLandhead);
				break;
			case 2:
				UpdateWaterTravelData(selected->memberData.travelByWaterhead);
				break;
			case 3:
				UpdateAirTravelData(selected->memberData.travelByAirhead);
				break;
			case 0:
				return;
			}
			break;
		case 4:
			switch (TypeOfTravelMenu(total))
			{
			case 1:
				DeleteLandTravelData(
					selected->memberData.travelByLandhead,
					selected->memberData.travelByLandtail
				);
				break;
			case 2:
				DeleteWaterTravelData(
					selected->memberData.travelByWaterhead,
					selected->memberData.travelByWatertail
				);
				break;
			case 3:
				DeleteAirTravelData(
					selected->memberData.travelByAirhead,
					selected->memberData.travelByAirtail
				);
				break;
			case 0:
				return;
			}
			break;
		case 0:
			return;
		}
	}
}

void Member::DisplayStrippedMemberList(MemberListNode* head)
{
	MemberListNode* current = head;

	system("cls");
	do
	{
		std::cout << current->memberData.id << " - " << current->memberData.lName << ", " << current->memberData.fName << ": " << current->memberData.level << "\n";
		current = current->afterMe;
	} while (current != nullptr);

	std::cout << "\n";
}

Member::MemberListNode* Member::SearchMember(MemberListNode* head)
{
	MemberListNode* current = head;
	bool isFound = false;
	int idNeeded;

	system("cls");

	DisplayStrippedMemberList(current);

	std::cout << "Enter User ID: ";
	std::cin >> idNeeded;
	system("cls");

	do
	{
		if (current->memberData.id == idNeeded)
		{
			isFound = true;
			std::cout
				<< "-- Member " << current->memberData.lName << " " << current->memberData.fName << " --\n"
				<< "ID    " << current->memberData.id << "\n"
				<< "Level " << current->memberData.level << "\n"
				<< "Exp   " << current->memberData.exp << "\n"
				<< "- Total Travels: " << current->memberData.travelCounterByAir + current->memberData.travelCounterByLand + current->memberData.travelCounterByWater << "\n"
				<< " > Land  " << current->memberData.travelCounterByLand << "\n"
				<< " > Water " << current->memberData.travelCounterByWater << "\n"
				<< " > Air   " << current->memberData.travelCounterByAir << "\n";
			return current;
		}
		current = current->afterMe;
	} while (current != nullptr);

	if (!isFound)
	{
		std::cout << "User ID is Invalid\n";
	}

	return nullptr;
}
