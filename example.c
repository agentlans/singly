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

#include <stdio.h>
#include <assert.h>

#include "sl.h"

int main()
{
	/* Initializes singly-linked list */
	struct sl* s = sl_init();
	assert(s != NULL);

	/* Create void* pointers to some numbers
	and insert them into the linked list. */
	printf("Inserting some numbers into linked list.\n");
	int x = 3, y = 10, z = 100;
	sl_insert_back(s, (void*) &x);
	sl_insert_back(s, (void*) &y);
	sl_insert_back(s, (void*) &z);
	sl_insert_front(s, (void*) &z);

	/* Go to the start of linked list and print
	the contents in order until there's no more (NULL).
	Because the list is singly-linked, you can't go back to previous nodes. */
	printf("Now printing contents of linked list:\n");
	struct sl_node* it = sl_head(s);
	while (it != NULL) {
		/* Convert void* pointer to int* */
		printf("%d\n", *(int*) sl_get(it));
		it = sl_next(it);
	}

	/* Remember to free the memory occupied by singly-linked list. */
	sl_free(s);
	/* Note: this doesn't free the void* pointers inside s.
	If those void* pointers are dynamically-allocated then you
	have to free them yourself. */

	return 0;
}

