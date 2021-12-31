#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

// Funktion för att lägga till en post i slutet av listan
void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

// Funktion för att lägga till en post i början av listan
void pushBeginning(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(node_t * head) {
    int retval = 0;

    // Om det bara finns en post så radera den
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    // Gå till den näst sista posten i listan
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Nu pekar current på näst sista posten så radera current->next
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;

}

int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return -1;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}

int main(int argc, char **argv) {

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    
    //if (head == NULL) {
    //    return 1;
    //}

    head->val = 0;
    head->next = NULL;

    for(int i = 1; i < 1000000; i++) {
        push(head, i);
    }
    
    print_list(head);

}