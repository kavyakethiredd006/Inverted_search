#include "inverted.h"
 int update_database(M_node *HT[], F_node **head)
{
    char fname[20];

    printf("Enter the database file name: ");
    scanf("%s", fname);

    if(validate_files(fname, head) == FAILURE)
    {
        return FAILURE;
    }

    load_data(fname, HT);
    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
    printf(YELLOW"\t                           INFO : Database updated successfully\n"RESET);
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    return SUCCESS;
}

//we got one filename
//do same validate
// 1.file_exist
//2.file _empty
//check duplicate in file name
