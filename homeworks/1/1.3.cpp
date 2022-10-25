#include <iostream>

template <typename T> class Tree {
private:
    struct Node {
        T data;
        float priority;
        struct Node* left, *right, *parent;
        Node(T x) : data(x), left(nullptr), right(nullptr), parent(nullptr) {
            priority = (float)std::rand() / (float) RAND_MAX;
        }
    };
    static const int count = 10;
    Node* root = nullptr;
    void _print(Node* n, int space) const;
    void destroy(Node* n);
    void left_rotate(Node* x);
    void right_rotate(Node* x);
    void move_up(Node* x);

public:
    void treap_insert(const T& elem);
    void print() const;
    ~Tree();

};


template <typename T> void Tree<T>::treap_insert(const T& elem) {
    Node* z = new Node(elem);
    Node* y = nullptr;
    Node* x = root;
    while (x) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    z->parent = y;

    if (!y) {
		root = z;
	} else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    if (z->parent) {
        move_up(z);
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

    std::cout << "(" << n->data << "," << n->priority<< ')' << "\n";

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


template <typename T>  void Tree<T>::left_rotate(Node* n) {
	Node* y = n->right;
	n->right = y->left;
	if (y->left) {
		y->left->parent = n;
	}
	y->parent = n->parent;
	if (!n->parent) {
		this->root = y;
	} else if (n == n->parent->left) {
		n->parent->left = y;
	} else {
		n->parent->right = y;
	}
	y->left = n;
	n->parent = y;
}

template <typename T>  void Tree<T>::right_rotate(Node* n) {
	Node* y = n->left;
	n->left = y->right;
	if (y->right) {
		y->right->parent = n;
	}
	y->parent = n->parent;
	if (!n->parent) {
		this->root = y;
	} else if (n == n->parent->right) {
		n->parent->right = y;
	} else {
		n->parent->left = y;
	}
	y->right = n;
	n->parent = y;
}

template <typename T> void Tree<T>::move_up(Node* n) {
    if (!n->parent) {
		return;
	}
	if (n->parent && n->priority >= n->parent->priority) {
	    return;
	}

	if (n == n->parent->left) {
		right_rotate(n->parent);
	} else {
		left_rotate(n->parent);
	}
    move_up(n);
}

int main() {

    std::srand(time(0));
    Tree<int> t;

    t.treap_insert(5);
    t.treap_insert(4);
    t.treap_insert(3);
    t.treap_insert(2);
    t.treap_insert(1);

    t.print();

}