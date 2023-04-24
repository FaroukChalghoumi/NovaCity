test:main.o minimap.o perso.o
	gcc main.o  minimap.o perso.o -o maps -lSDL -lSDL_ttf -lSDL_image -g
main.o:main.c
	gcc -c main.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
perso.o:perso.c
	gcc -c perso.c -g
