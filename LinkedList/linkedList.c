#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

#define CASHE_MAX 10


struct Node
{
	int id;
	char *txt;
	struct Node *next;
};

struct LinkedList
{
	Node *head;
	int count;
};


char* getDestination(LinkedList *List, int id) {
	Node* nodeHolder = List->head;
	if (nodeHolder->id == id)
		return nodeHolder;
	for (int i = 0; i < List->count; i++) {
		if (nodeHolder->next->id == id)
			newLRU(List, nodeHolder->next, nodeHolder);
			return nodeHolder->next->txt;
		nodeHolder = nodeHolder->next;
	}
	return NULL;
}
Node* createNode(int id, char* txt) {
	Node* newNode = malloc(sizeof(Node));
	newNode->txt = malloc(sizeof(char)*strlen(txt) + 1);
	strcpy(newNode->txt, txt);
	newNode->id = id;
	newNode->next = NULL;

	return newNode;
}
void addNewNode(LinkedList *List, int id, char *txt)
{
	Node* newNode = createNode(id, txt);
	if (List->count >= CASHE_MAX)
		popLastNode(List);
	else if (List->head != NULL)
		newNode->next = List->head;
	List->head = newNode;
	List->count++;
	
}
void popLastNode(LinkedList *List) {
	Node* nodeHolder = NULL;
	Node* newTail = NULL;
	nodeHolder = List->head;
	for (int i = 0; i < List->count -1; i++) {
		nodeHolder = nodeHolder->next;
		if (i == List->count - 1)
			newTail = nodeHolder;
	}
	free(nodeHolder->txt);
	free(nodeHolder);
	nodeHolder->txt = NULL;
	nodeHolder = NULL;
	
	newTail->next = NULL;
	List->count--;

 }
void newLRU(LinkedList *List, Node *recentlyUsed, Node *beforeRecentlyUsed) {
	beforeRecentlyUsed->next = recentlyUsed->next;
	recentlyUsed->next = List->head;
	List->head = recentlyUsed;
}
void main() {
}