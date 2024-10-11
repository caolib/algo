//
// Created by Tanking Cao on 24-9-7.
//

#ifndef TREEDEPTH_H
#define TREEDEPTH_H

#include"binaryTree.cpp"

int treeDepth(BiTree t){
    if (t == nullptr) return 0;
    int ld = treeDepth(t->lchild);
    int rd = treeDepth(t->rchild);
    return (ld > rd ? ld : rd) + 1;
}

#endif //TREEDEPTH_H
