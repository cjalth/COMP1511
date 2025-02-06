#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data, struct node *next);
void print_list(struct node *head);
struct node *insert_at_tail(int data, struct node *head);
struct node *insert_at_index(struct node *head, int index, int data);
struct node *remove_tail(struct node *head);
struct node *delete_at_index(struct node *head, int index);

int main(void) {

    struct node *head = create_node(7,NULL);
    head = create_node(8,head);
    head = create_node(11, head);

    print_list(head);
    insert_at_tail(6,head);
    print_list(head);

    head = insert_at_index(head, 2, 42);
    print_list(head);
    // expected: 11 -> 8 -> 42 -> 7 -> 6

    head = remove_tail(head);
    print_list(head);
    // expected: 11 -> 8 -> 42 -> 7

    head = delete_at_index(head, 0);
    return 0;
}

// insert at after position
struct node *insert_at_index(struct node *head, int index, int data) {
    index--;
    struct node *current_node = head;

    int i = 0;
    while (current_node != NULL) {
        if (i == index) {
            // let's add the node
            current_node->next = create_node(data, current_node->next);
            // return
        }
        //advance to the neext node
        current_node = current_node->next;
        i++;
    }
    return head;
}

struct node *create_node(int data, struct node *next) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

// prints a list
void print_list(struct node *head) {
    struct node *current_node = head;
    printf("My linked list is: \n");
    // loop until the end of the list
    while (current_node != NULL) {
        // print out the element
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
}

struct node *insert_at_tail(int data, struct node *head) {
    // traverse the linked list until we reach the last element
    struct node *current_node = head;
    // while we're not at the last element
    while (current_node->next != NULL) {
        // keep moving
        current_node = current_node->next;
    }
    // current_node is pointing at the last element

    // new node containing int data
    current_node->next = create_node(data,NULL); 

    return current_node;

}

// returns the HEAD of a new list in which the tail
// element is removed
struct node *remove_tail(struct node *head) {
    struct node *previous = head;
    struct node *current = head;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);
    return head;
}

struct node *delete_at_index(struct node *head, int index) {
    struct node *current_node = head;
    struct node *previous = head;

    int i = 0;

    while (current_node != NULL) {

        if (index == i) {
            if (previous == NULL) {
                //we are at the first element (0)
                struct node *result = current_node->next;
                free(current_node);
                return result;
            }
            //we can delete current node
            // and connect previous to current's next
            previous->next = current_node->next;
            free(current_node);
            return head;
        }
        previous = current_node;

    }
    return head;
}