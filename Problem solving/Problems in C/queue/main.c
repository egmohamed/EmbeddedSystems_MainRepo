#include <stdio.h>
#include <stdlib.h>
#include "queu.h"

int main()
{
    struct node *ptr4 = tail;
   enque(4);
   enque(3);
    printf("%d",tail->data);
    return 0;
}
