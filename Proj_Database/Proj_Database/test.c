#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Database.h"
int func(){
struct node* ptr = (struct node*)malloc(sizeof(struct node));
ptr->student_id = 20;
printf("%d",ptr->student_id);
}
