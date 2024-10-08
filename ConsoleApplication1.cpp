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

// Helper Function
void CinString(std::string&, std::string);

void DisplayStrippedMemberList(MemberListNode*);
MemberListNode* SearchMember(MemberListNode*);

void DisplayStrippedTravelByLandList(TravelByLandListNode*);
void SearchTravelByLand(TravelByLandListNode*);

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
	switch (TravelDataMenu()) {
	case 1:
		switch (TypeOfTravelMenu(total))
		{
		case 1:
			ListOfTravelsByLand(selected->memberData.travelByLandhead);
			break;
		case 2:
			break;
		case 3:
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
			break;
		case 3:
			break;
		case 0:
			return;
		}
		break;
	case 3:
		switch (TypeOfTravelMenu(total))
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			return;
		}
		break;
	case 4:
		switch (TypeOfTravelMenu(total))
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			return;
		}
		break;
	case 0:
		return;
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
		node->travelData.status = "Complete";
		break;
	case 2:
		node->travelData.status = "Cancelled";
		break;
	}

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

// Helper Function
void CinString(std::string& storage, std::string instruction) {
	std::cout << instruction << "\n";
	std::cin >> storage;
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

void SearchTravelByLand(TravelByLandListNode* head) {
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
		}
		current = current->afterMe;
	} while (current != nullptr);

	if (!isFound)
	{
		std::cout << "Travel ID is Invalid\n";
	}
}

