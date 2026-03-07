#include "main.h"

/* function to remove file which is already updated/present in Hash table*/
void remove_file_from_SLL(file_t **head, const char *filename)
{
  /* Take a temporary pointer temp to traverse the list and also a pointer prev to store previous node address */
  file_t *temp = *head;
  file_t *prev = NULL;

  /* Traverse the list */
  while (temp != NULL)
  {
    if (strcmp(temp->f_name, filename) == 0)
    {
      if (prev == NULL)
      {
        *head = temp->link;
      }
      else
      {
        prev->link = temp->link;
      }

      /* Delete the file present in list which already present in hash table */
      free(temp->f_name);
      free(temp);

      return;
    }

    /* Update previous node address and move to next node */
    prev = temp;
    temp = temp->link;
  }
}

/* Function to update database from backup file */
int update_DB(hash_t *arr, file_t **files)
{
  char filename[100];

  /* Read backup file name from user */
  printf("\nEnter backup file name : ");
  scanf("%s", filename);

  /* Check whether the user entered file is .txt file or not */
  if (!is_txt_file(filename))
  {
    printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] %s is not a .txt file\n", filename);
    return FAILURE;
  }

  /* Open file */
  FILE *fptr = fopen(filename, "r");

  /* Check whether the file open or not */
  if (!fptr)
  {
    perror("\n\033[1;97m[\033[1;91mERROR\033[1;97m] ");
    return FAILURE;
  }

  printf("\n");

  /* Reset Hash table */
  reset_HT(arr);

  /* Validate whether the user entered file is a back-up file or not */

  /* Read first character from file to check whether it is # or not */
  char ch;
  fscanf(fptr, "%c", &ch);
  if (ch != '#')
  {
    printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] This file is not a back_up file!\n");
    return FAILURE;
  }
  rewind(fptr);

  while (1)
  {
    /* Variables to store index, word, file count read from backup file */
    int index;
    char word[100];
    size_t f_count;

    /* Read index, word, file count from backup file */
    if (fscanf(fptr, " #%d;%[^;];%zu;", &index, word, &f_count) != 3)
    {
      break;
    }

    /* Create new main node */
    main_t *new_main = malloc(sizeof(main_t));
    new_main->word = malloc(strlen(word) + 1);

    /* Copy word, file count and initialize main node link */
    strcpy(new_main->word, word);
    new_main->f_count = f_count;
    new_main->slink = NULL;
    new_main->nlink = NULL;

    /* Create a pointer last_sub to store last sub node address for new main node */
    sub_t *last_sub = NULL;

    /* Traverse the file count and read filename, word count from backup file */
    for (int i = 0; i < f_count; i++)
    {
      char f_name[100];
      size_t w_count;

      /* Read filename, word count from backup file */
      fscanf(fptr, "%[^;];%zu;", f_name, &w_count);

      /* Remove the existing file if present */
      remove_file_from_SLL(files, f_name);

      /* Create new sub node */
      sub_t *new_sub = malloc(sizeof(sub_t));
      new_sub->f_name = malloc(strlen(f_name) + 1);

      /* Copy filename, word count and initialize sub node link */
      strcpy(new_sub->f_name, f_name);
      new_sub->w_count = w_count;
      new_sub->link = NULL;

      /* Update sub node link with new sub node link */
      if (new_main->slink == NULL)
      {
        new_main->slink = new_sub;
      }
      else
      {
        last_sub->link = new_sub;
      }

      /* Update last sub node address with new sub node address */
      last_sub = new_sub;
    }

    /* Read # from backup file to differentiate each word data */
    fscanf(fptr, "#");

    /* Update hash table index with new main node link */
    if (arr[index].link == NULL)
    {
      arr[index].link = new_main;
    }
    else
    {
      main_t *temp = arr[index].link;
      while (temp->nlink != NULL)
      {
        temp = temp->nlink;
      }
      temp->nlink = new_main;
    }
  }

  /* Close file */
  fclose(fptr);

  printf("\n\033[1;97m[\033[1;92mUPDATE\033[1;97m] Database restored successfully!\n");
  return SUCCESS;
}
