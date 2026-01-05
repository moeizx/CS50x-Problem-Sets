#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool only_digits(string s);
void calculate(string s, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    // bool check = only_digits(argv[1]);
    bool c= only_digits(argv[1]);

    if (c==false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    // Turn plaintext to Ciphertext
    calculate(plaintext, key);
    printf("\n");
}

bool only_digits(string s)
{
    bool choice=true;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (!isdigit(s[i]))
        {
            choice = false;
            break;
        }

    }
    return choice;
}
void calculate(string s, int key)
{
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        char c = s[i];
        if (isalpha(c))
        {
            if (isupper(s[i]))
            {
                c = (c - 'A' + key) % 26 + 'A';
                printf("%c", c);
            }
            else
            {
                c = (c - 'a' + key) % 26 + 'a';
                printf("%c", c);
            }
        }
        else
        {
            printf("%c", c);
        }
    }
}
