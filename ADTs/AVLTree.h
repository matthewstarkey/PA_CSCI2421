//
// Created by Kai Marshall on 7/22/21.
//

#ifndef LAB6PREP_AVLTREE_H
#define LAB6PREP_AVLTREE_H
#include <memory>
#include "BinarySearchTree.h"

template <class ItemType>
class AVLTree : public BinarySearchTree<ItemType> {
private:
    shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    const int ALLOWED_IMBALANCE = 1;

    shared_ptr<BinaryNode<ItemType>> balance(shared_ptr<BinaryNode<ItemType>> root);
    shared_ptr<BinaryNode<ItemType>> rotateWithLeftChild(shared_ptr<BinaryNode<ItemType>> root);
    shared_ptr<BinaryNode<ItemType>> rotateWithRightChild(shared_ptr<BinaryNode<ItemType>> root);
    shared_ptr<BinaryNode<ItemType>> rotateDoubleWithLeftChild(shared_ptr<BinaryNode<ItemType>> root);
    shared_ptr<BinaryNode<ItemType>> rotateDoubleWithRightChild(shared_ptr<BinaryNode<ItemType>> root);

    shared_ptr<BinaryNode<ItemType>>
    placeNode(shared_ptr<BinaryNode<ItemType>> subTreePtr, shared_ptr<BinaryNode<ItemType>> newNode) override;

    shared_ptr<BinaryNode<ItemType>>
    removeValue(shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType target, bool& success) override;

public:
    explicit AVLTree();
    explicit AVLTree(const ItemType& rootItem);

    bool add(const ItemType& newData) override;
    bool remove(const ItemType& target) override;
    void printTree() const override;
    int getHeight() const override;
    bool isEmpty() const override;
    int getNumberOfNodes() const override;

};

#include "AVLTree.cpp"
#endif //LAB6PREP_AVLTREE_H
