#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg =
                ((image[i][j].rgbtBlue) + (image[i][j].rgbtGreen) + (image[i][j].rgbtRed)) / 3.0;
            int r = 0.5 + avg;
            image[i][j].rgbtBlue = r;
            image[i][j].rgbtGreen = r;
            image[i][j].rgbtRed = r;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = (0.5) + (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +.189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaGreen = (0.5) + (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                      .168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            int sepiaBlue = (0.5) + (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                     .131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j]=image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cpy[height][width];

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            cpy[i][j]=image[i][j];
        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int sumRed=0;
            int sumBlue=0;
            int sumGreen=0;
            int count=0;

            for(int xi=-1;xi<=1;xi++)
            {

                for(int xj=-1;xj<=1;xj++)
                {
                    int yi=xi+i;
                    int yj=xj+j;

                    if(yi >= 0 && yi < height && yj>=0 && yj<width)
                    {
                        sumRed += cpy[yi][yj].rgbtRed;
                        sumBlue += cpy[yi][yj].rgbtBlue;
                        sumGreen += cpy[yi][yj].rgbtGreen;

                        count++;
                    }
                }

            }
            image[i][j].rgbtRed = (0.5) + ((sumRed)/(float)count);
            image[i][j].rgbtBlue = (0.5) + ((sumBlue)/(float)count);
            image[i][j].rgbtGreen = (0.5) + ((sumGreen)/(float)count);
        }
    }
    return;
}
