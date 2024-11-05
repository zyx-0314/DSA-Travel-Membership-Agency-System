#pragma once
#include <iostream>

#include "TravelData.h"

class TravelByLand : public TravelData
{
private:
	struct TravelByLandData : BasicTravelData {
		std::string nameCompany = "", type = "";
		Destination destination;
	};

protected:
	struct TravelByLandListNode {
		// Pointer Member
		TravelByLandListNode* afterMe = nullptr, * beforeMe = nullptr;

		// Data Member
		TravelByLandData travelData;
	};

public:
	void ListOfTravelsByLand(TravelByLandListNode*);
	void AddTravelsByLand(TravelByLandListNode*&, TravelByLandListNode*&, int&);
	void UpdateLandTravelData(TravelByLandListNode*);
	void DeleteLandTravelData(TravelByLandListNode*& head, TravelByLandListNode*& tail);

private:
	int UpdateLandTravelDataMenu();

	void RegisterNewTravelByLand(TravelByLandListNode*, int&);
	void DisplayStrippedTravelByLandList(TravelByLandListNode*);
	TravelByLandListNode* SearchTravelByLand(TravelByLandListNode*);
};
