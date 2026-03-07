#include "main.h"

int main(int argc, char *argv[])
{
  hash_t arr[27];
  reset_HT(arr);

  file_t *file_name = NULL;
  vaildate_Files(&file_name, argc, argv);

  char option;

  int create_flag = 0, update_flag = 0;

  do
  {
    system("clear");
    int choice;
    // printf("\033[1;97mInverted Search MENU\n1] Create database\n2] Search database\n3] Display database\n4] Save database\n5] Update database\n6] Exit\n\n\033[1;97m[\033[1;92mCHOICE\033[1;97m] Enter your choice : ");

    printf("\033[1;97m\n▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌\n");
    printf("▐ \033[1;7;93m%-8c\033[1;92m %s \033[0m\033[1;7;93m%-9c\033[0m\033[1;97m ▌\n", ' ', "WELCOME TO INVERTED SEARCH", ' ');
    printf("\033[1;97m▐▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▌\n");
    printf("▐ \033[1;7;92m%-17c\033[1;92m %s \033[0m\033[1;7;92m%-17c\033[0m\033[1;97m ▌\n", ' ', "MAIN MENU", ' ');
    printf("\033[1;97m▐▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▌\n");
    printf("▐ \033[1;93m\033[1;7m 1. \033[1;92m %-5s\033[0m\033[1;97m\t\t\t \033[1;3m\033[0m▌\n", "\U0001F6E0\U0000FE0F  CREATE DATABASE ");
    printf("\033[1;97m▐▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▌\n");
    printf("▐ \033[1;93m\033[1;7m 2. \033[1;92m %-4s\033[0m\033[1;97m\t\t\t\033[1;3m\033[0m▌\n", "\U0001F50D SEARCH DATABASE ");
    printf("\033[1;97m▐▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▌\n");
    printf("▐ \033[1;93m\033[1;7m 3. \033[1;92m %-4s\033[0m\033[1;97m\t\t\t\033[1;3m\033[0m▌\n", "\U0001F4CA DISPLAY DATABASE ");
    printf("\033[1;97m▐▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▌\n");
    printf("▐ \033[1;93m\033[1;7m 4. \033[1;92m %-4s\033[0m\033[1;97m\t\t\t\t\033[1;3m\033[0m▌\n", "\U0001F4BE SAVE DATABSE ");
    printf("\033[1;97m▐▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▌\n");
    printf("▐ \033[1;93m\033[1;7m 5. \033[1;92m %-4s\033[0m\033[1;97m\t\t\t\033[1;3m\033[0m▌\n", "\U0001F504 UPDATE DATABASE ");
    printf("\033[1;97m▐▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▌\n");
    printf("▐ \033[1;93m\033[1;7m 6. \033[1;92m %-4s\033[0m\033[1;97m\t\t\t\t\t\033[1;3m\033[0m▌\n", "\U0001F6AA EXIT ");
    printf("\033[1;97m▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌\n\n\033[1;97m[\033[1;92mCHOICE\033[1;97m] Enter your choice : ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      if (create_flag == 1)
      {
        printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] Database already created. Cannot create again.\n");
      }
      else if (update_flag == 1)
      {
        printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] Database already created. Cannot create after update.\n");
      }
      else
      {
        if (create_DB(arr, file_name) == SUCCESS)
        {
          create_flag = 1;
        }
      }
      break;
    case 2:
      search_DB(arr);
      break;
    case 3:
      display_DB(arr);
      break;
    case 4:
      save_DB(arr);
      break;
    case 5:
      if (update_flag == 1)
      {
        printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] Database already updated. Cannot update again.\n");
      }
      else
      {
        if (update_DB(arr, &file_name) == SUCCESS)
        {
          update_flag = 1;
          create_flag = 1;
        }
      }
      break;
    case 6:
      free_file_list(file_name);
      return 0;
    default:
      printf("\033[1;91mInalid choice!\033[1;97m\n");
    }

    getchar();

    printf("\n\033[1;97m[\033[1;92mOPTION\033[1;97m] Do you want to continue (Y / N) : ");
    scanf("%c", &option);
  } while (((option == 'y' || option == 'Y') && (option != 'n' || option != 'N')));
}