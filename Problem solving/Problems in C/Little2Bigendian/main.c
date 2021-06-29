#include <stdio.h>
#include <stdlib.h>
void lit2big(long word){
unsigned char *ptr;
ptr = &word;
unsigned char temp;
int i;
for(i = 0;i<4;i++){
    temp = ptr[i];
    ptr[i] = ptr[3-i];
    ptr[3-i] = temp;

}
printf("%x%x%x%x",ptr[0],ptr[1],ptr[2],ptr[3]);
}
int changed_endian(int num){
int byte0,byte1,byte2,byte3;
byte0=(num&0x000000FF)>>0;byte1=(num&0x0000FF00)>>8;
byte2=(num&0x00FF0000)>>16;byte3=(num&0xFF000000)>>24;return((byte0<<24)|(byte1<<16)|
 (byte2 << 8) | (byte3 << 0));
 }

int main()
{
    printf("Enter little endianess to convert it to big endianess\n");
   // lit2big(0xCD12AB90);
   int res = changed_endian(0xabcdef12);
   printf("%x",res);
    return 0;
}
