#include "inverted.h"

int main(int argc, char *argv[])
{
    F_node *head = NULL;
    M_node *HT[27];

	for(int i=0;i<27;i++)
	{
       HT[i]=NULL;
	}

    if(argc < 2)// Validate_files
    {
		printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
		printf(RED"\t                                   Error: NO files passed\n"RESET);
		printf("----------------------------------------------------------------------------------------------------------------------------\n");
		return 0;
	}
    for(int i=1;i<argc;i++)
	{
	validate_files(argv[i], &head);
	}
    int option;
    do
    {
	printf(CYAN"Select your choice among following operations:"RESET"\n1. Create Database\n2. Display Database\n3. Save Database\n4. Search\n5. Update Database\n6. Exit\n");
	printf(GREEN"Enter your choice : "RESET);
     scanf("%d", &option);

	switch (option)
	{
	    case 1:
		create_database(HT, head);
		break;

	    case 2:
		display_database(HT);
		break;

	    case 3:
		save_database(HT);
		    break;

	    case 4:
		search_database(HT);
		break;

	    case 5:
		update_database(HT, &head);
		break;

	    case 6:
		break;

	    default:
		printf("\n----------------------------------------------------------------------------------------------------------------------------\n");
		printf(YELLOW"\t                                INFO : Please enter the valid option\n"RESET);
		printf("------------------------------------------------------------------------------------------------------------------------------\n");
	}
    }while( option != 6 );

    return 0;
}
