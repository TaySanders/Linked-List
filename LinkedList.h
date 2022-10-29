#ifndef PROJECT_1_LINKEDLIST_H
#define PROJECT_1_LINKEDLIST_H
#endif //PROJECT_1_LINKEDLIST_H
#include <iostream>
#include <vector>
using namespace std;
template<typename T>

class LinkedList {

public:
    struct Node {
        T data;
        Node* next;
        Node* prev;

    };
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned int count;

                        /// previews ///

        /// INSERTIONS ///
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);
    void InsertAfter(Node* node, const T& data);
    void InsertBefore(Node* node, const T& data);
    void InsertAt(const T& data, unsigned int index);

        /// BEHAVIORS ///
    void PrintForward() const;
    void PrintReverse() const;
    void Delete();
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;

        /// ACCESSORS ///
    unsigned int NodeCount() const;
    void FindAll(vector<Node*>& outData, const T& value);
    const Node* Find(const T& data) const;
    Node* Find(const T& data);
    const Node* GetNode(unsigned int index) const;
    Node* GetNode(unsigned int index);
    Node* Head();
    const Node* Head() const;
    Node* Tail();
    const Node* Tail() const;


        /// OPERATORS ///
    T& operator[](const unsigned int index);
    const T& operator[](const unsigned int index) const;
    bool operator==(const LinkedList<T>& rhs) const;
    LinkedList<T>&operator=(const LinkedList<T> &rhs);

        /// CONSTRUCTORS ///
    LinkedList();
    LinkedList(const LinkedList &d);
    ~LinkedList();
    //LinkedList(const LinkedList<T> &list);

        /// REMOVAL ///
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const T& data);
    bool RemoveAt(unsigned int index);
    void Clear();

};

/// copy constructor default ///
template <typename T>
LinkedList<T>::LinkedList() {
    head = tail = nullptr;
    this -> count = 0;
}

/// copy constructor ///
template <typename T>
LinkedList<T>::LinkedList(const LinkedList &d) {
    Node *holder = d.head;
    while (holder != nullptr){
        AddTail(holder-> data);
        holder = holder -> next;
    }
    holder = nullptr;
}

/// copy assignment constructor ///
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    Delete();
    Node *holder = rhs.head;
    while (holder != nullptr){
        AddTail(holder-> data);
        holder = holder -> next;
    }
    holder = nullptr;
    return *this;
}

/// destructor ///
template <typename T>
LinkedList<T>::~LinkedList<T>() {
    Delete();
}

template <typename T>
void LinkedList<T>::Delete() {
    Node *holder = head;
    while (head != nullptr) {
        head = head->next;
        delete holder;
        holder = head;
    }
    head = tail = nullptr;
    count = 0;
}

        ///-----PART ONE-----///

template <typename T>
void LinkedList<T>::AddHead(const T& data) {
    Node* holder = new Node;
    holder -> data = data;
    holder -> next = NULL;
    holder -> prev = NULL;

    if (head == nullptr) {
        head = holder;
        tail = holder;
    }
    else {
        holder->next = head;
        head->prev = holder;
        head = holder;
    }
    count++;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data){
    Node* holder = new Node;
    holder -> data = data;
    holder -> next = NULL;
    holder -> prev = NULL;

    if (tail == NULL) {
        head = holder;
    }
    else {
        tail->next = holder;
        holder->prev = tail;

    }
    tail = holder;
    count++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count){
    for (unsigned int i = count ; i >= 1; i--) {
        AddHead(data[i-1]);
    }
    count++;
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        AddTail(data[i]);
    }
    count++;
}

template <typename T>
void LinkedList<T>::PrintForward() const {
    Node* holder = head;
    while (holder != NULL) {
        cout<< holder -> data << endl;
        holder = holder -> next;
    }
    delete holder;
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
    Node* holder = tail;
    while (holder != NULL) {
        cout << holder -> data << endl;
        holder = holder -> prev;
    }
    delete holder;
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
    return count;
}

        ///-----PART TWO-----///

    /// FIND FUNCTIONS ///
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) {
   Node* holder = head;
   while (holder != NULL) {
       if (holder -> data == value) {
           outData.push_back(holder);
       }
       holder = holder -> next;
   }
}

template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Find(const T& data) const {
    Node* holder = head;
    while (holder != NULL) {
        if (holder -> data == data) {
            return holder;
        }
        holder = holder -> next;
    }
    return nullptr;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>:: Find(const T& data){
    Node* holder = head;
    while (holder != NULL) {
        if (holder -> data == data) {
            return holder;
        }
        holder = holder -> next;
    }
    return nullptr;
}

    /// GET NODE ///
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index) const {
    Node *holder = head;
    if (index >= count) {
        throw std::out_of_range("error");
    }
    else {
        for (unsigned int i = 0; i < index && holder != NULL; i++) {
            holder = holder->next;
        }
    }
    return holder;
}

template <typename T>
typename LinkedList<T>:: Node *LinkedList<T>::GetNode(unsigned int index) {
    Node *holder = head;
    if (index >= count) {
        throw std::out_of_range("error");
    }
    else {
        for (unsigned int i = 0; i < index && holder != NULL; i++) {
            holder = holder->next;
        }
    }
    return holder;
}

    /// HEADS ///
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Head() {
    return head;
}

template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Head() const {
    return head;
}

    /// TAILS ///
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Tail() {
    return tail;
}

template <typename T>
const typename LinkedList<T>:: Node *LinkedList<T>::Tail() const {
    return tail;
}
template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
    Node *holder = head;
    if (index >= count) {
        throw std::out_of_range("error");
    }
    else {
        for (unsigned int i = 0; i < index; i++) {
            holder = holder->next;
        }
    }
    return holder->data;
}
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const{
    Node *holder = head;
    if (index >= count) {
        throw std::out_of_range("error");
    }
    else {
        for (unsigned int i = 0; i < index; i++) {
            holder = holder->next;
        }
    }
    return holder->data;
}


        ///-----PART THREE-----///

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = node->next;
    node->next = temp;
    temp->prev = node;
    count++;
}


template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
    Node* temp = new Node();
    Node *holder;
    holder = node->prev;
    holder->next = temp;
    temp->data = data;
    temp->prev = node->prev;
    node->prev = temp;
    temp->next = node;
    count++;
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
    Node * holder = head;
    if (index > count){
        return;
    }
    else if(index == 0){
        AddHead(data);
    }
    else if(index == count){
        AddTail(data);
    }
    else {
        holder = GetNode(index);
            InsertBefore(holder, data);
    }
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const{
    if (head->data == rhs.head -> data && tail -> data == rhs.tail -> data){
        return true;
    }
        return false;
}

        ///-----PART FOUR-----//

    /// removal ///

template <typename T>
bool LinkedList<T>::RemoveHead(){
    Node *holder = head;
    if (head == nullptr) {
        return false;
    }
    if (head -> next != nullptr) {
        head = head->next;
        head -> prev = nullptr;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }
    delete holder;
    holder = nullptr;
    count--;
    return true;
}

template <typename T>
bool LinkedList<T>::RemoveTail() {
    Node *holder = tail;
    if (tail == nullptr) {
        return false;
    }
    if (tail -> prev != nullptr) {
        tail = tail->prev;
        tail -> next = nullptr;
    }
    else {
        tail = nullptr;
        head = nullptr;
    }
    delete holder;
    holder = nullptr;
    count--;
    return true;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
    Node *holder = head, *temp;
    unsigned int remove = 0;
    while (holder != nullptr)
    {
        if (holder->data == data)
        {
            holder->prev->next = holder->next;
            holder->next->prev = holder->prev;
            temp = holder->next;
            delete holder;
            holder = temp;
            remove++;
            count--;
            continue;
        }
        holder = holder->next;
    }
    return remove;
}



template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
    unsigned int set = 0;
    Node *holder = head;
    if (index >= count || index < 0) {
        return false;
    }
    while (holder != nullptr && set < index) {
        holder = holder -> next;
        set++;
    }
    if (holder == nullptr){
        return false;
    }
    else {
        if (holder -> prev != nullptr){
            holder -> prev -> next = holder -> next;
        }
        if (holder -> next != nullptr){
            holder -> next -> prev = holder -> prev;
        }
        delete holder;
        holder = nullptr;
        count--;
        return true;
    }

}
template <typename T>
void LinkedList<T>::Clear() {
    Node *holder = head;
    while (head != nullptr) {
        head = head->next;
        delete holder;
        holder = head;
    }
    head = tail = nullptr;
    count = 0;
}

    /// print recursive ///

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
    if (node == NULL) {
        return;
    }
    else {
        cout << node -> data << endl;
    }
    node = node -> next;
    PrintForwardRecursive(node);
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
    if (node == NULL) {
        return;
    } else {
        cout << node->data << endl;
    }
    node = node->prev;
    PrintReverseRecursive(node);
}

