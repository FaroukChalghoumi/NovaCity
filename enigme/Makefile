enigme:main.o ENG.o enigme.o input.o
	gcc main.o ENG.o enigme.o input.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o enigme -g; ./enigme
main.o:main.c
	gcc -c main.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
input.o:input.c
	gcc -c input.c -g

ENG.o:ENG.c
	gcc -c ENG.c -g


