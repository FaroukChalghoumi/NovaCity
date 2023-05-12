test:main.o enigme.o input.o tic.o ENG.o minimap.o perso.o background.o entite.o
	gcc main.o enigme.o input.o ENG.o tic.o minimap.o perso.o background.o entite.o -o test -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
perso.o:perso.c
	gcc -c perso.c -g
background.o:background.c
	gcc -c background.c -g
entite.o:entite.c
	gcc -c entite.c -g
tic.o:tic.c
	gcc -c tic.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
input.o:input.c
	gcc -c input.c -g

ENG.o:ENG.c
	gcc -c ENG.c -g

