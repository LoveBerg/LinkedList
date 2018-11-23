#pragma once

#include <string>

class DisplayMessageEndpoint
{
public:
	typedef struct
	{
		std::string time;
		std::string newTime;
		int destinationId;
		std::string track;
		int trainNo;
	} DisplayEntry;

	DisplayEntry GetDisplayMessage();
private:
	int GetRandom(int from, int to);
	int RandomizeDestination();
};

class DisplayMessageDestinationService
{
public:
	std::string GetDestinationName(int id);
};