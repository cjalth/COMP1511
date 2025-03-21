// list_delete_contains_string.c
// This program removes the node in a linked list matching a given string
// Written by Caitlin Wong (z5477471), on 30/07/2023

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    struct node *next;
    char        data[MAX_SIZE];
};


struct node *delete_contains(char string[MAX_SIZE], struct node *head);
struct node *array_to_list(int len, char *array[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create linked list from command line arguments excluding the program name
    struct node *head = NULL;
    if (argc > 0) {
        // list has elements
        head = array_to_list(argc - 1, &argv[1]);
    }

    printf("Enter a string to delete: ");
    char string[MAX_SIZE];
    fgets(string, MAX_SIZE, stdin);
    string[strcspn(string, "\n")] = 0;
    struct node *new_head = delete_contains(string, head);
    print_list(new_head);

    return 0;
}


// Delete the first node in the list containing the specific string
// The deleted node is freed.
// If no node contains the specified string, the list is not changed
// The head of the list is returned.
struct node *delete_contains(char string[MAX_SIZE], struct node *head) {
    struct node *node = head;
    if (head == NULL) {
        return head;
    } else if (strcmp(head->data, string) == 0) {
        struct node *new_head = head->next;
        free(node);
        return new_head;
    } else if (head->next == NULL) {
        return head;
    }
    while (node->next->next != NULL && strcmp(node->next->data, string) != 0) {
        node = node->next;
    }
    if (strcmp(node->next->data, string) == 0) {
        struct node *next_node = node->next;
        node->next = node->next->next;
        free(next_node);
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *array_to_list(int len, char *array[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        strcpy(n->data, array[i]);
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
        printf("%s", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}