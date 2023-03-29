#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
}

Node* getLastNode(Node* node)
{
    if (node != NULL)
    {
        while (node->next != NULL)
        {
            node = node->next;
        }
        return node;
    }
    return NULL;

}

Node* createNewValue(int val)
{
    Node* newValue = (Node*)malloc(sizeof(Node));
    if (newValue != NULL)
    {
        newValue->value = val;
        newValue->next = NULL;
    }
    return newValue;
}

void appendElement(Node** list, int value)
{
    Node* newValue = createNewValue(value);
    if (*list != NULL)
    {
        Node* temp = *list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newValue;
    }
    else
    {
        *list = newValue;
    }

}

void deleteList(Node** list)
{
    Node* ptr;
    while (*list != NULL)
    {
        //printf("addr=%d",*list)
        ptr = *list;
        *list = (*list)->next;
        free(ptr);
    }
}

int showElement(Node* list, int index)
{
    int i = 0;
    while (list != NULL)
    {
        if (i == index)
            return list->value;
        else
            list = list->next;
        i++;
    }
    return -1;
}

Node* getElement(Node* list, int index)
{
    int i = 0;
    while (list != NULL)
    {
        if (i == index)
            return list;
        else
            list = list->next;
        i++;
    }
    return NULL;
}

Node* push(Node** list, int value)
{
    Node* newValue = createNewValue(value);
    newValue->next = *list;
    *list = newValue;
    return newValue;
}

int pop(Node** list)
{
    Node* ptr = *list;
    int value = ptr->value;
    *list = ptr->next;
    free(ptr);
    return value;
}

Node* createList(int* ptr, int size)
{
    Node* head = NULL;
    while (size--)
    {
        appendElement(&head, *(ptr++));
    }
    return head;
}

void reverseList(Node** list)
{
    Node* current = *list;
    Node* next = NULL;
    Node* previous = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *list = previous;
}

int sizeList(Node* list)
{
    int noElements = 0;

    while (list != NULL)
    {
        list = list->next;
        noElements++;
    }

    return noElements;
}

void insertElement(Node** list, int index, int value)
{
    if (index == 0)
    {
        push(list, value);
    }
    else if (index == (sizeList(*list) - 1))
    {
        appendElement(list, value);
    }
    else
    {
        Node* temp = *list;
        Node* previous = NULL;

        int it = 0;
        while (it != index)
        {
            previous = temp;
            temp = temp->next;
            it++;
        }
        Node* newNode = createNewValue(value);
        previous->next = newNode;
        newNode->next = temp;

    }
}

void deleteElement(Node** list, int index)
{
    if (index == 0)
    {
        pop(list);
    }
    else
    {
        Node* temp = *list;
        Node* previous = NULL;

        int it = 0;
        while (it != index)
        {
            previous = temp;
            temp = temp->next;
            it++;
        }

        previous->next = temp->next;
        free(temp);

    }
}

void swapElements(Node** list, int a, int b)
{
    int size = sizeList(*list);
    Node *ptrA, *ptrB, *prevA, *prevB;
    Node* temp;

    if(a < size && b < size)
    {
        if(a!=0)
        {
            prevA = getElement(*list, a-1);
            ptrA = prevA->next;
        }
        else
            ptrA = getElement(*list, a);

        if(b!=0)
        {
            prevB = getElement(*list, b-1);
            ptrB = prevB->next;
        }
        else
            ptrB = getElement(*list, b);

        if(a!=0)
            prevA->next = ptrB;
        if(b!=0)
            prevB->next = ptrA;

        temp = ptrA->next;
        ptrA->next = ptrB->next;
        ptrB->next = temp;

        if(a==0)
            *list = ptrB;
        else if(b==0)
            *list = ptrA;

    }
}