//
// Created by Kai Marshall on 7/15/21.
//

#include "BinarySearchTree.h"

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           shared_ptr<BinaryNode<ItemType>> newNode) {
   if (subTreePtr == nullptr)
       return newNode;
   else {
       if (subTreePtr->getItem() > newNode->getItem())
           subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNode));
       else
           subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNode));

       return subTreePtr;
   }
}

template<class ItemType>
shared_ptr<BinaryNode<ItemType>>
BinarySearchTree<ItemType>::removeValue(shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target,
                                        bool &success) {
    if (subTreePtr == nullptr) {
        success = false;
        return subTreePtr;
    }
    if (subTreePtr->getItem() == target) {
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }
    else {
        if (subTreePtr->getItem() > target)
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
        else
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));

        return subTreePtr;
    }
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode(shared_ptr<BinaryNode<ItemType>> nodePtr) {
    if (nodePtr->isLeaf()) {
        nodePtr.reset();
        return nodePtr;
    }
    else if (nodePtr->getLeftChildPtr() == nullptr) {
        return nodePtr->getRightChildPtr();
    }
    else if (nodePtr->getRightChildPtr() == nullptr) {
        return nodePtr->getLeftChildPtr();
    }
    else {
        ItemType newNodeValue;
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                    ItemType &inorderSuccessor) {
    if (subTreePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    } else {
        subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
        return subTreePtr;
    }
}

template<class ItemType>
auto BinarySearchTree<ItemType>::findNode(shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType &target) const {
    if (treePtr == nullptr)
        return treePtr;
    else if (treePtr->getItem() == target)
        return treePtr;
    else if (treePtr->getItem() > target)
        return findNode(treePtr->getLeftChildPtr(), target);
    else
        return findNode(treePtr->getRightChildPtr(), target);

}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() = default;

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &rootItem)
: rootPtr(make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)){}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType> &tree) {
rootPtr = this->copyTree(tree.rootPtr);
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    this->destroyTree(rootPtr);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {
    if (isEmpty())
        throw PrecondViolatedExcep("getRootData() called with empty tree.");

    return rootPtr->getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType &newData) const noexcept(false) {
    throw PrecondViolatedExcep("Cannot change root value in a BST!");
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newData) {
    auto newNodePtr = make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &target) {
    bool isSuccess = false;
    rootPtr = removeValue(rootPtr, target, isSuccess);
    return isSuccess;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
    this->destroyTree(rootPtr);
    rootPtr.reset();
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType &anEntry) const noexcept(false) {
    shared_ptr<BinaryNode<ItemType>> nodeWithEntry = findNode(rootPtr, anEntry);
    if (nodeWithEntry == nullptr)
        throw NotFoundException("Entry not found in tree.");
    else
        return nodeWithEntry->getItem();
    }


template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType &anEntry) const {
    return (findNode(rootPtr, anEntry) == nullptr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void (*visit)(ItemType &)) const {
    this->preorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void (*visit)(ItemType &)) const {
    this->inorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void (*visit)(ItemType &)) const {
    this->postorder(visit, rootPtr);
}

template<class ItemType>
BinarySearchTree<ItemType> &BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType> &rightHandSide) {
    if (&rightHandSide != this)
    {
        BinarySearchTree temp(rightHandSide);
        std::swap(temp.rootPtr, rootPtr);
    }
    return *this;
}

