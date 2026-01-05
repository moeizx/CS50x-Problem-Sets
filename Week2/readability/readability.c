#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<math.h>
#include<string.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float avg_l(int l_length, int w_length);
float avg_s(int s_length, int w_length);
int colman(float avg_l, float avg_s);

int main()
{
    // Input text from the user
    string text = get_string("Enter: ");

    // Count number o letters words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float avg_letter = avg_l(letters, words);
    float avg_sentence = avg_s(sentences, words);
    int grade = colman(avg_letter, avg_sentence);

    // Print result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int length = 0;
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        if (isalpha(text[i]))
        {
            length++;
        }
    }
    return length;
}

int count_words(string text)
{
    int length = 1;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (isspace(text[i]))
        {
            length++;
        }
    }
    return length;
}

int count_sentences(string text)
{
    int length = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            length++;
        }
    }
    return length;
}

float avg_l(int l_length, int w_length)
{
    float avg_letter = ((float) l_length / (float) w_length) * 100;
    return avg_letter;
}
float avg_s(int s_length, int w_length)
{
    float avg_sentence = ((float) s_length / (float) w_length) * 100;
    return avg_sentence;
}
int colman(float avg_l, float avg_s)
{
    float x = (0.0588 * avg_l) - (0.2968 * avg_s) - 15.8;
    int y = round(x);
    return y;
}
