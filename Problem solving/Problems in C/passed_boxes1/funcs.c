#include <stdio.h>
#include <stdlib.h>
#include "header.h"
void passed(int boxes,int *hight1,int *width1,int *length1){
int vol[boxes]; int count = 0; int i;
for(i = 0;i<boxes;i++){
    vol[i] = hight1[i]*width1[i]*length1[i];
    if(vol[i]<40 && hight1[i] <41)
    count++;
}
printf("%d",count);

}
