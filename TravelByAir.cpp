#include "TravelByAir.h"

void TravelByAir::ListOfTravelsByAir(TravelByAirListNode* head)
{
	if (head != nullptr)
	{
		DisplayStrippedTravelByAirList(head);

		switch (TravelsListMenu())
		{
		case 1:
			// not needed for return
			SearchTravelByAir(head);

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

void TravelByAir::AddTravelsByAir(TravelByAirListNode*& head, TravelByAirListNode*& tail, int& counter)
{
	TravelByAirListNode* temp;
	temp = new TravelByAirListNode;

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

	RegisterNewTravelByAir(temp, counter);
}

void TravelByAir::RegisterNewTravelByAir(TravelByAirListNode* node, int& counter)
{
	CinString(node->travelData.nameOfAirline, "Enter Airline Name: ");
	CinString(node->travelData.seatType, "Enter Seat Type: ");
	CinString(node->travelData.date, "Enter Date [YYYY-MM-DD]: ");
	CinString(node->travelData.sched, "Enter Sched [XX-XX-A/PM]: ");
	CinString(node->travelData.airport.origin, "Enter Airline Origin: ");
	CinString(node->travelData.airport.target, "Enter Airline Destination: ");

	node->travelData.status = StatusSetter();

	node->travelData.id = ++counter;

	system("cls");

	std::cout << "Travel Registered\n\n";

	system("pause");
	system("cls");
}

void TravelByAir::UpdateAirTravelData(TravelByAirListNode* head)
{
	// we need to have the value of the pointer to edit
	TravelByAirListNode* selected = SearchTravelByAir(head);

	switch (UpdateAirTravelDataMenu())
	{
	case 1:
		CinString(selected->travelData.nameOfAirline, "Enter Airline Name: ");
		break;
	case 2:
		CinString(selected->travelData.sched, "Enter Updated Sched [XX-XX-A/PM]: ");
		break;
	case 3:
		CinString(selected->travelData.seatType, "Enter Updated Seat Type: ");
		break;
	case 4:
		CinString(selected->travelData.date, "Enter Updated Date  [YYYY-MM-DD]: ");
		break;
	case 5:
		CinString(selected->travelData.airport.origin, "Enter Updated Airline Origin: ");
		break;
	case 6:
		CinString(selected->travelData.airport.target, "Enter Updated Airline Destination: ");
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

void TravelByAir::DeleteAirTravelData(TravelByAirListNode*& head, TravelByAirListNode*& tail)
{
	// we need to have the value of the pointer to edit
	TravelByAirListNode* selected = SearchTravelByAir(head);
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

int TravelByAir::UpdateAirTravelDataMenu() {
	int choice = -1;

	do
	{
		std::cout
			<< "-- Update Air Travel Data\n"
			<< "1. Airline\n"
			<< "2. Schedule\n"
			<< "3. Seat type\n"
			<< "4. Date\n"
			<< "5. Airline Origin\n"
			<< "6. Airline Destination\n"
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

void TravelByAir::DisplayStrippedTravelByAirList(TravelByAirListNode* head)
{
	TravelByAirListNode* current = head;

	system("cls");
	do
	{
		std::cout
			<< current->travelData.id << ". " << current->travelData.date << " : "
			<< current->travelData.airport.origin << " -> " << current->travelData.airport.target
			<< " - " << current->travelData.seatType << " | " << current->travelData.status << " | "
			<< "\n";
		current = current->afterMe;
	} while (current != nullptr);

	std::cout << "\n";
}

TravelByAir::TravelByAirListNode* TravelByAir::SearchTravelByAir(TravelByAirListNode* head)
{
	TravelByAirListNode* current = head;
	bool isFound = false;
	int idNeeded;

	system("cls");

	DisplayStrippedTravelByAirList(current);

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
				<< "Airline  " << current->travelData.nameOfAirline << "\n"
				<< "Status   " << current->travelData.status << "\n"
				<< "Travel Data:\n"
				<< "> Seat Type     " << current->travelData.seatType << "\n"
				<< "> Origin        " << current->travelData.airport.origin << "\n"
				<< "> Destination   " << current->travelData.airport.target << "\n";
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
