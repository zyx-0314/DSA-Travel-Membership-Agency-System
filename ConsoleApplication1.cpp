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

// Functioning Function
void RegisterNewMember(MemberData&, int);
void ListOfMembers(MemberListNode*);
void UpdateMemberData(MemberListNode*);
void DeleteMemberData(MemberListNode*&,MemberListNode*&);

// Helper Function
void CinString(std::string&, std::string);
void DisplayList(MemberListNode*);
MemberListNode* SearchMember(MemberListNode*);

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

int MainMenu()
{
	int choice = -1;

	system("cls");
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

	return choice;
}

void RegisterNewMember(MemberData& temp, int idNumber) {
	CinString(temp.fName, "Enter First Name: ");
	CinString(temp.lName, "Enter Last Name: ");
	temp.id = idNumber;

	system("cls");

	std::cout << "Member Registered\n\n";

	system("pause");
	system("cls");
}

void CinString(std::string& storage, std::string instruction) {
	std::cout << instruction << "\n";
	std::cin >> storage;
}

void ListOfMembers(MemberListNode* head) {
	if (head != nullptr)
	{
		DisplayList(head);

		switch (MembersListMenu())
		{
		case 1:
			// not needed for return
			SearchMember(head);

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

void DisplayList(MemberListNode* head) {
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

	DisplayList(current);

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
}