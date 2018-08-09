#ifndef ENTITYVECTOR_H_
#define ENTITYVECTOR_H_
#include "Entity.h"

class EntityVector {
private:
	int size;
	int capacity;
	Entity **entities;
	void CheckCapacity();
	void QuickSort(EntityVector& vector, int centerPosX, int centerPosY, int p, int q);
	int Split(EntityVector& vector, int centerPosX, int centerPosY, int p, int q);
public:
	EntityVector();
	~EntityVector();
	int GetCapacity();
	int GetSize();
	void Insert(Entity* newEntity, int index);
	void PushBack(Entity* newEntity);
	Entity* PopBack();
	Entity* Front();
	Entity* Back();
	void Reserve(int newCapacity);
	void Clear();
	bool Empty() const;
	void Sort(EntityVector& vector, int centerPosX, int centerPosY);
	Entity*& operator[](int index);
};

#endif /* ENTITYVECTOR_H_ */
