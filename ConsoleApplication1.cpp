// Create a system that records travels using a membership system
// it is available to store data of travel booking in 3 types of travel: by land, by water or by air

#include <iostream>

#include "Member.h"

int MainMenu();

int main()
{
	// list of my members
	Member member;

	Member::MemberListNode* head = nullptr, * tail = nullptr, * temp = nullptr;
	int idCounter = 1;

	do
	{
		switch (MainMenu())
		{
		case 1:
			temp = new Member::MemberListNode;

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

			member.RegisterNewMember(temp->memberData, idCounter);
			idCounter++;
			break;
		case 2:
			member.ListOfMembers(head);
			break;
		case 3:
			member.UpdateMemberData(head);
			break;
		case 4:
			member.DeleteMemberData(head, tail);
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