#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTE 512

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }
    FILE *file = fopen(argv[1],"r");
    if(file==NULL)
    {
        printf("Unable to open the file\n");
        return 1;
    }

    uint8_t buffer[BYTE];
    FILE *img = NULL;
    int count = 0;
    char new_file[8];

    while(fread(buffer, 1, BYTE, file) == 512)
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
        {
            if(img != NULL)
            {
                fclose(img);
            }
            sprintf(new_file,"%03i.jpg", count);
            img = fopen(new_file,"w");
            count++;
            fwrite(buffer,1,BYTE,img);
        }
        else if(img != NULL)
        {
            fwrite(buffer, 1, BYTE, img);
        }
    }
    if(img != NULL)
    {
        fclose(img);
    }
    fclose(file);
}
