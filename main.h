#ifndef INVERT_SEARCH
#define INVERT_SEARCH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* MACRO FOR RETURN VALUES */
#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -3

/* STRUCTURE TO VALIDATE THE FILE */
typedef struct file_node
{
  char *f_name;
  struct file_node *link;
} file_t;

/* STRUCTURE FOR SUB NODE */
typedef struct sub_node
{
  char *f_name;
  size_t w_count;
  struct sub_node *link;
} sub_t;

/* STRUCTURE FOR MAIN NODE */
typedef struct main_node
{
  char *word;
  size_t f_count;
  struct sub_node *slink;
  struct main_node *nlink;
} main_t;

/* STRUCTURE FOR HASH TABLE */
typedef struct hash_table
{
  size_t index;
  struct main_node *link;
} hash_t;

/* Function used to reset the hash table */
void reset_HT(hash_t *);


void vaildate_Files(file_t **, int argc, char *argv[]);
int is_file_empty(FILE *fptr);
int is_txt_file(const char *filename);
int is_dupicate_file(file_t *head, const char *filename);
void free_file_list(file_t *head);

int create_DB(hash_t *arr, file_t *file_head);
void display_DB(hash_t *arr);
void search_DB(hash_t *arr);
void save_DB(hash_t *arr);
int update_DB(hash_t *arr, file_t **files);

#endif