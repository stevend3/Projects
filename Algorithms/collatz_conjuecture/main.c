// This file calculates the steps from any number to 1 using the Collatz Conjecture
// Created by Steven Diniz
#include <stdio.h>
#include <stdlib.h>

// define the structure of a node for a list
struct node {
    int data;
    struct node * next;
};
int collatz_conjecture(int, struct node *);
struct node * append(struct node * head, int data);
void printList(struct node * head);

int main() {
    int num = -1;
    int success = 0;
    char junk;
    // initialize the list
    struct node * head = malloc(sizeof(struct node));

    // keep prompting user for input until a # > 1 is entered
    while (num < 1){
        printf("Enter an integer greater than 1: ");
        success = scanf("%d", &num);
        if (success == 0) scanf("%c", &junk);
    }
    // store the info in first node of list
    head->data = num;
    head->next = NULL;
    // calculate the steps
    int steps = collatz_conjecture(num, head);
    // print the steps
    printList(head);
    printf("The number of steps it takes to reach 1 from %d is: %d", num, steps);
    return 0;
}

// Apply the collatz conjecture to find the number of steps from any number to 1
// Parameters:
//      int num: the starting number
//      struct node * head: beginning node of a list
// Return: the number of steps from num to 1
int collatz_conjecture(int num, struct node * head) {
    int steps = 0;
    while (num > 1) {
        // num is even
        if (num % 2 == 0) {
            steps++;
            num /= 2;
            // append step to list
            head = append(head, num);
        }
        // num is odd
        else {
            steps++;
            num = (3 * num) + 1;
            // append step to list
            head = append(head, num);
        }
    }
    return steps;
}

// Append a new node at the end of a list
// Parameters:
//  struct node * head: the beginning of the list to append to
//  int data: number to append
// Returns: a pointer to the head of the updated list
struct node * append(struct node * head, int data) {
    struct node * p = head;
    struct node * prev = NULL;
    // initialize the new node to add
    struct node * new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // scan through list
    while (p) {
        prev = p;
        p = p->next;
    }
    // add node to list
    if (head) {
        prev->next = new;
    }
    else head = new;
    return head;
}

// Print a list
// Parameters:
//  struct node * head: start of list to print
// Returns: nothing
void printList(struct node * head) {
    int steps = 0;
    printf("Steps: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
        steps++;
        // only print 25 numbers per line for formatting
        if (steps % 25 == 0) printf("\n");
    }
    printf("\n");
}