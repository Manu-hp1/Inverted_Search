#include "main.h"

/* Function to search word in the database */
void search_DB(hash_t *arr)
{
  char g_word[50];

  printf("\nEnter the data you want to search : ");
  scanf("%s", g_word); // Doesn't support multiple words

  int index;

  /* Calculate index for the given word */
  if (g_word[0] >= 'a' && g_word[0] <= 'z')
  {
    index = g_word[0] - 'a';
  }
  else if (g_word[0] >= 'A' && g_word[0] <= 'Z')
  {
    index = g_word[0] - 'A';
  }
  else
  {
    index = 26;
  }

  /* Check whether the index is empty or not */
  if (arr[index].link == NULL)
  {
    printf("\n\033[1;97m[\033[1;91mERROR\033[1;97m] Word not found in database\n");
    return;
  }

  // printf("\n-------------------------------------------------------------\n");
  printf("\n▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n");
  printf("%-10s %-30s %-14s %-10s %-10s\n", "Index", "Word", "File Count", "File(s)", "Word Count");
  // printf("-------------------------------------------------------------\n");
  printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n");

  /* Take a temporary pointer m_temp to traverse main node */
  main_t *m_temp = arr[index].link;

  /* Traverse main node */
  while (m_temp)
  {
    if (strcmp(m_temp->word, g_word) == 0)
    {
      printf("  %-8d %-34s %-10zu ", index, m_temp->word, m_temp->f_count);

      /* Take a temporary pointer s_temp to traverse sub node */
      sub_t *s_temp = m_temp->slink;

      /* Variable to check whether the first file is printed or not */
      int first = 1;

      /* Traverse sub node */
      while (s_temp != NULL)
      {
        if (!first)
        {
          /* Print spaces to align under File(s) */
          printf("\n  %-8s %-34s %-10s ", "", "", "");
        }

        printf("%-14s %zu", s_temp->f_name, s_temp->w_count);

        first = 0;
        s_temp = s_temp->link;
      }
      printf("\n▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n");

      return;
    }
    m_temp = m_temp->nlink;
  }

  /* If word not found in database */
  printf("\033[1;97m[\033[1;91mERROR\033[1;97m] Word not found in database\n");
  printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n");
}