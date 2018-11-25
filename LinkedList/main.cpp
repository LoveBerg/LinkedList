#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "DisplayMessageEndpoint.h"
#include "linkedList.h"
#include <Windows.h>

std::string GetDestinationFrom(int destinationId)
{
	TXT = getFromID()
	DisplayMessageDestinationService service;
	return service.GetDestinationName(destinationId);
	//This call is really slow!!!

	//Uppgift: Skapa en LRU cache...
	//Du får dock spara högst 10 st för det finns så lite minne i displayen

	//1. Skapa en C-only linkedlist - varför? - den ska användas i en c-only device senare.. 
	//struct Node
	//{
	//	int id;
	//	char *txt;
	//	struct Node *next;
	//};
	//kom ihåg att malloc och free på både noder och char *

	//2. Anropa denna härifrån sas
	// if linkedlist_get(id) == NULL
	//{
	//fetch from remote service.GetDestinationName(destinationId)
	//	Add to linked list (FRONT)
	//	Ta bort sista om > 10!
	//}
	//else if linkedlist_get(id) != NULL
	//	Move it to FRONT!
	//
}

void main()
{
	SetConsoleOutputCP(1252);
	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId)
			<< std::endl;
	}
}