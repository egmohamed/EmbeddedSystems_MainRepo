#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

 struct node* createNode(int data){
    struct node *ptr = NULL;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr){

        ptr->data = data;
       // printf("%d\n",ptr->data);
        ptr->pnex = ptr->pprev = NULL;

        return ptr;
    }

 }
int addNode(int data){
struct node *ptr = createNode(data);
//printf("%d\n",ptr->data);
int flag = 0;
if(ptr){
    flag = 1;

    if(!head){
        head = tail = ptr;
   // printf("%d\n",head->data);
    }
    else{
    tail->pnex = ptr;
    ptr->pprev = tail;
    tail = ptr;
//printf("%d\n",tail->data);
    // printf("hi\n");
    }

}

}
int insertData(int data,int loc){
int flag = 0; int i = 0;
struct node *ptr;   struct node *pcur;
ptr = createNode(data);
if(ptr){

    flag = 1;
    if(!head)
        head = tail = ptr;
    else if (loc == 0){

        ptr->pnex = head;
        head->pprev = ptr;
        head = ptr;
    }
    else{
    pcur = head;
    for(i = 0;i<loc;i++){
        pcur = pcur->pnex;
    if(pcur->pnex = NULL){
        break;}
    }
    if(pcur == tail){
            tail->pnex = ptr;
            ptr->pprev = tail;
            tail = ptr;
    }
    else{
            pcur->pprev->pnex = ptr;
            ptr->pprev = pcur->pprev;
            pcur->pprev = ptr;
            ptr->pnex = pcur;
}
}
}
return flag;
}

int searchData(int value){
    int i;
struct node *se = head;
for(i = 0;se != NULL;i++){
    se = se->pnex;
    if(se->data = value )
        return 1;
    else return -1;
}

}
