//
// Created by Kai Marshall on 6/24/21.
//

#include "LinkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {

}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType> &aStack) {
    Node<ItemType> origChainPtr = aStack.topPtr;

    if (origChainPtr == nullptr)
        topPtr = nullptr;
    else
    {
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr->getItem());

        //copy remaining nodes
        Node<ItemType>* newChainPtr = topPtr;
        origChainPtr = origChainPtr->getNext();

        while(origChainPtr != nullptr)
        {

            ItemType nextItem = origChainPtr->getItem(); //get next item from original chain
            origChainPtr = origChainPtr->getNext(); //advance original chain pointer
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);//create a new node containing the next item
            newChainPtr->setNext(newNodePtr);//Link new node to end of new chain
            newChainPtr = newChainPtr->getNext();//Advance pointer to new last node
        }

        newChainPtr->setNext(nullptr);
    }


}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while(!isEmpty())
        pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType &newItem) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    if (!isEmpty())
    {
     Node<ItemType> nodeToDeletePtr = topPtr;
     topPtr = topPtr->getNext();

     nodeToDeletePtr.setNext(nullptr);
     delete nodeToDeletePtr;
     nodeToDeletePtr = nullptr;

     return true;
    }
    return false;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const noexcept(false) {
    if (isEmpty())
        throw (PrecondViolatedExcep("peek() called with empty stack"));

    return topPtr.getItem();
}
