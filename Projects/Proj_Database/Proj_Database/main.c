#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Database.h"

int main()
{
    int i; u8 counter; u8 IDstd; int IDsearch;
    int ReadID;
    char status=work;
    char s; int checkFull;
    head = NULL;
    printf("\n\n                                             ****** Welcome to DataBase ****** \n");
while(status)
{
show();
scanf(" %c",&s);
switch (s)
{
case 'p':
printList();
break;

case 'i':
checkFull = isFull();
if(checkFull == 1)
    printf("Database is full >> returned 1");
else
    printf("Database is NOT full >> returned 0");

break;

case 'e':
printf(" Please Enter student ID : ");
u8 id; u8 ye; u8 sub[3]; u8 gra[3]; u8 psub[3]; u8 pgra[3];
scanf(" %d", &id);
u8 pid = id;
printf(" Please Enter the year : ");
scanf(" %d", &ye);
u8 pye = ye;
printf(" Please Enter subjects IDs : ");
for(i = 0;i<3;i++){
    scanf(" %d", &sub[i]);
    psub[i] = sub[i];
}
printf(" Please Enter Grades out of 100 : ");
for(i = 0;i<3;i++){
    scanf(" %d", &gra[i]);
    pgra[i] = gra[i];
}
int checkAdd = addEntry(pid,pye,psub,pgra);
if(checkAdd == 1)
    printf("Element added , returned 1");

else
    printf(" returned 0");

break;

case 'r':
printf("Enter student ID you want to search for his data : ");
scanf("%d",&IDstd);
ReadID = ReadEntry(IDstd);
if(ReadID == -1)
    printf("There is no entries to search in >> returned -1");
else if (ReadID == 0)
    printf("Entered student ID is not found in Database >> returned 0");
else if(ReadID == 1)
    printf("\nID exist >> returned 1");
break;

case 'd':
printf("Enter student ID you want to delete from Database : ");
scanf("%d",&IDstd);
DeleteEntry(IDstd);
break;

case 'k':
printf("Enter ID of student you are looking for : ");
scanf("%d",&IDstd);
IDsearch = isIDexist(IDstd);
if(IDsearch == -1)
    printf("There is no entries to search in >> returned -1");
else if (IDsearch == 0)
    printf("Entered student ID is not found in Database >> returned 0");
else if(IDsearch == 1)
    printf("ID exist >> returned 1");
break;

case 'c':
counter = existEntries();
if(counter == 0)
    printf("Database is empty >> %d entry",counter);
else
    printf("Database entries = %d",counter);
break;
case 'x':
status=exit;
break;

default :
printf(" ERROR : InValid option \n");
}
}

}
