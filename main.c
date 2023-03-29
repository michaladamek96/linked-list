#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    int arr[] = { 1,2,3 };

    printf("1. Create list\n");
    Node* list = createList(arr, 3);
    printf("List size=%d\n",sizeList(list));

    printf("\n2. Print list\n");
    printList(list);
    printf("\n");

    printf("\n3. Push element with value=5\n");
    push(&list, 5);
    printList(list);
    printf("\n");

    printf("\n4. Insert element with value=7 at index=2\n");
    insertElement(&list, 2, 7);
    printList(list);
    printf("\n");

    printf("\n5. Pop element\n");
    pop(&list);
    printList(list);
    printf("\n");

    printf("\n6. Delete element at index=1\n");
    deleteElement(&list, 1);
    printList(list);
    printf("\n");

    printf("\n7. Reverse list\n");
    reverseList(&list);
    printList(list);
    printf("\n");

    printf("\n8. Swap elements at index=1 and 2 and then index=0 and 2\n");
    swapElements(&list, 1, 2);
    printList(list);
    printf("\n");
    swapElements(&list, 0, 2);
    printList(list);
    printf("\n");

    printf("\n9. Delete list\n");
    deleteList(&list);
    printf("List size=%d\n",sizeList(list));
    printf("\n");

    return 0;
}
