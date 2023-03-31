#ifndef LIST_H_
#define LIST_H_

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createList(int* ptr, int size);

void printList(Node* list);
int showElement(Node* list, int index);
Node* getElement(Node* list, int index);
Node* getLastNode(Node* list);
int sizeList(Node* list);

Node* createNewValue(int val);
void appendElement(Node** list, int value);
Node* push(Node** list, int value);
void insertElement(Node** list, int index, int value);

void deleteList(Node** list);
void deleteElement(Node** list, int index);
int pop(Node** list);

void reverseList(Node** list);
void swapElements(Node** list, int a, int b);
void sortList(Node** list);


#endif
