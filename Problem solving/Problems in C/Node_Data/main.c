#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *next;
struct node *prev;
};
struct node *head;
struct node *tail;
int main()
{
  struct node node1;
  struct node node2;
  struct node node3;
  head = &node1;
  tail = &node3;
  head->next = &node2;
  head->next->next = &node3;
  tail->prev = &node2;
  tail->prev->prev = &node1;
  head->data = 500;
  head->next->data = 123;
  head->next->next->data = 321;
  printf("%d ",tail->data);
  printf("%d ",tail->prev->data);
  printf("%d ",tail->prev->prev->data);
  //head->ptr->ptr = head;
  //head->ptr->data = 123;
  //printf("%d",tail->data);
  return 0;
}
