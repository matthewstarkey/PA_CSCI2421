//
// Created by Kai Marshall on 6/24/21.
//

#ifndef LAB3PREP_LINKEDSTACK_H
#define LAB3PREP_LINKEDSTACK_H
#include "StackInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
    Node <ItemType> topPtr;

public:
    LinkedStack();
    LinkedStack(const LinkedStack<ItemType>& aStack);
    virtual ~LinkedStack();

    bool isEmpty() const;
    bool push(const ItemType& newItem);
    bool pop();
    ItemType peek() const noexcept(false);

};

#include "LinkedStack.cpp"


#endif //LAB3PREP_LINKEDSTACK_H
