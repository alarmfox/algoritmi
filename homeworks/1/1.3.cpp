#include <iostream>



template <typename T> class Tree {
private:
    struct Node {
        T data;
        struct Node* left, *right, *parent;
        Node(T x) : data(x), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    static const int count = 10;
    Node* root = nullptr;
    void _print(Node* n, int space) const;
    void destroy(Node* n);

public:
    void insert(const T& elem);
    void print() const;
    ~Tree();

};

template <typename T> void Tree<T>::insert(const T& elem) {
    if (!root) {
        root = new Node(elem);
        return;
    }
    Node* z = new Node(elem);
    Node* y = nullptr;
    Node* x = root;
    while (x) {
        y = x;
        if (elem < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->parent = y;

    if (elem < y->data) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}

template <typename T>  void Tree<T>::print() const {
    _print(root, 0);
}

template <typename T>  void Tree<T>::_print(Node * n, int space) const {
    if (!n) return;

    space += Tree::count;

    _print(n -> right, space);

    std::cout << std::endl;

    for (int i = Tree::count; i < space; ++i) {
        std::cout<< ' ';
    }

    std::cout << n->data << "\n";

    _print(n -> left, space);

}


template <typename T>  Tree<T>::~Tree() {
    destroy(this->root);
}

template <typename T>  void Tree<T>::destroy(Node* n) {
    if (n) {
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
}

// TREE-INSERT.T; ´/
// 1 y D NIL
// 2 x D T:root
// 3 while x ¤ NIL
// 4 y D x
// 5 if ´:key < x:key
// 6 x D x:left
// 7 else x D x:right
// 8 ´:p D y
// 9 if y == NIL
// 10 T:root D ´ // tree T was empty
// 11 elseif ´:key < y:key
// 12 y:left D ´
// 13 else y:right D ´

int main() {

    Tree<int> t;

    t.insert(5);
    t.insert(4);
    t.insert(3);
    t.insert(2);
    t.insert(7);

    t.print();

}