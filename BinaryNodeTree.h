//
// Created by Kai Marshall on 7/15/21.
//

#ifndef LAB5PREP_BINARYNODETREE_H
#define LAB5PREP_BINARYNODETREE_H

#include <memory>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

using namespace std;

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
private:
    shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    int getHeightHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    int getNumberOfNodesHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    auto balancedAdd(shared_ptr<BinaryNode<ItemType>> subTreePtr, shared_ptr<BinaryNode<ItemType>> newNodePtr);

    shared_ptr<BinaryNode<ItemType>> moveValuesUpTree (shared_ptr<BinaryNode<ItemType>> subTreePtr);

    virtual shared_ptr<BinaryNode<ItemType>> removeValue(shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                         ItemType target, bool& success);
    auto findNode(shared_ptr<BinaryNode<ItemType>> treePtr,
                  const ItemType& target, bool& success) const;

    shared_ptr<BinaryNode<ItemType>> copyTree(shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

    void destroyTree(shared_ptr<BinaryNode<ItemType>> subTreePtr);

    void preorder(void visit(ItemType&), shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void inorder(void visit(ItemType&), shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void postorder(void visit(ItemType&), shared_ptr<BinaryNode<ItemType>> treePtr) const;

public:
    BinaryNodeTree();
    explicit BinaryNodeTree(const ItemType& rootItem);
    explicit BinaryNodeTree(const ItemType& rootItem,
                            const shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                            const shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
    BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
    virtual ~BinaryNodeTree();

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const noexcept(false);
    void setRootData(const ItemType& newItem);
    bool add(const ItemType& newData);
    bool remove(const ItemType& target);
    void clear();
    ItemType getEntry(const ItemType& anEntry) const noexcept(false);
    bool contains (const ItemType& anEntry) const;
    virtual void printTree() const;
    void printTree(shared_ptr<BinaryNode<ItemType>> treePtr, const string& prefix, bool isLeft) const;

    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    BinaryNodeTree<ItemType> &operator =(const BinaryNodeTree &rightHandSide);

};

#include "BinaryNodeTree.cpp"

#endif //LAB5PREP_BINARYNODETREE_H
