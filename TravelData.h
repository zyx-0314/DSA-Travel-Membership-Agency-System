#pragma once
#include <iostream>
#include <string>

class TravelData
{
protected:
	struct BasicTravelData {
		std::string date = "", status = "";
		int id = 0;
	};

	struct Destination {
		std::string origin = "", target = "";
	};

	int TravelsListMenu();
	void CinString(std::string&, std::string);
	std::string StatusSetter();
};

