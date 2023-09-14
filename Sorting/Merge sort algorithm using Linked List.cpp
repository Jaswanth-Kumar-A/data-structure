#include <stdio.h>
#include <stdlib.h>

// Structure for a singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists and return the merged list
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to split the linked list into two halves
void split(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Function to perform merge sort on a linked list
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    if (head == NULL || head->next == NULL) {
        return; // Base case: empty or single-element list is already sorted
    }

    // Split the list into two halves
    split(head, &a, &b);

    // Recursively sort the sublists
    mergeSort(&a);
    mergeSort(&b);

    // Merge the sorted sublists
    *headRef = merge(a, b);
}

// Function to insert a new node at the end of the linked list
void append(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    // Perform merge sort on the linked list
    mergeSort(&head);

    // Print the sorted linked list
    printf("Sorted list:\n");
    printList(head);

    return 0;
}
