//
// Created by Kai Marshall on 7/15/21.
//

#ifndef LAB5PREP_BINARYNODE_H
#define LAB5PREP_BINARYNODE_H

#include <memory>

using namespace std;

template <class ItemType>
class BinaryNode {
private:
    ItemType item;
    shared_ptr<BinaryNode<ItemType>> leftChildPtr;
    shared_ptr<BinaryNode<ItemType>> rightChildPtr;

public:
    explicit BinaryNode();
    explicit BinaryNode(const ItemType& anItem);
    BinaryNode(const ItemType& anItem,
               shared_ptr<BinaryNode<ItemType>> leftPtr,
               shared_ptr<BinaryNode<ItemType>> rightPtr);

    void setItem (const ItemType& anItem);
    ItemType getItem() const;
    bool isLeaf() const;

    auto getLeftChildPtr() const;
    auto getRightChildPtr() const;

    void setLeftChildPtr(shared_ptr<BinaryNode<ItemType>> leftPtr);
    void setRightChildPtr(shared_ptr<BinaryNode<ItemType>> rightPtr);


};

#include "BinaryNode.cpp"
#endif //LAB5PREP_BINARYNODE_H
