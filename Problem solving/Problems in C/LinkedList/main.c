#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    int i;

   head = tail = NULL;
   //struct node *ptr3 = createNode(5);
    addNode(10);

   /*  addNode(1);
    addNode(9);
    //insertData(2,3);*/


  //  insertData(7,1);
  //  int x = searchData(0);


    struct node *pcur = head;
    for(i = 0;pcur != NULL ;i++){
    printf("%d \n",pcur->data);
   pcur = pcur->pnex;




}
// printf("%d ",x);
}
