#include <stdio.h>
#include <stdlib.h>
#include "queu.h"
 struct node* createnode(int data){
    struct node *ptr = NULL;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr){

        ptr->data = data;
        ptr->pprev = ptr->pnext = NULL;
        return ptr;
    }
 }
int enque(int data){
struct node *ptr = createnode(data);
int flag = 0;
if(ptr){
    flag = 1;
}
    if(!head){
        head = tail = ptr;
    }
    else{
    //tail->pnext = ptr;
    ptr->pprev = tail;
    tail = ptr;
    }
return flag;
}

int Deque(void){
struct node *pcur = tail;
int temp;
int i;
for(i= 0;pcur->pprev != head;i++){

    pcur = pcur->pprev;
}
temp = head->data;
free(head);
pcur->pprev = NULL;
head = pcur;
return temp;
}
