#include <stdio.h>
#include <stdlib.h>

int main(void)
{

int n, h;
scanf("%d",&n);
scanf("%d",&h);

int heights[n];

for(int i = 0; i < n; i++)
{
    scanf("%d",&heights[i]);
}
     int i; int width = 0;

        for(i = 0; i < n; i++)
        {
            if(heights[i] <= h)
            {
                width += 1;
            }
            else
            {
                width += 2;
            }
        }

       printf("%d\n", width);

}






