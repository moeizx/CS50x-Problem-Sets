#include <cs50.h>
#include <stdio.h>

int main()
{
    // Take input from the user
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    // Calculate length of the number
    int length = 0;
    long temp_number = number;
    do
    {
        temp_number /= 10;
        length++;
    }
    while (temp_number > 0);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        int sum1 = 0, sum2 = 0, z1, z2, n1, n2;
        temp_number = number;

        do
        {
            // last values
            z1 = temp_number % 10;
            sum1 += z1;
            temp_number /= 10;

            // second to last values
            z2 = temp_number % 10;
            z2 *= 2;
            n1 = z2 / 10;
            n2 = z2 % 10;
            sum2 += n1 + n2;
            temp_number /= 10;
        }
        while (temp_number > 0);

        int total_sum = sum1 + sum2;

        if (total_sum % 10 != 0)
        {
            printf("INVALID\n");
            return 0;
        }
        else
        {
            // Find the first 2 digits
            long start = number;
            do
            {
                start /= 10;
            }
            while (start >= 100);

            // Check the card
            if ((start == 34 || start == 37) && (length == 15))
            {
                printf("AMEX\n");
                return 0;
            }
            else if (start > 50 && start < 56 && length == 16)
            {
                printf("MASTERCARD\n");
                return 0;
            }
            else if ((start / 10 == 4) && (length == 13 || length == 16))
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }
}
