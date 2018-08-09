#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Entity.h"
#include "EntityVector.h"
#include "EntityRingList.h"
using namespace std;

int main() {

	//--------------- Entity Vector ---------------
	const int ENTITY_VECTOR_SIZE = 12;
	EntityVector *vector = new EntityVector();
	vector->Reserve(ENTITY_VECTOR_SIZE);

	srand(time(0));

	Entity *entity;
	//Creating some random entities between (-10;-10) and (10;10)
	for(int i = 0; i < ENTITY_VECTOR_SIZE; i++)
	{
		entity = new Entity();
		entity->m_x = rand() % 21 - 10;
		entity->m_y = rand() % 21 - 10;
		vector->PushBack(entity);

	}
	//Sorting around point (0;0)
	vector->Sort(*vector, 0, 0);

	cout << "Vector size: " << vector->GetSize() << ". Capacity: " << vector->GetCapacity() << endl << "Vector sorted by proximity around (0;0)" << endl;
	cout << "Closer point (front Entity): (" << vector->Front()->m_x << ";" << vector->Front()->m_y << ")" << endl;
	for (int i = 1; i < vector->GetSize(); i++) {
		cout << "Entity " << (i + 1) << ": (" << (*vector)[i]->m_x << ";" << (*vector)[i]->m_y << ")" << endl;
	}

	//--------------- Ring List ---------------
	int size = 3;
	EntityRingList *ringList = new EntityRingList(size);
	Entity *firstEntity = new Entity();
	firstEntity->m_x = 11;
	firstEntity->m_y = 10;
	ringList->Push(firstEntity);

	entity = new Entity();
	entity->m_x = 2;
	entity->m_y = 5;
	ringList->Push(entity);
	entity = new Entity();
	entity->m_x = 0;
	entity->m_y = 1;
	ringList->Push(entity);
	entity = new Entity();
	entity->m_x = 10;
	entity->m_y = 10;
	ringList->Push(entity);

	delete firstEntity;

	//Iterating over ring list (one extra of the ring list size)
	for (int i = 0; i < size + 1; i++) {
		cout << "Ring List Entity: (" << (*ringList)[i]->m_x << ";" << (*ringList)[i]->m_y << ")" << endl;
	}

	delete ringList;

	int wait;
	cin >> wait;

	return 0;
}
