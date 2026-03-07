#include "main.h"

int Is_HT_empty(hash_t *arr)
{
  hash_t *temp = arr;

  for (int i = 0; i < 27; i++)
  {
    if (temp[i].link != NULL)
    {
      return 1;
    }
  }
  return 0;
}

/* Function to display database */
void display_DB(hash_t *arr)
{
  if (Is_HT_empty(arr) == 0)
  {
    printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] Database is Empty!\n");
    return;
  }
  

  printf("\n█▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
  printf("█\033[1;7;93m\033[1;92m   \033[1;93m %s \033[1;92m  \033[0m\033[1;97m%s\033[1;7;93m\033[1;92m                              \033[1;93m %s \033[1;92m                              \033[0m\033[1;97m%s\033[1;7;93m\033[1;92m   \033[1;93m %s \033[1;92m   \033[0m\033[1;97m%s\033[1;7;93m\033[1;92m       \033[1;93m %s \033[1;92m      \033[0m\033[1;97m%s\033[1;7;93m\033[1;92m   \033[1;93m %s \033[1;92m   \033[0m\033[1;97m%s\n", "Index", "█", "Word", "█", "File Count", "█", "File(s)", "█", "Word Count", "█");
  printf("█▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");
  printf("█            █                                                                  █                  █                      █                  █\n");
  /* Traverse hash table */
  for (int i = 0; i < 27; i++)
  {
    if (arr[i].link != NULL)
    {
      main_t *m_temp = arr[i].link;

      /* Traverse main node */
      while (m_temp != NULL)
      {
        printf("█      %-5d %-7s %-60s %-10s %-9zu ", i, "█", m_temp->word, "█", m_temp->f_count);

        sub_t *s_temp = m_temp->slink;

        int first = 1;

        /* Traverse sub node */
        while (s_temp != NULL)
        {
          if (!first)
          {
            /* Print spaces to align under File(s) */
            printf("\n█      %-5s %-7s %-60s %-10s %-9s ", "", "█", "", "█", "");
          }
          printf("%-6s %-17s %-10s %-9zu █", "█", s_temp->f_name, "█", s_temp->w_count);

          first = 0;
          s_temp = s_temp->link;
        }

        printf("\n");

        m_temp = m_temp->nlink;
      }
    }
  }

  printf("█▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");
}