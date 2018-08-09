 #ifndef ENTITYRINGLIST_H_
#define ENTITYRINGLIST_H_
#include "EntityListNode.h"

class EntityRingList {
private:
	EntityListNode *head;
	EntityListNode *tail;
	int capacity;
	int size;
public:
	EntityRingList(int c);
	void Push(Entity *newEntity);
	Entity *operator[](int index);
	~EntityRingList();
};

#endif /* ENTITYRINGLIST_H_ */
