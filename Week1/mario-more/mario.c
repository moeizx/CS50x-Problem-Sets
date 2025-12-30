#include<stdio.h>
#include<cs50.h>

void space(int n);
void brick(int n);

int main()
{
    //prompt user for input
    int height;
    do{
        height=get_int("Height: ");
    }while(height<1 || height>8);

    //print pyramids
    for(int i=0;i<height;i++)
    {
        //spaces
        space(height-i-1);

        //bricks
        brick(i+1);
        printf("  ");
        brick(i+1);
        printf("\n");

    }
}

void space(int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" ");
    }
}
void brick(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("#");
    }
}
