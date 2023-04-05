.PHONY: main
main: drifblim

drifblim: drifblim.c
	gcc -o drifblim drifblim.c
