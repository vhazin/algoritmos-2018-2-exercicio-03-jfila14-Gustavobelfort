#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void append(struct Node **head_ref, int new_data);
void deleteNode(struct Node **head_ref, int key);
void printList(struct Node *node);

int main()
{

  struct Node *head = NULL;

  int listSize;
  scanf("%d", &listSize);
  for (int i = 0; i < listSize; i++)
  {
    int Element = 0;
    scanf("%d", &Element);
    append(&head, Element);
  }

  int finalListsize;
  scanf("%d", &finalListsize);
  for (int i = 0; i < finalListsize; i++)
  {
    int ElementO = 0;
    scanf("%d", &ElementO);
    deleteNode(&head, ElementO);
  }

  printList(head);
}

void append(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  struct Node *last = *head_ref;

  new_node->data = new_data;

  new_node->next = NULL;

  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void deleteNode(struct Node **head_ref, int key)
{
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key)
  {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;

  free(temp);
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
}