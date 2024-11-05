#include "TravelByWater.h"

void TravelByWater::ListOfTravelsByWater(TravelByWaterListNode* head)
{
	if (head != nullptr)
	{
		DisplayStrippedTravelByWaterList(head);

		switch (TravelsListMenu())
		{
		case 1:
			// not needed for return
			SearchTravelByWater(head);

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

void TravelByWater::AddTravelsByWater(TravelByWaterListNode*& head, TravelByWaterListNode*& tail, int& counter)
{
	TravelByWaterListNode* temp;
	temp = new TravelByWaterListNode;

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

	RegisterNewTravelByWater(temp, counter);
}

void TravelByWater::RegisterNewTravelByWater(TravelByWaterListNode* node, int& counter)
{
	int choice;

	CinString(node->travelData.nameCompany, "Enter Company Name: ");
	CinString(node->travelData.type, "Enter Type of Water Transportation: ");
	CinString(node->travelData.date, "Enter Date [YYYY-MM-DD]: ");
	CinString(node->travelData.sched, "Enter Sched [XX-XX-A/PM]: ");
	CinString(node->travelData.port.origin, "Enter Port Origin: ");
	CinString(node->travelData.port.target, "Enter Port Destination: ");

	node->travelData.status = StatusSetter();

	node->travelData.id = ++counter;

	system("cls");

	std::cout << "Travel Registered\n\n";

	system("pause");
	system("cls");
}

void TravelByWater::UpdateWaterTravelData(TravelByWaterListNode* head)
{
	// we need to have the value of the pointer to edit
	TravelByWaterListNode* selected = SearchTravelByWater(head);

	switch (UpdateWaterTravelDataMenu())
	{
	case 1:
		CinString(selected->travelData.nameCompany, "Enter Company Name: ");
		break;
	case 2:
		CinString(selected->travelData.sched, "Enter Updated Sched [XX-XX-A/PM]: ");
		break;
	case 3:
		CinString(selected->travelData.type, "Enter Updated Type: ");
		break;
	case 4:
		CinString(selected->travelData.date, "Enter Updated Date [YYYY-MM-DD]: ");
		break;
	case 5:
		CinString(selected->travelData.port.origin, "Enter Updated Port Origin: ");
		break;
	case 6:
		CinString(selected->travelData.port.target, "Enter Updated Port Destination: ");
		break;
	case 7:
		selected->travelData.status = StatusSetter();
		break;
	}


	system("cls");
	std::cout << "Information has been updated!\n\n";
	system("pause");
	system("cls");
}

void TravelByWater::DeleteWaterTravelData(TravelByWaterListNode*& head, TravelByWaterListNode*& tail)
{
	// we need to have the value of the pointer to edit
	TravelByWaterListNode* selected = SearchTravelByWater(head);
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

int TravelByWater::UpdateWaterTravelDataMenu() {
	int choice = -1;

	do
	{
		std::cout
			<< "-- Update Water Travel Data\n"
			<< "1. Port\n"
			<< "2. Schedule\n"
			<< "3. Type\n"
			<< "4. Date\n"
			<< "5. Port Origin\n"
			<< "6. Port Destination\n"
			<< "7. Status\n"
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

void TravelByWater::DisplayStrippedTravelByWaterList(TravelByWaterListNode* head)
{
	TravelByWaterListNode* current = head;

	system("cls");
	do
	{
		std::cout
			<< current->travelData.id << ". " << current->travelData.date << " : "
			<< current->travelData.port.origin << " -> " << current->travelData.port.target
			<< " - " << current->travelData.type << " | " << current->travelData.status << " | "
			<< "\n";
		current = current->afterMe;
	} while (current != nullptr);

	std::cout << "\n";
}

TravelByWater::TravelByWaterListNode* TravelByWater::SearchTravelByWater(TravelByWaterListNode* head)
{
	TravelByWaterListNode* current = head;
	bool isFound = false;
	int idNeeded;

	system("cls");

	DisplayStrippedTravelByWaterList(current);

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
				<< "> Origin        " << current->travelData.port.origin << "\n"
				<< "> Destination   " << current->travelData.port.target << "\n";
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


