#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
bool validkey(string s);
int main(int argc, string argv[])
{
    if(argc !=2)
    {
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }
    string key=argv[1];
    if(!validkey(key))
    {
        printf("Key must contain 26 unique characters.\n");
        return 1;
    }

    string plaintext=get_string("plaintext: ");
    printf("ciphertext: ");

    int length = strlen(plaintext);
    for(int i=0;i<length;i++)
    {
        char c=plaintext[i];
        if(isalpha(c))
        {
            if(isupper(c))
            {
                int pos = c - 'A';
                char cipher=toupper(key[pos]);
                printf("%c",cipher);
            }
            else
            {
                int pos = c - 'a';
                char cipher=tolower(key[pos]);
                printf("%c",cipher);
            }
        }
        else
        {
            printf("%c",c);
        }
    }
    printf("\n");

}

bool validkey(string s)
{
    if(strlen(s)!=26)
    {
        return false;
    }
    bool seen[26]={false};
    for(int i=0;i<26;i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
       int index=toupper(s[i]) - 'A';
       if(seen[index])
       {
        return false;
       }
       seen[index]=true;
    }
    return true;
}
