//
// Created by Kai Marshall on 7/15/21.
//

#ifndef LAB5PREP_BINARYSEARCHTREE_H
#define LAB5PREP_BINARYSEARCHTREE_H
#include <memory>
#include "BinaryTreeInterface.h"
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

using namespace std;

template <class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
private:
    shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    virtual shared_ptr<BinaryNode<ItemType>> placeNode (shared_ptr<BinaryNode<ItemType>> subTreePtr,
                    shared_ptr<BinaryNode<ItemType>> newNode);

    shared_ptr<BinaryNode<ItemType>> removeValue(shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                 const ItemType target,
                                                 bool& success) override;

    auto removeNode (shared_ptr<BinaryNode<ItemType>> nodePtr);
    auto removeLeftmostNode(shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType& inorderSuccessor);
    auto findNode(shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const;
    auto findNodeWithPointerItems(shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const;

public:
    explicit BinarySearchTree();
    explicit BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    virtual ~BinarySearchTree();

    bool isEmpty() const override;
    int getHeight() const override;
    int getNumberOfNodes() const override;
    ItemType getRootData() const override;
    void setRootData(const ItemType& newData) const noexcept(false);
    bool add(const ItemType& newData) override;
    bool remove (const ItemType& target) override;
    void clear() override;
    ItemType getEntry(const ItemType& anEntry) const noexcept(false) override;
    bool contains (const ItemType& anEntry) const override;

    void preorderTraverse(void visit(ItemType&)) const override;
    void inorderTraverse(void visit(ItemType&)) const override;
    void postorderTraverse(void visit(ItemType&)) const override;

    BinarySearchTree<ItemType>& operator =(const BinarySearchTree<ItemType>& rightHandSide);
};

#include "BinarySearchTree.cpp"
#endif //LAB5PREP_BINARYSEARCHTREE_H
