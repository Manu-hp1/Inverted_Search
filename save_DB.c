#include "main.h"

void save_DB(hash_t *arr)
{
  char file_store[100];

  printf("\nEnter the file to save data : ");
  scanf("%s", file_store);

  /* Check whether the user entered file is .txt file or not */
  if (!is_txt_file(file_store))
  {
    printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] %s is not a .txt file\n", file_store);
    return;
  }

  /* Open user entered file */
  FILE *fptr = fopen(file_store, "w");

  /* Check whether the file exits in current directory or not */
  if (fptr == NULL)
  {
    perror("File open failed");
    return;
  }

  /* Traverse hash table */
  for (int i = 0; i < 27; i++)
  {
    if (arr[i].link != NULL)
    {
      /* Save index*/
      // fprintf(fptr, "#%d", i);

      /* Take a temporary pointer m_temp to traverse main node */
      main_t *m_temp = arr[i].link;

      /* Traverse main node */
      while (m_temp != NULL)
      {
        /* Save index, word, file count to file */
        fprintf(fptr, "#%d;%s;%zu;", i, m_temp->word, m_temp->f_count);

        /* Take a temporary pointer s_temp to traverse sub node */
        sub_t *s_temp = m_temp->slink;

        /* Traverse sub node */
        while (s_temp != NULL)
        {
          
          /* Save file name, word count to the file */
          fprintf(fptr, "%s;%zu;", s_temp->f_name, s_temp->w_count);
          s_temp = s_temp->link;
        }

        /* Insert # at last of each word data to diferrentiate words */
        fprintf(fptr, "#\n");
        
        m_temp = m_temp->nlink;
      }
    }
  }

  /* Close file */
  fclose(fptr);
  printf("\n\033[1;97m[\033[1;92mSAVE\033[1;97m] Database is saved!\n");
}