#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Database.h"

int addEntry(u8 id,u8 year,u8* subjects,u8* grades){
struct node* ptr = NULL;
ptr = (struct node*)malloc(sizeof(struct node));
int flag = 0;
if(count>9){
    printf("Exceeded the maximum number of allowed entries >> exit ");
    return 0;
}
if(ptr){
    ptr->student_id = id;
    ptr->student_year = year;
    ptr->courses_ids[0] = subjects[0];
    ptr->courses_ids[1] = subjects[1];
    ptr->courses_ids[2] = subjects[2];
    ptr->courses_grades[0] = grades[0];
    ptr->courses_grades[1] = grades[1];
    ptr->courses_grades[2] = grades[2];
    ptr->pnex = ptr->pprev = NULL;

    if(ptr->courses_grades[0]>100 || ptr->courses_grades[1]>100 || ptr->courses_grades[2]>100){
    printf("Grades must be in range of 100 ... failed to add entry");
    return 0;
    }
    if(!head){
        head = tail = ptr;
        flag = 1;
        count++;
    }
    else{
        tail->pnex = ptr;
        ptr->pprev = tail;
        tail = ptr;
        flag = 1;
        count++;
    }

}
else{
    printf("Failed to access memory ");
    flag = 0;
}
return flag;
}
void printList(){
    int i; struct node* temp = head;
    if(count == 0)
        printf("There's no entries to show ");
    for(i = 0;temp != NULL;i++){
            printf("\nstudent %d ID = %d",i,temp->student_id);
            printf("  Subject %d IDs = %d  %d  %d",i,temp->courses_ids[0],temp->courses_ids[1],temp->courses_ids[2]);
            temp = temp->pnex;


    }
 printf("\nnumber of current entries = %d",count);
}
int isFull(){
if(count < 10)
    return 0;
    else if(count == 10)
    return 1;
}
u8 existEntries(){
if(count == 0)
    return 0;
else
    return count;
}
int isIDexist(u8 stID){
int i; struct node* temp1 = NULL;
    temp1 = head;
    if(temp1 == NULL){
        return -1;
    }
    else {
    for(i = 0;temp1 != NULL;i++){
          if(temp1->student_id == stID){
            return 1;
            }
     temp1 = temp1->pnex;
          }
    }
return 0;
}
int ReadEntry(u8 stdID){
    int i; struct node* temp1 = NULL;
    temp1 = head;
    if(temp1 == NULL){
        return -1;
    }
    else {
    for(i = 0;temp1 != NULL;i++){
          if(temp1->student_id == stdID){
                printf("Student year = %d\n",temp1->student_year);
                printf("Subjects IDs = %d  %d  %d",temp1->courses_ids[0],temp1->courses_ids[1],temp1->courses_ids[2]);
                printf("\nGrades of student = %d  %d  %d",temp1->courses_grades[0],temp1->courses_grades[1],temp1->courses_grades[2]);
            return 1;
            }
     temp1 = temp1->pnex;
          }
    }
return 0;
}
void DeleteEntry(u8 stdID){
int i; struct node* temp1 = NULL; int f = 0;
    temp1 = head;
    if(temp1 == NULL){
        printf("There's no entry to delete ");
    }
    else {
    for(i = 0;temp1 != NULL;i++){
            if(temp1->student_id == stdID){
                if(count == 1){
                    free(temp1);
                    head = tail = NULL;
                    count--;
                    printf("Entry deleted");
                    return;
                }
                if(temp1 == head){
                    head = temp1->pnex;
                    temp1->pnex->pprev = NULL;
                    temp1->pnex = NULL;
                    free(temp1);
                    count--; f=1;
                    printf("Entry deleted");
                }
                else if (temp1 == tail){
                    tail = temp1->pprev;
                    temp1->pprev->pnex = NULL;
                    temp1->pprev = NULL;
                    free(temp1);
                    count--; f=1;
                    printf("Entry deleted");
                }
                else{
                    temp1->pprev->pnex = temp1->pnex;
                    temp1->pnex->pprev = temp1->pprev;
                    temp1->pnex = NULL; temp1->pprev = NULL;
                    free(temp1);
                    count--; f=1;
                    printf("Entry deleted");
                }

            }

             temp1 = temp1->pnex;
}
if(f == 0)
    printf("Entered ID doesn't match any of Database IDs");


    }
}
void show()
{
printf("\n                                        ************** The Main Menue **************\n\nPlease Choose One of the Following :.....\nNote: IDs must be positive numbers,between range of 0-255. Distinct IDs are preferable\n\n");
printf("	p : print All IDs \n");
printf("	i : Check if the database is full\n");
printf("	e : Add new Data entry\n");
printf("	r : Read Data by provided student ID\n");
printf("	d : Delete Entry by ID\n");
printf("	k : Search for student by ID\n");
printf("	c : Print number of exist entries\n");
printf("	x : to Exit\n");
}

