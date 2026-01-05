#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int calscore(string word);
void winner(int s1,int s2);
int main()
{
    int score1=0;
    int score2=0;
    //playes input
    string p1=get_string("Player 1: ");
    string p2=get_string("Player 2: ");

    //compute score
    score1=calscore(p1);
    score2=calscore(p2);

    //print winner
    winner(score1,score2);

}




int calscore(string word)
{
    int score=0;
    for(int i=0,length=strlen(word);i<length;i++)
    {
        if(word[i]>='A' && word[i]<='Z')
        {
            score+=POINTS[word[i]-'A'];
        }
        else if(word[i]>='a' && word[i]<='z')
        {
            score+=POINTS[word[i]-'a'];
        }
    }
    return score;
}

void winner(int s1,int s2)
{
    if(s1>s2)
    {
        printf("Player 1 wins\n");
    }
    else if(s2>s1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie\n");
    }
}






