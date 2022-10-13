#include <iostream>

#define DEBUG 1

template <typename T> class List {

private:
    struct Node {
        T elem;
        Node* next;
        Node* prev;

    };
    int n;
    Node* head;
public:
    List() { n = 0; head = nullptr; }
    ~List();
    void insert(const T&);
    void half_reverse();
    void destroy();
    void print(std::ostream&)const;

};

template <typename T>List<T>::~List() {
    destroy();
}


template <typename T> void List<T>::destroy() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    n = 0;
}

template <typename T> void List<T>::insert(const T& e) {
    Node* p = new Node;

    p->elem = e;
    p->next = nullptr;
    p->prev = nullptr;
    if (!head) {
        head = p;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
        p->prev = temp;
    }
    ++n;
}


template <typename T> void List<T>::print(std::ostream& out)const {
    Node* current = head;
    while (current) {
        out << current->elem << std::endl;
        current = current->next;
    }
}

// 1 2 3 4 5 6 7
// 1 2 3 7 6 5 4
template <typename T> void List<T>::half_reverse() {
    const int mid = n / 2;

    Node* current = head, *prev = nullptr, *next = nullptr, *last = nullptr;
    for (int i = 0; i < mid; ++i) {
        current = current->next;
    }
    last = current -> prev;

    while (current) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    last -> next = prev;
}

int main() {
    List<int> list;


    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);


    if (DEBUG) {
        list.print(std::cout);
        std::cout << "sus" << std::endl;
    }

    list.half_reverse();
    list.print(std::cout);

    list.destroy();

    std::cout << "sus" << std::endl;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);
    list.insert(9);
    list.insert(10);
    list.insert(11);


    list.half_reverse();
    list.print(std::cout);
}
