prog:main.o menu.o serie.o
	gcc main.o menu.o serie.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm -o prog -g

main.o:main.c
	gcc -c main.c -g

menu.o:menu.c
	gcc -c menu.c -g
	
serie.o:serie.c
	gcc -c serie.c -g
