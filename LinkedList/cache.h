#pragma once
#include <string>

extern "C" {
#include "LinkedList.h"
}

class cache
{
private:
	LinkedList * linkedlist;
public:
	cache();
	void AddToCache(int id, std::string txt);
	std::string GetFromCache(int id);
};
