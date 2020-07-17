# Singly
Singly linked list data structure

This is for personal and experimental use.
You should consider using more tested and mature libraries instead.

## Install
1. Include the header file `sl.h` and the source code file `sl.c` in your own project
2. Compile your code with a C compiler

To compile the example demo, run `make` on the command line.

## Use

This implementation stores data as void* pointers inside a singly linked list
which can be used as a stack or a queue.

Overview for storing and retrieving data:
1. Initialize the linked list with `sl_init`
2. Pass data in the form of void* pointers to `sl_insert_back`
3. Iterate through the list.
  - Get a pointer to the first node using `sl_head`
  - Step through the nodes of the list by calling `sl_next`
  - Get the stored data using `sl_get`. It will return a void* pointer to the data.
4. Clean up after using the linked list with `sl_free`.
  - note: `sl_free` only frees memory occupied by the singly list and its nodes, not the pointers stored inside!

Please see `example.c` for more details on how to use this library.

Functions in this library:
```c
/* Initializes and frees memory for a singly-linked list. */
struct sl* sl_init();
void sl_free(struct sl* s);

/* Returns the data stored in the head or tail. If list is empty, returns NULL. */
void* sl_get_head(struct sl* s);
void* sl_get_tail(struct sl* s);

/* Returns 0 if linked list isn't empty, or 1 if it is. */
int sl_empty(struct sl* s);

/* Inserts or erases data at the front or back of the linked list. */
int sl_insert_front(struct sl* s, void* data);
int sl_erase_front(struct sl* s);
int sl_insert_back(struct sl* s, void* data);

/* Returns pointer to the head or tail node of linked list. */
struct sl_node* sl_head(struct sl* s);
struct sl_node* sl_tail(struct sl* s);
struct sl_node* sl_next(struct sl_node* sln);

/* Returns the data stored inside given node of linked list. */
void* sl_get(struct sl_node* sln);

/* Stores or erases the node after a given node of linked list. 
Returns 0 if successful or 1 if there's an error. */
int sl_insert_after(struct sl* s, struct sl_node* v, void* data);
int sl_erase_after(struct sl* s, struct sl_node* v);
```

## Author, License

Copyright 2020 Alan Tseng

MIT License
