#include "ZipTree.h"
#include <iostream>
#include <random>

using namespace std;

ZipTreeNode::ZipTreeNode(int k, int r) : key(k), left(nullptr), right(nullptr) {
    if (r == -1)
        rank = randomRank();
    else
        rank = r;
}

int ZipTreeNode::randomRank() {
    static mt19937 gen(random_device{}());
    static uniform_int_distribution<int> d(1, 100);
    return d(gen);
}

ZipTree::ZipTree() : root(nullptr) {}

ZipTreeNode* ZipTree::getRoot() {
    return root;
}

ZipTreeNode* ZipTree::search(int key) {
    ZipTreeNode* node = root;
    while (node) {
        if (key == node->key) return node;
        else if (key < node->key) node = node->left;
        else node = node->right;
    }
    return nullptr;
}

void ZipTree::insert(int key) {
    ZipTreeNode* x = new ZipTreeNode(key);
    root = insertNode(x, root);
}

ZipTreeNode* ZipTree::insertNode(ZipTreeNode* x, ZipTreeNode* root) {
    if (!root) return x;

    if (x->key < root->key) {
        if (x->rank > root->rank) {
            x->right = root;
            return x;
        }
        root->left = insertNode(x, root->left);
    }
    else {
        if (x->rank >= root->rank) {
            x->left = root;
            return x;
        }
        root->right = insertNode(x, root->right);
    }
    return root;
}

ZipTreeNode* ZipTree::zip(ZipTreeNode* x, ZipTreeNode* y) {
    if (!x) return y;
    if (!y) return x;

    if (y->rank > x->rank) {
        y->left = zip(x, y->left);
        return y;
    }
    else {
        x->right = zip(x->right, y);
        return x;
    }
}

void ZipTree::remove(int key) {
    ZipTreeNode* x = search(key);
    if (x) root = deleteNode(x, root);
}

ZipTreeNode* ZipTree::deleteNode(ZipTreeNode* x, ZipTreeNode* root) {
    if (!root) return nullptr;

    if (x->key == root->key) {
        ZipTreeNode* temp = zip(root->left, root->right);
        delete root;
        return temp;
    }

    if (x->key < root->key) {
        if (root->left && x->key == root->left->key) {
            ZipTreeNode* temp = zip(root->left->left, root->left->right);
            delete root->left;
            root->left = temp;
        }
        else if (root->left) {
            root->left = deleteNode(x, root->left);
        }
    }
    else {
        if (root->right && x->key == root->right->key) {
            ZipTreeNode* temp = zip(root->right->left, root->right->right);
            delete root->right;
            root->right = temp;
        }
        else if (root->right) {
            root->right = deleteNode(x, root->right);
        }
    }
    return root;
}

bool ZipTree::isValid(ZipTreeNode* node, int minKey, int maxKey) {
    if (!node) return true;
    if (node->key <= minKey || node->key >= maxKey) return false;
    if ((node->left && node->left->rank > node->rank) ||
        (node->right && node->right->rank > node->rank)) return false;
    return isValid(node->left, minKey, node->key) &&
        isValid(node->right, node->key, maxKey);
}

void ZipTree::Printinorder() {
    vector<int> res;
    inorder(root, res);
    for (int x : res) cout << x << " ";
    cout << endl;
}

void ZipTree::inorder(ZipTreeNode* node, vector<int>& res) {
    if (!node) return;
    inorder(node->left, res);
    res.push_back(node->key);
    inorder(node->right, res);
}

void ZipTree::printPreOrder() {
    vector<int> res;
    preOrder(root, res);
    for (int x : res) cout << x << " ";
    cout << endl;
}

void ZipTree::preOrder(ZipTreeNode* node, vector<int>& res) {
    if (!node) return;
    res.push_back(node->key);
    preOrder(node->left, res);
    preOrder(node->right, res);
}
