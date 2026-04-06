#include "SplayTree.h"
using namespace std;

Node::Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}



SplayTree::SplayTree() : root(nullptr) {}

Node* SplayTree::getRoot() {
    if(!empty())
    return root; 
}


Node* SplayTree::rightRotate(Node* x) {
    Node* y = x->left;
    if (!y) return x;

    x->left = y->right;
    if (y->right) y->right->parent = x;

    y->right = x;
    y->parent = x->parent;
    x->parent = y;

    if (y->parent) {
        if (y->parent->left == x) y->parent->left = y;
        else y->parent->right = y;
    }
    else {
        root = y;
    }

    return y;
}

Node* SplayTree::leftRotate(Node* x) {
    Node* y = x->right;
    if (!y) return x;

    x->right = y->left;
    if (y->left) y->left->parent = x;

    y->left = x;
    y->parent = x->parent;
    x->parent = y;

    if (y->parent) {
        if (y->parent->left == x) y->parent->left = y;
        else y->parent->right = y;
    }
    else {
        root = y; 
    }

    return y;
}

void SplayTree::splay(Node* x) {
    if (!x) return;

    while (x->parent) {
        Node* p = x->parent;
        Node* g = p->parent;

        if (!g) {
            // Zig
            if (x == p->left)
                x = rightRotate(p);
            else
                x = leftRotate(p);
        }
        else if (x == p->left && p == g->left) {
            // Zig-Zig Left
            rightRotate(g);
            x = rightRotate(p);
        }
        else if (x == p->right && p == g->right) {
            // Zig-Zig Right
            leftRotate(g);
            x = leftRotate(p);
        }
        else if (x == p->right && p == g->left) {
            // Zig-Zag Left-Right
            leftRotate(p);
            x = rightRotate(g);
        }
        else if (x == p->left && p == g->right) {
            // Zig-Zag Right-Left
            rightRotate(p);
            x = leftRotate(g);
        }
    }

    root = x; 
}

void SplayTree::insert(int key) {
    if (!root) {
        root = new Node(key);
        return;
    }

    Node* curr = root;
    Node* parent = nullptr;

    while (curr) {
        parent = curr;
        if (key < curr->key)
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else {
            splay(curr);
            return;
        }
    }

    Node* node = new Node(key);
    node->parent = parent;

    if (key < parent->key)
        parent->left = node;
    else
        parent->right = node;

    splay(node);
}

Node* SplayTree::access(int key) {
    Node* curr = root;
    Node* last = nullptr;

    while (curr) {
        last = curr;
        if (key < curr->key)
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else {
            splay(curr);
            return curr;
        }
    }

    if (last)
        splay(last);

    return nullptr;
}

Node* SplayTree::join(Node* leftTree, Node* rightTree) {
    if (!leftTree) return rightTree;
    if (!rightTree) return leftTree;

    Node* maxNode = leftTree;
    while (maxNode->right)
        maxNode = maxNode->right;

    root = leftTree;
    splay(maxNode);

    maxNode->right = rightTree;
    rightTree->parent = maxNode;

    return maxNode;
}

void SplayTree::split(int key, Node*& leftTree, Node*& rightTree) {
    if (!root) {
        leftTree = rightTree = nullptr;
        return;
    }

    access(key);

    if (root->key <= key) {
        leftTree = root;
        rightTree = root->right;
        if (rightTree)
            rightTree->parent = nullptr;
        leftTree->right = nullptr;
    }
    else {
        rightTree = root;
        leftTree = root->left;
        if (leftTree)
            leftTree->parent = nullptr;
        rightTree->left = nullptr;
    }
}

void SplayTree::deleteNode(int key) {
    Node* node = access(key);
    if (!node || node->key != key)
        return;

    Node* leftTree = root->left;
    Node* rightTree = root->right;

    if (leftTree)
        leftTree->parent = nullptr;
    if (rightTree)
        rightTree->parent = nullptr;

    delete root;
    root = join(leftTree, rightTree);
}

bool SplayTree::isValid(Node* node, int minKey, int maxKey) {
    if (!node) return true;

    if (node->key <= minKey || node->key >= maxKey)
        return false;

    if (node->left && node->left->parent != node) return false;
    if (node->right && node->right->parent != node) return false;

    return isValid(node->left, minKey, node->key) &&
        isValid(node->right, node->key, maxKey);
}

void SplayTree::preOrder(Node* node) {
    if (!node) return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void SplayTree::printPreOrder() {
    preOrder(root);
    cout << endl;
}

void SplayTree::inOrder(Node* node) {
    if (!node) return;
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}

void SplayTree::printInOrder() {
    inOrder(root);
    cout << endl;
}
