#include <cs50.h>
#include <stdio.h>
int get_change(void);
int printcoins(int n);
int main()
{

    int c = get_change();
    int p = printcoins(c);
    printf("Coins: %d\n", p);
}

int get_change(void)
{
    int n;
    do
    {
        n = get_int("Enter Change: ");
    }
    while (n < 0);
    return n;
}
int printcoins(int n)
{

    int coins = 0;
    if (n == 0)
    {
        return coins;
    }
    else
    {

        coins += n / 25;
        n %= 25;

        coins += n / 10;
        n %= 10;

        coins += n / 5;
        n %= 5;

        coins += n / 1;
        n %= 1;
        return coins;
    }
}
