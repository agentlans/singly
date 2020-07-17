/*

Copyright 2020 Alan Tseng

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef _SINGLYLINKEDLIST
#define _SINGLYLINKEDLIST

/* Node of singly-linked list */
struct sl_node {
	void* data;
	struct sl_node* next;
};

/* Initializes and frees memory for a node in singly-linked list. */
struct sl_node* sl_node_init(void* data);
void sl_node_free(struct sl_node* s);

/* Singly-linked list */
struct sl {
	struct sl_node* head;
	struct sl_node* tail;
};

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

#endif

