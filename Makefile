.PHONY: main
main: drifblim snorlax cursola

.PHONY: clean
clean:
	rm -f drifblim snorlax cursola

drifblim: drifblim.c
	gcc -o drifblim drifblim.c

snorlax: snorlax.c
	gcc -o snorlax snorlax.c

cursola: cursola.c
	gcc -o cursola cursola.c
