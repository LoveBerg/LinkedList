#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct LinkedList LinkedList;

Node* getDestination(LinkedList *List, int id);

Node* createNode(int id, char* txt);

void addNewNode(struct LinkedList *List, int id, char *txt);

void popLastNode(LinkedList *List);

void newLRU(LinkedList *List, Node *recentlyUsed, Node *beforeRecentlyUsed);

void main();