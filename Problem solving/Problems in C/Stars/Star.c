
#include <stdio.h>
#include <stdlib.h>

void stars_shape() {
int i; int ind1 = 4; int ind2 = 1;
int k; int m; int j;
for(j = 0;j<5;j++){

for(i = 0;i<ind1;i++){
    printf(" ");
}
for(k = 0;k<ind2;k++){
    printf("*");
}
for(m =0;m<ind1;m++){
    printf(" ");
}
printf("\n");
ind1--;ind2 +=2;
}

}
