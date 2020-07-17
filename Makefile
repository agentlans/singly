
example: sl.c example.c
	cc sl.c example.c -o example

.PHONY: clean
clean:
	rm example

