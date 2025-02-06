// Remove the Highest Elements
// list_delete_highest.c
//
// Written by Caitlin Wong (z5477471)
// on 30/07/2023
//
// This program scans in a list and deletes the all nodes in the linked 
// list whose data field are equal to the highest data value in the list.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LIST_LEN 100

struct node {
    struct node *next;
    int          data;
};

struct node *delete_highest(struct node *head);
struct node *array_to_list(int len, int array[]);
void print_list(struct node *head);
static void free_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(void) {
    // scan in quantity of numbers
    printf("Total numbers in list: ");
    int list_size;
    scanf(" %d", &list_size);

    // scan numbers into array
    int n_read = 0;
    int numbers_list[MAX_LIST_LEN] = {0};
    while (n_read < list_size && scanf(" %d", &numbers_list[n_read])) {
        n_read++;
    }

    // create linked list from inputs
    struct node *head = array_to_list(n_read, numbers_list);

    struct node *new_head = delete_highest(head);
    print_list(new_head);
    
    free_list(new_head);

    return 0;
}


//
// Delete the node(s) in the list that contain the highest value
// The deleted node(s) are freed.
// The head of the list is returned.
//
struct node *delete_highest(struct node *head) {
    if (head == NULL) {
        return head;
    } else if (head->next == NULL) {
        free(head);
        return NULL;
    }

    int highest = head->data;
    struct node *current = head;

    while (current != NULL) {
        if (current->data > highest) {
            highest = current->data;
        }
        current = current->next;
    }
    struct node *freed = head;
    while (freed != NULL && freed->next != NULL) {
        if (freed->next->data == highest) {
            struct node *next_node = freed->next;
            freed->next = freed->next->next;
            free(next_node);
        } else {
            freed = freed->next;
        }
    }
    if (head->data == highest) {
        struct node *new_head = head->next;
        free(head);
        return new_head;
    }
    return head;
}


// DO NOT CHANGE THIS FUNCTION
// Free all nodes in the supplied list
static void free_list(struct node *head) {
    if (head != NULL) {
        free_list(head->next);
        free(head);
    }
}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of ints
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

// DO NOT CHANGE THIS FUNCTION
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
