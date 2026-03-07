#include "main.h"

/* Function to reset hash table*/
void reset_HT(hash_t *arr)
{
  for (int i = 0; i <= 26; i++)
  {
    arr[i].index = i;
    arr[i].link = NULL;
  }
  printf("\033[1;97m[\033[1;92mWORK\033[1;97m] RESET HASH TABLE DONE\n");
}

/* Function to check the filename as .txt extension or not */
int is_txt_file(const char *filename)
{
  char *ext = strrchr(filename, '.'); // Find last dot

  if (ext != NULL && strcmp(ext, ".txt") == 0)
  {
    return 1; // Valid .txt file
  }
  return 0; // Not valid .txt file
}

/* Function to check whether file already exists in hash table or not */
int is_dupicate_file(file_t *head, const char *filename)
{
  while (head != NULL)
  {
    if (strcmp(head->f_name, filename) == 0)
    {
      return 1;
    }
    head = head->link;
  }
  return 0;
}

/* Function to check whether the file is empty or not */
int is_file_empty(FILE *fptr)
{
  fseek(fptr, 0, SEEK_END); // Move to last or end (EOF)
  long size = ftell(fptr);  // Get file size
  rewind(fptr);             // Reset ointer to begining

  if (size <= 0)
    return 1;
  else
    return 0;
}

/* Function to validate filename entered by user through CLA */
void vaildate_Files(file_t **file_name, int argc, char *argv[])
{
  /* Check whether user sent any file */
  // if (argc < 2)
  // {
  //   printf("\033[1;97m[\033[1;91mERROR\033[1;97m] No files are passed\n");
  //   exit(0);
  // }

  for (int i = 1; i < argc; i++)
  {
    /* Check whether the file contains .txt extension or not */
    if (!is_txt_file(argv[i]))
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] %s is not a .txt file\n", argv[i]);
      continue;
    }

    if(is_dupicate_file(*file_name, argv[i]))
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] %s is a duplicate file\n", argv[i]);
      continue;
    }

    /* Check whether file is exit in current directory or not */
    FILE *fptr = fopen(argv[i], "r");
    if (fptr == NULL)
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] File \"%s\" opening failed!\n", argv[i]);
      continue;
    }

    /* Check whether the file is empty or not */
    if (is_file_empty(fptr))
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] %s is an empty file\n", argv[i]);
      fclose(fptr);
      continue;
    }
    fclose(fptr);

    /* Create new node */
    file_t *new = malloc(sizeof(file_t));
    if (!new)
    {
      perror("\033[1;97m[\033[1;91mERROR\033[1;97m] New node creation failed!");
      return;
    }
    new->f_name = malloc(strlen(argv[i]) + 1);

    strcpy(new->f_name, argv[i]);
    new->link = NULL;

    /* Insert new node to list */
    if (*file_name == NULL)
    {
      *file_name = new;
    }
    else
    {
      file_t *temp = *file_name;
      while (temp->link)
      {
        temp = temp->link;
      }
      temp->link = new;
    }
  }

  printf("\033[1;97m[\033[1;92mWORK\033[1;97m] Validation Compleleted!\n");
  
}

/* Free the file list created dynamically */
void free_file_list(file_t *head)
{
  file_t *temp;

  /* Traverse the File List */
  while (head != NULL)
  {
    temp = head;
    head = head->link;

    free(temp->f_name);
    free(temp);
  }
  printf("FILE FREED!\n");
}