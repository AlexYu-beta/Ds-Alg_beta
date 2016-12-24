//
// Created by alex on 12/24/16.
//

#ifndef EXPRESSIONTREE_TREENODE_H
#define EXPRESSIONTREE_TREENODE_H
#include <iostream>
using namespace std;

template <typename T>
class TreeNode{
public:
    T element;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        this(0);
    }

    TreeNode(T ele):element(ele){
        left= nullptr;
        right= nullptr;
    }

    TreeNode(T ele,TreeNode *left,TreeNode *right):element(ele),left(left),right(right){

    }
};
#endif //EXPRESSIONTREE_TREENODE_H
