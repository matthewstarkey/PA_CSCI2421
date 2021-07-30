//
// Created by Kai Marshall on 7/22/21.
//

#include "AVLTree.h"

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> AVLTree<ItemType>::balance(shared_ptr<BinaryNode<ItemType>> root) {
    if (root == nullptr)
        return nullptr;

    int leftHeight = this->getHeightHelper(root->getLeftChildPtr());
    int rightHeight = this->getHeightHelper(root->getRightChildPtr());

    if ((leftHeight-rightHeight) > ALLOWED_IMBALANCE) {
        if (this->getHeightHelper(root->getLeftChildPtr()->getLeftChildPtr())
        >= this->getHeightHelper(root->getLeftChildPtr()->getRightChildPtr()))
            return rotateWithLeftChild(root);
        else
            return rotateDoubleWithLeftChild(root);
    }
    else if ((rightHeight-leftHeight) > ALLOWED_IMBALANCE) {
        if (this->getHeightHelper(root->getRightChildPtr()->getRightChildPtr())
            >= this->getHeightHelper(root->getRightChildPtr()->getLeftChildPtr()))
            return rotateWithRightChild(root);
        else
            return rotateDoubleWithRightChild(root);
    }

    return root;
}

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> AVLTree<ItemType>::rotateWithLeftChild(shared_ptr<BinaryNode<ItemType>> root) {
    shared_ptr<BinaryNode<ItemType>> newRoot = root->getLeftChildPtr();
    root->setLeftChildPtr(newRoot->getRightChildPtr());
    newRoot->setRightChildPtr(root);
    return newRoot;
}

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> AVLTree<ItemType>::rotateWithRightChild(shared_ptr<BinaryNode<ItemType>> root) {
    shared_ptr<BinaryNode<ItemType>> newRoot = root->getRightChildPtr();
    root->setRightChildPtr(newRoot->getLeftChildPtr());
    newRoot->setLeftChildPtr(root);
    return newRoot;
}

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> AVLTree<ItemType>::rotateDoubleWithLeftChild(shared_ptr<BinaryNode<ItemType>> root) {
    root->setLeftChildPtr(rotateWithRightChild(root->getLeftChildPtr()));
    return rotateWithLeftChild(root);
}

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> AVLTree<ItemType>::rotateDoubleWithRightChild(shared_ptr<BinaryNode<ItemType>> root) {
    root->setRightChildPtr(rotateWithLeftChild(root->getRightChildPtr()));
    return rotateWithRightChild(root);
}

template<class ItemType>
shared_ptr<BinaryNode<ItemType>>
AVLTree<ItemType>::placeNode(shared_ptr<BinaryNode<ItemType>> subTreePtr, shared_ptr<BinaryNode<ItemType>> newNode) {
    return BinarySearchTree<ItemType>::placeNode(subTreePtr, newNode);
}

template<class ItemType>
shared_ptr<BinaryNode<ItemType>>
AVLTree<ItemType>::removeValue(shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType target, bool &success) {
    return BinarySearchTree<ItemType>::removeValue(subTreePtr, target, success);
}

template<class ItemType>
AVLTree<ItemType>::AVLTree()=default;

template<class ItemType>
AVLTree<ItemType>::AVLTree(const ItemType &rootItem):
rootPtr(make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)) {}

template<class ItemType>
bool AVLTree<ItemType>::add(const ItemType &newData) {
    auto newNodePtr = make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    rootPtr = balance(rootPtr);
    return true;
}

template<class ItemType>
bool AVLTree<ItemType>::remove(const ItemType &target) {
    bool isSuccess = false;
    rootPtr = removeValue(rootPtr, target, isSuccess);
    rootPtr = balance(rootPtr);
    return isSuccess;
}

template<class ItemType>
void AVLTree<ItemType>::printTree() const {
BinaryNodeTree<ItemType>::printTree(rootPtr, "", false);
}

template<class ItemType>
int AVLTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}
template<class ItemType>
bool AVLTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template<class ItemType>
int AVLTree<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr);
}
