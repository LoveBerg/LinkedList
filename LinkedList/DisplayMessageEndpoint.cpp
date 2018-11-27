#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "DisplayMessageEndpoint.h"
#include <random>
#include <sstream>
#include <iomanip>
#include <Windows.h>


std::vector<std::string> destinations = {
	"Stockholm",
	"Goteborg",
	"Hallsberg",
	"Malmo",
	"V�steras",
	"Uppsala",
	"Sundsvall",
	"Gavle",
	"Kalmar",
	"Falun",
	"Linkoping",
	"Oslo",
	"Orebro",
	"Sodertalje",
	"Umea",
	"Kiruna",
	"Karlstad",
	"Norrk�ping",
	"Kopenhamn",
	"Helsingborg",
	"Vaxj�"
};

int DisplayMessageEndpoint::GetRandom(int start, int slut)
{
	std::random_device rd; 
	std::mt19937 eng(rd()); 
	std::uniform_int_distribution<> distr(start, slut); 
	return distr(eng);
}

int DisplayMessageEndpoint::RandomizeDestination()
{
	int max = destinations.size() + 10;

	int sum = 0;
	for (int i = 0; i < destinations.size(); i++)
		sum += max - i;
	int rand = GetRandom(0,sum-1);
	sum = 0;
	for (int i = 0; i < destinations.size(); i++)
	{
		sum += max - i;
		if (sum > rand) return i;
	}
	return sizeof(destinations)-1;
}

std::string DisplayMessageDestinationService::GetDestinationName(int id)
{
	Sleep(3000);
	return destinations[id];
}

DisplayMessageEndpoint::DisplayEntry DisplayMessageEndpoint::GetDisplayMessage()
{
	DisplayMessageEndpoint::DisplayEntry entry;
	entry.trainNo = GetRandom(1, 1000);
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << GetRandom(0,23)
		<< std::setw(1)
		<< ":" << std::setw(2) << std::setfill('0') << GetRandom(0, 59);
	entry.time = ss.str();
	entry.track = std::to_string(GetRandom(1, 20));
	if (GetRandom(0, 100) > 97)
		entry.newTime = "INST�LLT";
	else if (GetRandom(0, 100) > 92)
	{
		std::stringstream ns;
		ns << std::setw(2) << std::setfill('0') << GetRandom(0, 23)
			<< std::setw(1)
			<< ":" << std::setw(2) << std::setfill('0') << GetRandom(0, 59);
		entry.newTime = ns.str();
	}
	entry.destinationId = RandomizeDestination();
	return entry;
}


