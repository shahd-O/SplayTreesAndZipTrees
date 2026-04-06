#ifndef ZIPTREE_H
#define ZIPTREE_H

#include <vector>

class ZipTreeNode {
public:
    int key;
    int rank;
    ZipTreeNode* left;
    ZipTreeNode* right;

    ZipTreeNode(int k, int r = -1);

private:
    int randomRank();
};

class ZipTree {
private:
    ZipTreeNode* root;

    ZipTreeNode* insertNode(ZipTreeNode* x, ZipTreeNode* root);
    ZipTreeNode* zip(ZipTreeNode* x, ZipTreeNode* y);
    ZipTreeNode* deleteNode(ZipTreeNode* x, ZipTreeNode* root);
    void inorder(ZipTreeNode* node, std::vector<int>& res);
    void preOrder(ZipTreeNode* node, std::vector<int>& res);

public:
    ZipTree();

    ZipTreeNode* getRoot();
    ZipTreeNode* search(int key);
    void insert(int key);
    void remove(int key);
    bool isValid(ZipTreeNode* node, int minKey, int maxKey);

    void Printinorder();
    void printPreOrder();
};

#endif 