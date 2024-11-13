#include "TravelByLand.h"

void TravelByLand::ListOfTravelsByLand(TravelByLandListNode* head)
{
	if (head != nullptr)
	{
		DisplayStrippedTravelByLandList(head);

		switch (TravelsListMenu())
		{
		case 1:
			// not needed for return
			SearchTravelByLand(head);

			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			return;
		}

	}
	else {
		std::cout << "No data available to view yet!\n\n";
		system("pause");
		system("cls");
	}
}

void TravelByLand::RegisterNewTravelByLand(TravelByLandListNode* node, int& counter)
{
	int choice;

	CinString(node->travelData.nameCompany, "Enter Company Name: ");
	CinString(node->travelData.type, "Enter Type of Land Transportation: ");
	CinString(node->travelData.date, "Enter Date [YYYY-MM-DD]: ");
	CinString(node->travelData.destination.origin, "Enter Origin: ");
	CinString(node->travelData.destination.target, "Enter Destination: ");

	node->travelData.status = StatusSetter();

	node->travelData.id = ++counter;

	system("cls");

	std::cout << "Travel Registered\n\n";

	system("pause");
	system("cls");
}

void TravelByLand::AddTravelsByLand(TravelByLandListNode*& head, TravelByLandListNode*& tail, int& counter) {
	TravelByLandListNode* temp;
	temp = new TravelByLandListNode;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else {
		tail->afterMe = temp;
		temp->beforeMe = tail; // advance part
		tail = temp;
	}

	RegisterNewTravelByLand(temp, counter);
}

void TravelByLand::DeleteLandTravelData(TravelByLandListNode*& head, TravelByLandListNode*& tail) {
	// we need to have the value of the pointer to edit
	TravelByLandListNode* selected = SearchTravelByLand(head);
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

void TravelByLand::UpdateLandTravelData(TravelByLandListNode* head)
{
	// we need to have the value of the pointer to edit
	TravelByLandListNode* selected = SearchTravelByLand(head);

	switch (UpdateLandTravelDataMenu())
	{
	case 1:
		CinString(selected->travelData.nameCompany, "Enter Company Name: ");
		break;
	case 2:
		CinString(selected->travelData.type, "Enter Updated Type: ");
		break;
	case 3:
		CinString(selected->travelData.date, "Enter Updated Date [YYYY-MM-DD]: ");
		break;
	case 4:
		CinString(selected->travelData.destination.origin, "Enter Updated Station Origin: ");
		break;
	case 5:
		CinString(selected->travelData.destination.target, "Enter Updated Station Destination: ");
		break;
	case 6:
		selected->travelData.status = StatusSetter();
		break;
	}


	system("cls");
	std::cout << "Information has been updated!\n\n";
	system("pause");
	system("cls");
}


int TravelByLand::UpdateLandTravelDataMenu()
{
	int choice = -1;

	do
	{
		std::cout
			<< "-- Update Land Travel Data\n"
			<< "1. Company\n"
			<< "2. Type\n"
			<< "3. Date\n"
			<< "4. Station Origin\n"
			<< "5. Station Destination\n"
			<< "6. Status\n"
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


void TravelByLand::DisplayStrippedTravelByLandList(TravelByLandListNode* head)
{
	TravelByLandListNode* current = head;

	system("cls");
	do
	{
		std::cout
			<< current->travelData.id << ". " << current->travelData.date << " : "
			<< current->travelData.destination.origin << " -> " << current->travelData.destination.target
			<< " - " << current->travelData.type << " | " << current->travelData.status << " | "
			<< "\n";
		current = current->afterMe;
	} while (current != nullptr);

	std::cout << "\n";
}

TravelByLand::TravelByLandListNode* TravelByLand::SearchTravelByLand(TravelByLandListNode* head)
{
	TravelByLandListNode* current = head;
	bool isFound = false;
	int idNeeded;

	system("cls");

	DisplayStrippedTravelByLandList(current);

	std::cout << "Enter User ID: ";
	std::cin >> idNeeded;
	system("cls");

	do
	{
		if (current->travelData.id == idNeeded)
		{
			isFound = true;
			std::cout
				<< "-- " << current->travelData.id << " --\n"
				<< "Date     " << current->travelData.date << "\n"
				<< "Company  " << current->travelData.nameCompany << "\n"
				<< "Status   " << current->travelData.status << "\n"
				<< "Travel Data:\n"
				<< "> Type          " << current->travelData.type << "\n"
				<< "> Origin        " << current->travelData.destination.origin << "\n"
				<< "> Destination   " << current->travelData.destination.target << "\n";
			return current;
		}
		current = current->afterMe;
	} while (current != nullptr);

	if (!isFound)
	{
		std::cout << "Travel ID is Invalid\n";
	}

	return nullptr;
}

