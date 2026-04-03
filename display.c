#include "inverted.h"

void display_database(M_node *HT[])
{
    printf("===========================================================================\n");
    printf(GREEN"Index   Word            File Count      File Name       Word Count\n"RESET);
    printf("===========================================================================\n");

    for(int i = 0; i < 27; i++)
    {
        M_node *temp = HT[i];
       while(temp)
        {
            S_node *sub = temp->sub_link;
             while(sub)
            {
                printf("|%-7d| %-15s| %-10d |%-10s| %-12d|\n",
                        i,
                        temp->word,
                        temp->file_count,
                        sub->filename,
                        sub->word_count);

                sub = sub->sub_link;
            }
             temp = temp->main_link;
        }
    }
   printf("=========================================================================\n");
}