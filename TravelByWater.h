#pragma once
#include <iostream>

#include "TravelData.h"

class TravelByWater : public TravelData
{
private:
	struct TravelByWaterData : BasicTravelData {
		std::string nameCompany = "", type = "", sched = "";
		Destination port;
	};

protected:
	struct TravelByWaterListNode {
		// Pointer Member
		TravelByWaterListNode* afterMe = nullptr, * beforeMe = nullptr;

		// Data Member
		TravelByWaterData travelData;
	};

public:
	void ListOfTravelsByWater(TravelByWaterListNode*);
	void AddTravelsByWater(TravelByWaterListNode*&, TravelByWaterListNode*&, int&);
	void UpdateWaterTravelData(TravelByWaterListNode*);
	void DeleteWaterTravelData(TravelByWaterListNode*& head, TravelByWaterListNode*& tail);

private:
	int UpdateWaterTravelDataMenu();

	void RegisterNewTravelByWater(TravelByWaterListNode*, int&);
	void DisplayStrippedTravelByWaterList(TravelByWaterListNode*);
	TravelByWaterListNode* SearchTravelByWater(TravelByWaterListNode*);
};

