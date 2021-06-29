#include <stdio.h>
#include <stdlib.h>

struct human{
char gender;
int age;
};
int main(){

    struct human *me,Me;
    me = &Me;
    me->age = 24;
    me->gender = 'm';
    printf("%d  %c ",(*me).age,(*me).gender);

    return 0;
}
