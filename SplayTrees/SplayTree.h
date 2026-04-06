#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int k);
};

class SplayTree {
private:
    Node* root;

    Node* rightRotate(Node* x);
    Node* leftRotate(Node* x);

    void inOrder(Node* node);
    void preOrder(Node* node); 

public:
    SplayTree();
    Node* getRoot();

    void splay(Node* x);
    void insert(int key);
    Node* access(int key);
    Node* join(Node* leftTree, Node* rightTree);
    void split(int key, Node*& leftTree, Node*& rightTree);
    void deleteNode(int key);
    bool empty() const {
        return root == nullptr;
    }
    bool isValid(Node* node, int minKey, int maxKey);
    void printInOrder();
    void printPreOrder();  


};

#endif 
