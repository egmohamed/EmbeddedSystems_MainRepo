#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define work 1
#define exit 0
typedef unsigned char u8;
static count = 0;
struct node{
u8 student_id;
u8 student_year;
u8 courses_ids[3];
u8 courses_grades[3];
struct node *pnex;
struct node *pprev;
};

struct node* head;
struct node* tail;
void show();
int addEntry(u8 id,u8 year,u8* subjects,u8* grades);
void printList();
int isFull();
u8 existEntries();
int isIDexist(u8 stID);
ReadEntry(u8 stdID);
void DeleteEntry(u8 stdID);
