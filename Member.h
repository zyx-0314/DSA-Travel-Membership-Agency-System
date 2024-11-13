#pragma once
#include <iostream>

#include "TravelByAir.h"
#include "TravelByLand.h"
#include "TravelByWater.h"

class Member : 
	public TravelByAir, public TravelByLand, public TravelByWater
{
private:
	struct MemberData {
		std::string fName = "", lName = "";
		int level = 1, exp = 0, id = 0, travelCounterByAir = 0, travelCounterByLand = 0, travelCounterByWater = 0;

		// List of connected list of travels tracked by the organization
		TravelByAirListNode* travelByAirhead = nullptr, * travelByAirtail = nullptr;
		TravelByLandListNode* travelByLandhead = nullptr, * travelByLandtail = nullptr;
		TravelByWaterListNode* travelByWaterhead = nullptr, * travelByWatertail = nullptr;
	};


public:
	struct MemberListNode {
		// Pointer Member
		MemberListNode* afterMe = nullptr, * beforeMe = nullptr;

		// Data Member
		MemberData memberData;
	};

	void RegisterNewMember(MemberData&, int);
	void ListOfMembers(MemberListNode*);
	void UpdateMemberData(MemberListNode*);
	void DeleteMemberData(MemberListNode*&, MemberListNode*&);


private:
	int MembersListMenu();
	int UpdateMemberMenu();
	int TravelDataMenu();
	int TypeOfTravelMenu(int);

	void TravelsList(MemberListNode*);
	void DisplayStrippedMemberList(MemberListNode*);
	MemberListNode* SearchMember(MemberListNode*);
};

