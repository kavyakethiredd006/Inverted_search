#include "inverted.h"

void search_database(M_node *HT[])
{
    char word[25];
    printf("Enter the word to search: ");
    scanf("%s", word);
    for(int i = 0; word[i]; i++)
    {
        word[i]=tolower(word[i]);
    }
    int index=get_index(word);
     M_node *temp = HT[index];
     while(temp)
    {
        if(strcmp(temp->word, word) == 0)
        {
            printf("Word '%s' is present in %d file(s)\n", temp->word, temp->file_count);

            S_node *sub = temp->sub_link;
            while(sub)
            {
                printf("File: %s  ->  Word Count: %d\n", sub->filename, sub->word_count);
                sub = sub->sub_link;
            }
               return;
        }
        temp = temp->main_link;
    }
     printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
    printf(YELLOW"\t                                  INFO : Word '%s' not found in database\n"RESET, word);
     printf("--------------------------------------------------------------------------------------------------------------------------------\n");
}