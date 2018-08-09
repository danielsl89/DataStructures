#include "EntityRingList.h"
#include <iostream>
using namespace std;
EntityRingList::EntityRingList(int c) {
	capacity = c;
	size = 0;
	head = nullptr;
	tail = nullptr;
}

EntityRingList::~EntityRingList() {
	EntityListNode *currentNode = head;
	EntityListNode *nodeToDelete = nullptr;

	while(size > 0) {
		nodeToDelete = currentNode;
		currentNode = currentNode->nextNode;
		delete nodeToDelete;
		size--;
	}
}


void EntityRingList::Push(Entity *newEntity) {
	EntityListNode *node = new EntityListNode();
	node->entity = newEntity;

	//If empty list
	if (head == nullptr) {
		head = node;
		tail = node;
		tail->nextNode = node;
		size++;
	}
	else {
		tail->nextNode = node;
		tail = node;
		if (size == capacity) {
			head = head->nextNode;
		}
		else
		{
			size++;
		}
		tail->nextNode = head;
	}
}

Entity* EntityRingList::operator[](int index) {
	EntityListNode *currentNode = head;
	for (int i = 0; i < index; i++) {
		currentNode = currentNode->nextNode;
	}
	return currentNode->entity;
}
