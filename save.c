#include "inverted.h"

void save_database(M_node *HT[])
{
    char fname[20];
    printf("Enter the file name to save database: ");
    scanf("%s", fname);

    FILE *fp = fopen(fname, "w");
    if(fp == NULL)
    {
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
        printf(RED"\t                                ERROR: Unable to create file %s\n"RESET, fname);
        printf("---------------------------------------------------------------------------------------------------------------------------\n");
        return;
    }
    for(int i = 0; i < 27; i++)
    {
        M_node *temp = HT[i];
       while(temp)
        {
            fprintf(fp, "#%d;%s;%d;", i, temp->word, temp->file_count);
            S_node *sub = temp->sub_link;
            while(sub)
            {
                fprintf(fp, "%s;%d;", sub->filename, sub->word_count);
                sub = sub->sub_link;
            }
              fprintf(fp, "#\n");
           temp = temp->main_link;
        }
    }
    fclose(fp);

    printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");
    printf(YELLOW"\t                           INFO : Database saved successfully\n"RESET);
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
}