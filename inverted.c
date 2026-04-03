#include "inverted.h"

int validate_files(char *f_name, F_node **head)
{
    FILE *fp = fopen(f_name, "r");
    if(fp == NULL)
    {
        printf("\n---------------------------------------------------------------------------------------------------------------------\n");
        printf(RED"\t                                  ERROR: %s file not found\n" RESET, f_name);
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        return FAILURE;
    }
   fseek(fp, 0, SEEK_END);
    if(ftell(fp) == 0)
    {
        printf("\n----------------------------------------------------------------------------------------------------------------------\n");
        printf(RED"\t                                  ERROR: %s file is empty\nRESET", f_name);
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        fclose(fp);
        return FAILURE;
    }
    fclose(fp);

    if(check_duplicates(*head, f_name) == SUCCESS)
    {
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
        printf(YELLOW"\t                               INFO: Duplicate file %s\n"RESET, f_name);
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        return FAILURE;
    }
    insert_last(head, f_name);
     print_filenames(*head);

    return SUCCESS;
}
int check_duplicates(F_node *head, char *f_name)// Function definitions 
{
    while(head)
    {
        if(strcmp(head->f_name, f_name) == 0)
        {
            return SUCCESS;
        }
        head = head->link;
    }
    return FAILURE;
}
int insert_last(F_node **head, char *f_name)// Insert filename at the end of list 
{
    F_node *new = malloc(sizeof(F_node));
    if(new == NULL)
    {
    return FAILURE;
    }
    strcpy(new->f_name, f_name);
    new->link = NULL;

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    F_node *temp = *head;
    while(temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;

    return SUCCESS;
}
int print_filenames(F_node *head)// Print filenames 
{
    if(head == NULL)
    {
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf(YELLOW"\t                                  INFO : No files available\n"RESET);
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        return FAILURE;
    }
   
    printf(BLUE"Files accepted are:\n"RESET);
    
    while(head)
    {
        printf("%s\n", head->f_name);
        head = head->link;
    }

    return SUCCESS;
}