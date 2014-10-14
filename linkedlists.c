/*
  Linked List Problems
  Based on Nick Parlante's Linked List Problems
  <http://cslibrary.stanford.edu/105/LinkedListProblems.pdf>

  Kai Rikhye
  http://github.com/dutycycle
  September 2014
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Define a singly linked list node */

typedef struct Node {
  int data;
  struct Node *next;
} Node_t;

/* Utility functions: Printing */

void print_node(Node_t *node) {
  printf("%d -> ", node -> data);
}

void print_linked_list(Node_t *head) {
  Node_t *cur = head;

  while (cur) {
    print_node(cur);
    cur = cur -> next;
  }

  printf("\n");
}

/** Utility functions: Insertion **/


void insert_at_tail(Node_t *head, int data) {
  Node_t *cur = head;

  while (cur -> next) {
    cur = cur -> next;
  }

  Node_t *inserted = malloc(sizeof(Node_t));
  inserted -> data = data;
  inserted -> next = NULL;

  cur -> next = inserted;
}

void insert_at_head(Node_t **head, int data) {
  Node_t *newhead = malloc(sizeof(Node_t));

  newhead -> data = data;
  newhead -> next = *head;

  *head = newhead;
}

void insert_after_value(Node_t *head, int value, int data) {
  Node_t *cur = head;

  while (cur) {
    if (cur -> data == value) {
      Node_t *new_node = malloc(sizeof(Node_t));
      new_node -> data = data;
      new_node -> next = cur -> next;
      cur -> next = new_node;
      return;
    }
    cur = cur -> next;
  }
}

void reverse_linked_list(Node_t **head_ref) {
  Node_t *cur = *head_ref;
  Node_t *prev = NULL;
  Node_t *next = NULL;
  
  while (cur) {
    next = cur -> next;
    cur -> next = prev;
    prev = cur;
    cur = next;
  }

  *head_ref = prev;
}

void recurse_reverse_linked_list(Node_t **head_ref) {
  Node_t *head = *head_ref;

  if (head == NULL || head -> next == NULL) {
    return;
  }
  
  Node_t *rest = head -> next;
  
  recurse_reverse_linked_list(&rest);

  head -> next -> next = head;
  head -> next = NULL;

  *head_ref = rest;
}

/*
  Exercise 1: Count

  Returns the number of times a given int occurs in a list.
*/

int count(Node_t *head, int value_to_count) {
  Node_t *cur = head;
  int my_count = 0;
  
  while (cur) {
    if (cur -> data == value_to_count) {
      my_count++;
    }
  }

  return my_count;
}

/*
  Exercise 2: GetNth

  Returns the n-th element of the list, where n is zero-indexed.

  asserts failure if n is not in bounds.
*/

int get_node_at_index(Node_t *head, int index) {
  Node_t *cur = head;

  assert(cur != NULL);

  if (index == 0) return head -> data;
  
  for (int i = 1; i < index; i++) {
    cur = cur -> next;
    assert(cur != NULL);
  }

  return cur -> data;
}

/*
  Exercise 3: DeleteList

  Deallocate a list and null the head pointer.
*/

void delete_list(Node **head_ref) {
  Node_t *cur = *head_ref;
  Node_t *next = NULL;
  
  while (cur) {
    next = cur -> next;
    free(cur);
    cur = next;
  }

  *head_ref = NULL;
}

int main() {
  Node_t *head = malloc(sizeof(Node_t));

  head -> data = 5;
  head -> next = NULL;

  insert_at_tail(head, 6);
  insert_at_head(&head, 4);
  insert_after_value(head, 4, 7);
  
  print_linked_list(head);

  reverse_linked_list(&head);

  print_linked_list(head);

  recurse_reverse_linked_list(&head);

  print_linked_list(head);
}


