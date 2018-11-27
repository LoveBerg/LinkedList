#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "DisplayMessageEndpoint.h"
#include "linkedList.h"
#include <Windows.h>
#include "cache.h"

std::string GetDestinationFrom(int destinationId, cache *cache)
{
	DisplayMessageDestinationService service;
	std::string destination(cache->GetFromCache(destinationId));
	if (destination.empty()) {
		destination = service.GetDestinationName(destinationId);
		cache->AddToCache(destinationId, destination);
		return destination;
	}
	else
	{
		return destination;
	}
}

int main()
{
	SetConsoleOutputCP(1252);
	cache* LRUcache = new cache();
	
	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, LRUcache)
			<< std::endl;
	}
}