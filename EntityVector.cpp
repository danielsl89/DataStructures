#include "EntityVector.h"
#include <math.h>

EntityVector::EntityVector() {
	size = 0;
	capacity = 0;
	entities = nullptr;
}

EntityVector::~EntityVector() {
	delete[] entities;
}

int EntityVector::GetCapacity() {
	return capacity;
}

int EntityVector::GetSize() {
	return size;
}

void EntityVector::Insert(Entity* newEntity, int index) {
	CheckCapacity();
	//The entity vector implementation pushes back the element if the insertion is done in a not contiguous index
	if (index > size) {
		PushBack(newEntity);
	}
	for(int i = size - 1; i >= index; i--) {
		entities[i + 1] = entities[i];
	}
	entities[index] = newEntity;
	size++;
}
void EntityVector::PushBack(Entity* newEntity) {
	CheckCapacity();
	entities[size] = newEntity;
	size++;
}

void EntityVector::CheckCapacity() {
	//If there is no capacity on the array we duplicate its size, plus 1.
	//The entity vector implementation ensures the size will be changed automatically even if there is not an initial capacity reserved
	if (size == capacity) {
		Reserve(capacity * 2 + 1);
	}
}

Entity* EntityVector::PopBack() {
	size--;
	return entities[size];
}

Entity* EntityVector::Front() {
	return entities[0];
}

Entity* EntityVector::Back() {
	return entities[size - 1];
}

void EntityVector::Reserve(int newCapacity) {
	Entity **newEntities = new Entity*[newCapacity];
	for (int i = 0; i < size; i++) {
		newEntities[i] = entities[i];
	}
	entities = newEntities;
	capacity = newCapacity;
}

void EntityVector::Clear() {
	size = 0;
	capacity = 0;
	delete[] entities;
	entities = nullptr;
}

bool EntityVector::Empty() const {
	return size == 0;
}

Entity* &EntityVector::operator[](int index) {
	return entities[index];
}

void EntityVector::Sort(EntityVector& vector, int centerPosX, int centerPosY) {
	QuickSort(vector, centerPosX, centerPosY, 0, vector.GetSize());
}

void EntityVector::QuickSort(EntityVector& vector, int centerPosX, int centerPosY, int p, int q) {
    int splitPoint;
    if(p < q) {
    	splitPoint = Split(vector, centerPosX, centerPosY, p, q);
    	QuickSort(vector, centerPosX, centerPosY, p, splitPoint);
    	QuickSort(vector, centerPosX, centerPosY, splitPoint+1, q);
    }
}


int EntityVector::Split(EntityVector& vector, int centerPosX, int centerPosY, int p, int q) {
    Entity *x = vector[p];
    int i = p;
    int j;
    Entity auxEntity;

    for(j = p + 1; j < q ; j++) {
    	//Getting the one closer to the center positions
        if( pow(vector[j]->m_x - centerPosX, 2) + pow(vector[j]->m_y - centerPosY, 2) <= pow(x->m_x - centerPosX, 2) + pow(x->m_y - centerPosY, 2)) {//x->m_x) {
            i = i + 1;
            auxEntity = *vector[i];
            *vector[i] = *vector[j];
            *vector[j] = auxEntity;
        }
    }

    auxEntity = *vector[i];
    *vector[i] = *vector[p];
    *vector[p] = auxEntity;
    return i;
}
