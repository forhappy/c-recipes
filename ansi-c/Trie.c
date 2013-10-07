/*
 * ========================================================================
 *
 *       Filename:  Trie.c
 *
 *    Description:  simple trie implementation.
 *
 *        Created:  10/07/2013 08:33:35 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */
#include<stdio.h>
#include<malloc.h>

typedef struct trie_s
{
    int words;
    int prefixes;
    struct trie_s *edges[26];
}trie_t;

trie_t * trie_initialize(trie_t *node)
{
    int i = 0;
    if (node == NULL)
        node = (trie_t *)malloc(sizeof(trie_t));
    node->words = 0;
    node->prefixes = 0;

    for(i = 0; i < 26; i++)
        node->edges[i] = NULL;
    return node;
}

trie_t * trie_add_word(trie_t *ver, char *str)
{
    char k;
    if(str[0] == '\0') {
        ver->words = ver->words + 1;
    } else {
        ver->prefixes = (ver->prefixes) + 1;
        k = str[0];
        str++;
        int index = k - 'a';
        if(ver->edges[index] == NULL) {
            ver->edges[index] = trie_initialize(ver->edges[index]);
        }
        ver->edges[index] = trie_add_word(ver->edges[index], str);
    }
    return ver;
}

int trie_count_words(trie_t *ver, char *str)
{
    if(str[0] == '\0') {
        return ver->words;
    } else {
        int k = str[0] - 'a';
        str++;
        if(ver->edges[k] == NULL) return 0;
        return trie_count_words(ver->edges[k], str);
    }
}

int trie_count_prefix(trie_t *ver, char *str)
{
    if(str[0]=='\0') {
        return ver->prefixes;
    } else {
        int k = str[0] - 'a';
        str++;
        if (ver->edges[k] == NULL) return 0;
        return trie_count_prefix(ver->edges[k], str);
    }
}

int main()
{
    trie_t *start = NULL;
    start = trie_initialize(start);
    int ch=1;
    while (ch) {
        printf("\n 1. Insert a word ");
        printf("\n 2. Count words");
        printf("\n 3. Count prefixes");
        printf("\n 0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        char input[1000];
        switch (ch) {
        case 1:
            printf("\nEnter a word to insert: ");
            scanf("%s", input);
            start = trie_add_word(start, input);
            break;
        case 2:
            printf("\nEnter a word to count words: ");
            scanf("%s", input);
            printf("\n%d", trie_count_words(start, input));
            break;
        case 3:
            printf("\nEnter a word to count prefixes: ");
            scanf("%s", input);
            printf("\n%d", trie_count_prefix(start, input));
            break;
        }
    }
    return 0;
}
