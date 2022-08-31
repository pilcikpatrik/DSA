#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char *key;
    int frequency;
    struct node *next;
};

struct hashtable {
    struct node **table;
    int currentsize;
    int tablesize;
};

typedef struct hashtable hashtable;

struct node * add(hashtable *, char *, int);
void mostfrequent(hashtable *, int);

int main()
{
    FILE *in = fopen("book.txt", "r");
    hashtable *hash = createtable(50000);
    struct node *node = NULL;
    char word[100];
    int length = 0;

    /* Load data from txt file to the hash table */
    while(1) {
        if(fscanf(in, "%s", word) != 1)
            break;
    length = strlen(word) - 1;
        if(ispunct(word[length]))
        *(word + length) = '\0';
    if(strlen(word) > 0)
            node = add(hash, word, 1);
        node->frequency++;
    }
    fclose(in);
    /* Print words with frequency higher than 250 */
    mostfrequent(hash, 250);
    return 0;
}

struct node * add(hashtable *h, char *key, int freq) {
    struct node *newnode;
    int index = hashcode(key) % h->tablesize;
    struct node *current = h->table[index];

    /* Search for duplicate value */
    while(current != NULL) {
        if(strcmp(key, current->key) == 0)
            return current;
        current = current->next;
    }
    /* Create new node if no duplicate is found */
    newnode = nalloc(key, freq);
    newnode->next = h->table[index];
    h->table[index] = newnode;
    h->currentsize = h->currentsize + 1;
    return newnode;
}

void mostfrequent(hashtable *h, int freq) {
    struct node *current = NULL;
    int i;
    printf("\n  Word       Frequency\n");
    printf("  --------------------\n");
    for(i = 0; i < h->tablesize; i++) {
        current = h->table[i];
        while(current != NULL) {
            if(current->frequency > freq)
                printf("  %-14s %d\n", current->key, current->frequency);
            current = current->next;
        }
    }
}
