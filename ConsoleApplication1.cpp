// Create a system that records travels using a membership system
// it is available to store data of travel booking in 3 types of travel: by land, by water or by air

#include <iostream>

// Support Data Structure of Informations
struct BasicTravelData {
	std::string date = "", status = "";
	int id = 0;
};

struct Destination {
	std::string origin = "", target = "";
};

// Main Data Structure of Informations
struct TravelByLandData : BasicTravelData {
	std::string nameCompany = "", type = "";
	Destination destination;
};

// Main Data Structure of Informations
struct TravelByWaterData : BasicTravelData {
	std::string nameCompany = "", type = "", sched = "";
	Destination port;
};

// Main Data Structure of Informations
struct TravelByAirData : BasicTravelData {
	std::string nameOfAirline = "", sched = "", seatType = "";
	Destination airport;
};

// Node Data Structure
struct TravelByLandListNode {
	// Pointer Member
	TravelByLandListNode* afterMe = nullptr, * beforeMe = nullptr;

	// Data Member
	TravelByLandData travelData;
};

// Node Data Structure
struct TravelByWaterListNode {
	// Pointer Member
	TravelByWaterListNode* afterMe = nullptr, * beforeMe = nullptr;

	// Data Member
	TravelByWaterData travelData;
};

// Node Data Structure
struct TravelByAirListNode {
	// Pointer Member
	TravelByAirListNode* afterMe = nullptr, * beforeMe = nullptr;

	// Data Member
	TravelByAirData travelData;
};

// Main Data Structure of Informations
struct MemberData {
	std::string fName = "", lName = "";
	int level = 1, exp = 0, id = 0, travelCounterByAir = 0, travelCounterByLand = 0, travelCounterByWater = 0;

	// List of connected list of travels tracked by the organization
	TravelByAirListNode* travelByAirhead = nullptr, * travelByAirtail = nullptr;
	TravelByLandListNode* travelByLandhead = nullptr, * travelByLandtail = nullptr;
	TravelByWaterListNode* travelByWaterhead = nullptr, * travelByWatertail = nullptr;
};

// Node Data Structure
struct MemberListNode {
	// Pointer Member
	MemberListNode* afterMe = nullptr, * beforeMe = nullptr;

	// Data Member
	MemberData memberData;
};

// Protypes
// Menu Function
int MainMenu();
int MembersListMenu();
int UpdateMemberMenu();
int TravelDataMenu();
int TravelsListMenu();

int TypeOfTravelMenu(int);

// Functioning Function
void RegisterNewMember(MemberData&, int);
void ListOfMembers(MemberListNode*);
void UpdateMemberData(MemberListNode*);
void DeleteMemberData(MemberListNode*&, MemberListNode*&);

void TravelsList(MemberListNode*);

void ListOfTravelsByLand(TravelByLandListNode*);
void AddTravelsByLand(TravelByLandListNode*&, TravelByLandListNode*&, int&);
void RegisterNewTravelByLand(TravelByLandListNode*, int&);
void UpdateLandTravelData(TravelByLandListNode*);
void DeleteLandTravelData(TravelByLandListNode*& head, TravelByLandListNode*& tail);

void ListOfTravelsByWater(TravelByWaterListNode*);
void AddTravelsByWater(TravelByWaterListNode*&, TravelByWaterListNode*&, int&);
void RegisterNewTravelByWater(TravelByWaterListNode*, int&);
void UpdateWaterTravelData(TravelByWaterListNode*);
void DeleteWaterTravelData(TravelByWaterListNode*& head, TravelByWaterListNode*& tail);

void ListOfTravelsByAir(TravelByAirListNode*);
void AddTravelsByAir(TravelByAirListNode*&, TravelByAirListNode*&, int&);
void RegisterNewTravelByAir(TravelByAirListNode*, int&);
void UpdateAirTravelData(TravelByAirListNode*);
void DeleteAirTravelData(TravelByAirListNode*& head, TravelByAirListNode*& tail);

// Helper Function
void CinString(std::string&, std::string);
std::string StatusSetter();

void DisplayStrippedMemberList(MemberListNode*);
MemberListNode* SearchMember(MemberListNode*);

void DisplayStrippedTravelByLandList(TravelByLandListNode*);
TravelByLandListNode* SearchTravelByLand(TravelByLandListNode*);

void DisplayStrippedTravelByWaterList(TravelByWaterListNode*);
TravelByWaterListNode* SearchTravelByWater(TravelByWaterListNode*);

void DisplayStrippedTravelByAirList(TravelByAirListNode*);
TravelByAirListNode* SearchTravelByAir(TravelByAirListNode*);

int main() {
	// list of my members
	MemberListNode* head = nullptr, * tail = nullptr, * temp = nullptr;
	int idCounter = 1;

	do
	{
		switch (MainMenu())
		{
		case 1:
			temp = new MemberListNode;

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

			RegisterNewMember(temp->memberData, idCounter);
			idCounter++;
			break;
		case 2:
			ListOfMembers(head);
			break;
		case 3:
			UpdateMemberData(head);
			break;
		case 4:
			DeleteMemberData(head, tail);
			break;
		case 0:
			return 0;
			break;
		}
	} while (true);
	// Crud

}

// Menu Functions
int MainMenu()
{
	int choice = -1;

	do
	{
		std::cout
			<< "1. Add a new member\n"
			<< "2. List of all members\n"
			<< "3. Update Data of member\n"
			<< "4. Delete a member\n"
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

int MembersListMenu() {
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

int UpdateMemberMenu() {
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

int TravelDataMenu() {
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

int TypeOfTravelMenu(int totalTravel) {
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

int TravelsListMenu() {
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

int UpdateLandTravelDataMenu() {
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

int UpdateWaterTravelDataMenu() {
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

int UpdateAirTravelDataMenu() {
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

// Functioning Functions
void RegisterNewMember(MemberData& temp, int idNumber) {
	CinString(temp.fName, "Enter First Name: ");
	CinString(temp.lName, "Enter Last Name: ");
	temp.id = idNumber;

	system("cls");

	std::cout << "Member Registered\n\n";

	system("pause");
	system("cls");
}

void ListOfMembers(MemberListNode* head) {
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

void UpdateMemberData(MemberListNode* head) {
	// we need to have the value of the pointer to edit
	MemberListNode* selected = SearchMember(head);

	switch (UpdateMemberMenu())
	{
	case 1:
		CinString(selected->memberData.fName, "Enter First Name: ");
		break;
	case 2:
		CinString(selected->memberData.lName, "Enter Last Name: ");
		break;
	}

	system("cls");
	std::cout << "Information has been updated!\n\n";
	system("pause");
	system("cls");
}

void DeleteMemberData(MemberListNode*& head, MemberListNode*& tail) {
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

void TravelsList(MemberListNode* selected) {
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

void ListOfTravelsByLand(TravelByLandListNode* head)
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

void RegisterNewTravelByLand(TravelByLandListNode* node, int& counter)
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

void AddTravelsByLand(TravelByLandListNode*& head, TravelByLandListNode*& tail, int& counter) {
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

void DeleteLandTravelData(TravelByLandListNode*& head, TravelByLandListNode*& tail) {
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

void ListOfTravelsByWater(TravelByWaterListNode* head)
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

void RegisterNewTravelByWater(TravelByWaterListNode* node, int& counter)
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

void AddTravelsByWater(TravelByWaterListNode*& head, TravelByWaterListNode*& tail, int& counter) {
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

void DeleteWaterTravelData(TravelByWaterListNode*& head, TravelByWaterListNode*& tail) {
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

void ListOfTravelsByAir(TravelByAirListNode* head)
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

void RegisterNewTravelByAir(TravelByAirListNode* node, int& counter)
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

void AddTravelsByAir(TravelByAirListNode*& head, TravelByAirListNode*& tail, int& counter) {
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

void DeleteAirTravelData(TravelByAirListNode*& head, TravelByAirListNode*& tail) {
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

// Helper Function
void CinString(std::string& storage, std::string instruction) {
	std::cout << instruction << "\n";
	std::cin >> storage;
}

std::string StatusSetter() {
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

void DisplayStrippedMemberList(MemberListNode* head) {
	MemberListNode* current = head;

	system("cls");
	do
	{
		std::cout << current->memberData.id << " - " << current->memberData.lName << ", " << current->memberData.fName << ": " << current->memberData.level << "\n";
		current = current->afterMe;
	} while (current != nullptr);

	std::cout << "\n";
}

MemberListNode* SearchMember(MemberListNode* head) {
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

void DisplayStrippedTravelByLandList(TravelByLandListNode* head) {
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

TravelByLandListNode* SearchTravelByLand(TravelByLandListNode* head) {
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

void UpdateLandTravelData(TravelByLandListNode* head) {
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


void DisplayStrippedTravelByWaterList(TravelByWaterListNode* head) {
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

TravelByWaterListNode* SearchTravelByWater(TravelByWaterListNode* head) {
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

void UpdateWaterTravelData(TravelByWaterListNode* head) {
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

void DisplayStrippedTravelByAirList(TravelByAirListNode* head) {
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

TravelByAirListNode* SearchTravelByAir(TravelByAirListNode* head) {
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

void UpdateAirTravelData(TravelByAirListNode* head) {
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
