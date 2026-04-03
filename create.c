#include "inverted.h"
#include <ctype.h>

void create_database(M_node *HT[], F_node *head)
{
    char word[25];
    while(head)
    {
        FILE *fp = fopen(head->f_name, "r");
        if(fp == NULL)
        {
            head = head->link;
            continue;
        }
       while(fscanf(fp, "%s", word) != EOF)
        {
            for(int i = 0; word[i]; i++)
            {
                word[i] = tolower(word[i]);
            }
            int index = get_index(word);

            M_node *temp = HT[index];
            M_node *prev = NULL;

            while(temp)
            {
                if(strcmp(temp->word, word) == 0)
                {
                    break;
                }
                prev = temp;
                temp = temp->main_link;
            }

            if(temp) 
            {
                S_node *sub = temp->sub_link;
              while(sub)
                {
                    if(strcmp(sub->filename, head->f_name) == 0)
                    {
                        sub->word_count++;
                        break;
                    }
                    sub = sub->sub_link;
                }
             if(sub == NULL)
                {
                    S_node *new_sub = malloc(sizeof(S_node));

                    strcpy(new_sub->filename, head->f_name);
                    new_sub->word_count = 1;
                    new_sub->sub_link = temp->sub_link;

                    temp->sub_link = new_sub;
                    temp->file_count++;
                }
            }
            else
            {
                M_node *new_main = malloc(sizeof(M_node));

                strcpy(new_main->word, word);
                new_main->file_count = 1;
                new_main->main_link = NULL;

                S_node *new_sub = malloc(sizeof(S_node));

                strcpy(new_sub->filename, head->f_name);
                new_sub->word_count = 1;
                new_sub->sub_link = NULL;

                new_main->sub_link = new_sub;

                if(HT[index] == NULL)
                {
                    HT[index] = new_main;
                }
                else
                {
                    prev->main_link = new_main;
                }
            }
        }
       fclose(fp);
        head = head->link;
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
    printf(YELLOW"\t                                 INFO : Database created successfully\n"RESET);
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
}
void load_data(char *f_name, M_node *HT[])
{
    char word[25];
    int ind;

    FILE *fp = fopen(f_name,"r");
    if(fp == NULL)
    {
        
    printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
    printf(RED"\t                                      ERROR: Unable to open %s\n"RESET, f_name);
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
        return;
    }
    while(fscanf(fp,"%s",word) != EOF)
    {
        ind = get_index(word);

        M_node *temp = HT[ind];
        M_node *prev = NULL;

        while(temp)
        {
            if(strcmp(temp->word,word) == 0)
            {
                S_node *s_temp = temp->sub_link;
               while(s_temp)
                {
                    if(strcmp(s_temp->filename,f_name) == 0)
                    {
                        s_temp->word_count++;
                        return;
                    }
                   if(s_temp->sub_link == NULL)
                   {
                        break;
                   }
                    s_temp = s_temp->sub_link;
                }
                S_node *s_new = malloc(sizeof(S_node));
                strcpy(s_new->filename,f_name);
                s_new->word_count = 1;
                s_new->sub_link = NULL;

                s_temp->sub_link = s_new;
                temp->file_count++;

                return;
            }
            prev = temp;
            temp = temp->main_link;
        }
        M_node *m_new = malloc(sizeof(M_node));
        strcpy(m_new->word,word);
        m_new->file_count = 1;
        m_new->main_link = NULL;

        S_node *s_new = malloc(sizeof(S_node));
        strcpy(s_new->filename,f_name);
        s_new->word_count = 1;
        s_new->sub_link = NULL;

        m_new->sub_link = s_new;

        if(prev == NULL)
        {
            HT[ind] = m_new;
        }
        else
        {
            prev->main_link = m_new;
        }
    }
    fclose(fp);
}
int get_index(char*word)
{
    //char ch=word[0];
    if(isalpha(word[0]))
       return toupper(word[0])-'A';
       else
       return 26;
}