#include "main.h"

/* Function to create database using hash table ad filename */
int create_DB(hash_t *arr, file_t *file_head)
{
  /* Check whether the filename stored or not */
  if (file_head == NULL)
  {
    printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] File list empty\n");
    return FAILURE;
  }

  file_t *f_temp = file_head;

  /* Traverse the file list */
  while (f_temp != NULL)
  {
    /* Open file */
    FILE *fptr = fopen(f_temp->f_name, "r");

    /* Check whether the file exits in current directory or not */
    if (!fptr)
    {
      printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] Unable to open %s\n", f_temp->f_name);
      f_temp = f_temp->link;
      continue;
    }

    char word[100];

    /* Read each word from file */
    while (fscanf(fptr, "%99s", word) != EOF)
    {
      /* Skip empty words */
      if (strlen(word) == 0)
      {
        continue;
      }

      int index;

      /* Calculate hash index based on first character of word */
      if (word[0] >= 'a' && word[0] <= 'z')
      {
        index = word[0] - 'a';
      }
      else if (word[0] >= 'A' && word[0] <= 'Z')
      {
        index = word[0] - 'A';
      }
      else
      {
        index = 26;
      }

      /* Take a temporary pointer m_temp to traverse main node */
      main_t *m_temp = arr[index].link;

      /* Take a temporary pointer prev_main to store previous main node address */
      main_t *prev_main = NULL;

      /* Traverse main node */
      while (m_temp != NULL)
      {
        /* If word exiting in main node */
        if (strcmp(m_temp->word, word) == 0)
          break;

        /* Update previous main node address and move to next main node */
        prev_main = m_temp;
        m_temp = m_temp->nlink;
      }

      /* If word not exiting in main node */
      if (m_temp == NULL)
      {
        /* Create new main node */
        main_t *new_main = malloc(sizeof(main_t));

        /* Allocate memory and copy word to new main node */
        new_main->word = malloc(strlen(word) + 1);
        strcpy(new_main->word, word);

        /* Initialize file count, main node link and also create sub node for new main node */
        new_main->f_count = 1;
        new_main->nlink = NULL;

        /* Create sub node */
        sub_t *new_sub = malloc(sizeof(sub_t));

        /* Allocate memory and copy filename to new sub node */
        new_sub->f_name = malloc(strlen(f_temp->f_name) + 1);
        strcpy(new_sub->f_name, f_temp->f_name);

        /* Initialize word count and sub node link */
        new_sub->w_count = 1;
        new_sub->link = NULL;

        /* Update main node link with new sub node link */
        new_main->slink = new_sub;

        /* Update hash table index with new main node link */
        if (prev_main == NULL)
          arr[index].link = new_main;
        else
          prev_main->nlink = new_main;
      }
      else
      {
        /* Create a temporary pointer s_temp to traverse sub node and also a pointer prev_sub to store previous sub node address */
        sub_t *s_temp = m_temp->slink;
        sub_t *prev_sub = NULL;

        /* Traverse sub node */
        while (s_temp != NULL)
        {
          /* If filename exits in subnode or not */
          if (strcmp(s_temp->f_name, f_temp->f_name) == 0)
            break;

          /* Update previous sub node address and move to next sub node */
          prev_sub = s_temp;
          s_temp = s_temp->link;
        }

        if (s_temp == NULL)
        {
          /* Create new sub node */
          sub_t *new_sub = malloc(sizeof(sub_t));

          /* Allocate memory and copy filename to new sub node */
          new_sub->f_name = malloc(strlen(f_temp->f_name) + 1);
          strcpy(new_sub->f_name, f_temp->f_name);

          /* Initialize word count and sub node link */
          new_sub->w_count = 1;
          new_sub->link = NULL;

          /* Update last sub node link with new sub node link and also increment file count */
          prev_sub->link = new_sub;
          m_temp->f_count++;
        }
        else
        {
          /* Increment word count, if file exiting */
          s_temp->w_count++;
        }
      }
    }

    /* Close file */
    fclose(fptr);
    f_temp = f_temp->link;
  }

  printf("\n\033[1;97m[\033[1;92mWORK\033[1;97m]Database created successfully\n");

  return SUCCESS;
}