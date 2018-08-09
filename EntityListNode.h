#ifndef ENTITYLISTNODE_H_
#define ENTITYLISTNODE_H_
#include "Entity.h"

struct EntityListNode {
  Entity *entity;
  EntityListNode *nextNode = nullptr;
};

#endif /* ENTITYLISTNODE_H_ */
