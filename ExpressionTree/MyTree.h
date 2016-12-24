//
// Created by alex on 12/24/16.
//

#ifndef EXPRESSIONTREE_MYTREE_H
#define EXPRESSIONTREE_MYTREE_H
#include <iostream>
#include "TreeNode.h"
using namespace std;
template <typename T>
class MyTree{
public:
    TreeNode<T> *root;
    MyTree(){
        root=new TreeNode<T>();
    }

    MyTree(TreeNode<T> *rootptr):root(rootptr){
    }

    ~MyTree(){
        delete root;
    }

    void combine(TreeNode<T> *newRoot,MyTree *tree){
        root=new TreeNode<T>(newRoot->element,root,tree->root);
    }

    void InOrder(){
        InOrder(root);
    }

    void InOrder(TreeNode<T> *temp){
        if(temp==nullptr) return;
        else{
            if(temp->left!= nullptr)InOrder(temp->left);
            cout<<temp->element<<"  ";
            if(temp->right!= nullptr)InOrder(temp->right);
            return;
        }
    }
};
#endif //EXPRESSIONTREE_MYTREE_H
