#include <iostream>
using namespace std;

struct Tree {
    int val;
    Tree *left, *right;
    Tree(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insert(Tree *root, int val) {
    if (val < root->val) {
        if (root->left == nullptr) {
            root->left = new Tree(val);
        } else {
            insert(root->left, val);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new Tree(val);
        } else {
            insert(root->right, val);
        }
    }
}

void print(Tree *root) {
    if (root == nullptr) {
        return;
    }
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

void deleteTree(Tree *root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

Tree* search(Tree *root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

int main() {
    Tree *root = new Tree(5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    print(root);
    cout << endl;
    Tree *node = search(root, 7);
    if (node != nullptr) {
        cout << "Found " << node->val << endl;
    } else {
        cout << "Not found" << endl;
    }
    deleteTree(root);
}
