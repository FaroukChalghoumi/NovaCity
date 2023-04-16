test:main.o minimap.o perso.o background.o
	gcc main.o  minimap.o perso.o background.o -o test -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
perso.o:perso.c
	gcc -c perso.c -g
background.o:background.c
	gcc -c background.c -g
