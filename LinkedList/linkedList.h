#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	int id;
	char *txt;
	struct Node *next;
};

typedef struct LinkedList LinkedList;
struct LinkedList
{
	int count;
	Node *head;
};

char* getDestination(LinkedList *List, int id);

Node* createNode(int id, char* txt);

void addNewNode(struct LinkedList *List, int id, char *txt);

void popLastNode(LinkedList *List);

void newLRU(LinkedList *List, Node *recentlyUsed, Node *beforeRecentlyUsed);
