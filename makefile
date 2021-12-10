all: worker ui

worker: worker.o
	gcc -o worker worker.o

worker.o: worker.c
	gcc -c worker.c

ui: ui.o
	gcc -o ui ui.c

ui.o: ui.c
	gcc -c ui.c

clean:
	rm *.o worker ui
