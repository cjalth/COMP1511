// Insert into the nth position in a Linked List
// list_insert_nth.c
//
// Written by Caitlin Wong (z5477471) 
// on 22/07/2023
//
// This program creates a new list node containing a
// value and places it in the nth position of a linked list.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *insert_nth(int n, int value, struct node *head);
struct node *create_node(int data, struct node *next);
struct node *array_to_list(int len, int array[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION
#define MAX_INIT_LIST_LEN 100
int main() {
    // Need to read in a number of ints into an array
    printf("How many numbers in initial list?: ");
    int list_size = 0;
    scanf("%d", &list_size);
    int initial_elems[MAX_INIT_LIST_LEN] = {0};
    int n_read = 0;
    while (n_read < list_size && scanf("%d", &initial_elems[n_read])) {
        n_read++;
    }

    // create linked list from first set of inputs
    struct node *head = NULL;
    if (n_read > 0) {
        // list has elements
        head = array_to_list(n_read, initial_elems);
    }

    printf("Enter position and value to insert: ");
    int n;
    scanf("%d", &n);
    int value;
    scanf("%d", &value);

    struct node *new_head = insert_nth(n, value, head);
    print_list(new_head);

    return 0;
}


// Insert a new node containing value at position n of the linked list.
// if n == 0, node is inserted at start of list
// if n >= length of list, node is appended at end of list
// The head of the new list is returned.
struct node *insert_nth(int n, int value, struct node *head) {
    // PUT YOUR CODE HERE! CHANGE THE NEXT LINES!

    // PUT YOUR CODE HERE
    struct node *n_value = malloc(sizeof(struct node));
    n_value->data = value;
    n_value->next = NULL;
    int i = 1;
    if (head == NULL) {
        return n_value;
    }
    else if (n == 0) {
        n_value->next = head;
        return n_value;
    } else {
        struct node *current = head;
        while (n > i && current->next != NULL) {
            current = current->next;
            i++;
        }
        n_value->next = current->next;
        current->next = n_value;
    }

    return head;
}



// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *array_to_list(int len, int array[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = array[i];
        head = n;
        i -= 1;
    }   
    return head;
}

// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
