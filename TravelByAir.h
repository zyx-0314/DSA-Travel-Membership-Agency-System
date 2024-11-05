#pragma once
#include <iostream>

#include "TravelData.h"

class TravelByAir : public TravelData
{
private:
	struct TravelByAirData : BasicTravelData {
		std::string nameOfAirline = "", sched = "", seatType = "";
		Destination airport;
	};

protected:
	struct TravelByAirListNode {
		// Pointer Member
		TravelByAirListNode* afterMe = nullptr, * beforeMe = nullptr;

		// Data Member
		TravelByAirData travelData;
	};

public:
	void ListOfTravelsByAir(TravelByAirListNode*);
	void AddTravelsByAir(TravelByAirListNode*&, TravelByAirListNode*&, int&);
	void UpdateAirTravelData(TravelByAirListNode*);
	void DeleteAirTravelData(TravelByAirListNode*& head, TravelByAirListNode*& tail);

private:
	int UpdateAirTravelDataMenu();

	void RegisterNewTravelByAir(TravelByAirListNode*, int&);
	void DisplayStrippedTravelByAirList(TravelByAirListNode*);
	TravelByAirListNode* SearchTravelByAir(TravelByAirListNode*);
};

