#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;


// ============================================================
// 1. CUSTOM VECTOR
// ============================================================

template <typename T>
class MyVector {

private:
    T* arr;
    int capacity;
    int size;

    void resize() {

        capacity *= 2;

        T* newArr = new T[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;

        arr = newArr;
    }

public:

    MyVector(int initialCapacity = 2) {

        capacity = initialCapacity;
        size = 0;

        arr = new T[capacity];
    }

    ~MyVector() {
        delete[] arr;
    }

    void push_back(const T& value) {

        if (size == capacity) {
            resize();
        }

        arr[size] = value;
        size++;
    }

    void pop_back() {

        if (size > 0) {
            size--;
        }
    }

    T& operator[](int index) {
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }
};


// ============================================================
// 2. CUSTOM LINKED LIST
// ============================================================

template <typename T>
class MyLinkedList {

private:

    struct Node {

        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:

    MyLinkedList() {

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~MyLinkedList() {

        Node* current = head;

        while (current != nullptr) {

            Node* nextNode = current->next;

            delete current;

            current = nextNode;
        }
    }

    void push_front(const T& value) {

        Node* newNode = new Node(value);

        newNode->next = head;

        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        size++;
    }

    void push_back(const T& value) {

        Node* newNode = new Node(value);

        if (head == nullptr) {

            head = newNode;
            tail = newNode;
        }
        else {

            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void pop_front() {

        if (head == nullptr) {
            return;
        }

        Node* temp = head;

        head = head->next;

        delete temp;

        size--;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    T& front() {
        return head->data;
    }

    T& back() {
        return tail->data;
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }
};


// ============================================================
// 3. CUSTOM STACK
// ============================================================

template <typename T>
class MyStack {

private:

    MyVector<T> data;

public:

    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {

        if (!data.empty()) {
            data.pop_back();
        }
    }

    T& top() {
        return data[data.getSize() - 1];
    }

    bool empty() const {
        return data.empty();
    }

    int size() const {
        return data.getSize();
    }
};


// ============================================================
// 4. CUSTOM QUEUE
// ============================================================

template <typename T>
class MyQueue {

private:

    MyLinkedList<T> data;

public:

    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        data.pop_front();
    }

    T& front() {
        return data.front();
    }

    bool empty() const {
        return data.empty();
    }

    int size() const {
        return data.getSize();
    }
};


// ============================================================
// MAIN
// ============================================================

int main() {

    const int N = 1000000;


    // ========================================================
    // BASIC USAGE
    // ========================================================

    cout << "========================================" << endl;
    cout << "       BASIC USAGE OF CUSTOM DS" << endl;
    cout << "========================================" << endl;
    cout << endl;


    // ---------------- VECTOR ----------------

    MyVector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Vector: ";

    for (int i = 0; i < v.getSize(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;


    // ---------------- LINKED LIST ----------------

    MyLinkedList<string> list1;

    list1.push_back("Tanmay");
    list1.push_back("Rahul");
    list1.push_back("Amit");

    cout << "LinkedList front: "
         << list1.front() << endl;


    // ---------------- STACK ----------------

    MyStack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack top: "
         << s.top() << endl;


    // ---------------- QUEUE ----------------

    MyQueue<int> q;

    q.push(100);
    q.push(200);
    q.push(300);

    cout << "Queue front: "
         << q.front() << endl;


    // ========================================================
    // PERFORMANCE COMPARISON
    // ========================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "       CUSTOM vs STL PERFORMANCE" << endl;
    cout << "========================================" << endl;
    cout << endl;


    // ========================================================
    // VECTOR COMPARISON
    // ========================================================

    MyVector<int> customVector;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        customVector.push_back(i);
    }

    auto end = high_resolution_clock::now();

    double customVectorTime =
        duration<double, milli>(end - start).count();


    vector<int> stlVector;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        stlVector.push_back(i);
    }

    end = high_resolution_clock::now();

    double stlVectorTime =
        duration<double, milli>(end - start).count();


    // ========================================================
    // LINKED LIST COMPARISON
    // ========================================================

    MyLinkedList<int> customList;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        customList.push_back(i);
    }

    end = high_resolution_clock::now();

    double customListTime =
        duration<double, milli>(end - start).count();


    list<int> stlList;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        stlList.push_back(i);
    }

    end = high_resolution_clock::now();

    double stlListTime =
        duration<double, milli>(end - start).count();


    // ========================================================
    // STACK COMPARISON
    // ========================================================

    MyStack<int> customStack;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        customStack.push(i);
    }

    end = high_resolution_clock::now();

    double customStackTime =
        duration<double, milli>(end - start).count();


    stack<int> stlStack;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        stlStack.push(i);
    }

    end = high_resolution_clock::now();

    double stlStackTime =
        duration<double, milli>(end - start).count();


    // ========================================================
    // QUEUE COMPARISON
    // ========================================================

    MyQueue<int> customQueue;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        customQueue.push(i);
    }

    end = high_resolution_clock::now();

    double customQueueTime =
        duration<double, milli>(end - start).count();


    queue<int> stlQueue;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        stlQueue.push(i);
    }

    end = high_resolution_clock::now();

    double stlQueueTime =
        duration<double, milli>(end - start).count();


    // ========================================================
    // PRINT RESULTS
    // ========================================================

    cout << "===== VECTOR COMPARISON =====" << endl;

    cout << "Custom Vector push_back : "
         << customVectorTime
         << " ms" << endl;

    cout << "STL Vector push_back    : "
         << stlVectorTime
         << " ms" << endl;

    cout << endl;


    cout << "===== LINKED LIST COMPARISON =====" << endl;

    cout << "Custom LinkedList push_back : "
         << customListTime
         << " ms" << endl;

    cout << "STL List push_back          : "
         << stlListTime
         << " ms" << endl;

    cout << endl;


    cout << "===== STACK COMPARISON =====" << endl;

    cout << "Custom Stack push : "
         << customStackTime
         << " ms" << endl;

    cout << "STL Stack push    : "
         << stlStackTime
         << " ms" << endl;

    cout << endl;


    cout << "===== QUEUE COMPARISON =====" << endl;

    cout << "Custom Queue push : "
         << customQueueTime
         << " ms" << endl;

    cout << "STL Queue push    : "
         << stlQueueTime
         << " ms" << endl;


    // ========================================================
    // TIME COMPLEXITY
    // ========================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "          TIME COMPLEXITY" << endl;
    cout << "========================================" << endl;
    cout << endl;


    cout << "Vector:" << endl;
    cout << "  push_back : O(1) amortized" << endl;
    cout << "  pop_back  : O(1)" << endl;
    cout << "  access    : O(1)" << endl;
    cout << endl;


    cout << "LinkedList:" << endl;
    cout << "  push_front : O(1)" << endl;
    cout << "  push_back  : O(1)" << endl;
    cout << "  pop_front  : O(1)" << endl;
    cout << "  search     : O(n)" << endl;
    cout << endl;


    cout << "Stack:" << endl;
    cout << "  push : O(1) amortized" << endl;
    cout << "  pop  : O(1) amortized" << endl;
    cout << "  top  : O(1)" << endl;
    cout << endl;


    cout << "Queue:" << endl;
    cout << "  push  : O(1)" << endl;
    cout << "  pop   : O(1)" << endl;
    cout << "  front : O(1)" << endl;


    return 0;
}