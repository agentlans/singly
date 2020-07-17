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

#include "sl.h"

#include <stdlib.h>

struct sl_node* sl_node_init(void* data)
{
	struct sl_node* ptr = malloc(sizeof(struct sl_node));
	if (ptr == NULL) return ptr;
	ptr->data = data;
	return ptr;
}

void sl_node_free(struct sl_node* s)
{
	free(s);
}

struct sl* sl_init()
{
	struct sl* ptr = malloc(sizeof(struct sl));
	if (ptr == NULL) return ptr;
	ptr->head = NULL;
	ptr->tail = NULL;
}

int sl_empty(struct sl* s)
{
	return s->head == NULL;
}

/* Returns the pointer stored in the head or tail. */
void* sl_get_head(struct sl* s)
{
	if (sl_empty(s)) return NULL;
	return s->head->data;
}

void* sl_get_tail(struct sl* s)
{
	if (sl_empty(s)) return NULL;
	return s->tail->data;
}

/* Returns pointer to the head or tail node of linked list. */
struct sl_node* sl_head(struct sl* s)
{
	return s->head;
}

struct sl_node* sl_tail(struct sl* s)
{
	return s->tail;
}

struct sl_node* sl_next(struct sl_node* sln)
{
	if (sln == NULL) return NULL;
	return sln->next;
}

void* sl_get(struct sl_node* sln)
{
	if (sln == NULL) return NULL;
	return sln->data;
}

/* Inserts or erases data at the front of the linked list. */
int sl_insert_front(struct sl* s, void* data)
{
	struct sl_node* ptr = sl_node_init(data);
	if (ptr == NULL) return 1;
	ptr->next = s->head;
	if (sl_empty(s)) s->tail = ptr;
	s->head = ptr;
	return 0;
}

int sl_erase_front(struct sl* s)
{
	if (sl_empty(s)) return 1;
	struct sl_node* v = s->head;
	s->head = v->next;
	if (sl_empty(s)) s->tail = NULL;
	sl_node_free(v);
	return 0;
}

/* Frees memory occupied by linked list and its nodes */
void sl_free(struct sl* s)
{
	while (!sl_empty(s)) sl_erase_front(s);
	free(s);
}

int sl_insert_after(struct sl* s, struct sl_node* v, void* data)
{
	struct sl_node* new_node = sl_node_init(data);
	if (new_node == NULL) return 1;

	struct sl_node* old_next = v->next;
	v->next = new_node;
	new_node->next = old_next;

	if (new_node->next == NULL) {
		s->tail = new_node;
	}
	return 0;
}

int sl_erase_after(struct sl* s, struct sl_node* v)
{
	if (v->next == NULL) return 1;
	/* node order is v, w, old_next */
	struct sl_node *w = v->next;
	struct sl_node *old_next = w->next;
	v->next = old_next;

	if (w->next == NULL) {
		s->tail = v;
	}
	sl_node_free(w);
	return 0;
}

/* Inserts element at end of linked list */
int sl_insert_back(struct sl* s, void* data)
{
	if (sl_empty(s)) {
		return sl_insert_front(s, data);
	} else {
		return sl_insert_after(s, s->tail, data);
	}
}

