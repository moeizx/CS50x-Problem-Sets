// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int bucket = hash(word);
    node *cursor = table[bucket];

    while (cursor)
    {
        int i = 0;
        bool match = true;
        while (word[i] != '\0' && cursor->word[i] != '\0')
        {
            if (tolower(word[i]) != tolower(cursor->word[i]))
            {
                match = false;
                break;
            }
            i++;
        }

        // Also ensure both strings ended
        if (match && word[i] == '\0' && cursor->word[i] == '\0')
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash += tolower(word[i]);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source = fopen(dictionary, "r");
    if (!source)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(source, "%45s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (!new_node)
        {
            fclose(source);
            return false;
        }

        strcpy(new_node->word, word);

        unsigned int bucket = hash(word);
        new_node->next = table[bucket];
        table[bucket] = new_node;
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            count++;
            cursor = cursor->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
