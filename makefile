friendfind: friendfind.o Map-Reduce.o TextInputOutput.o
	gcc friendfind.o Map-Reduce.o TextInputOutput.c -o friendfind
	
friendfind.o: friendfind.c ListaAmigos.h Map-Reduce.h TextInputOutput.h
	gcc -c  friendfind.c
	
Map-Reduce.o: Map-Reduce.c ListaAmigos.h TextInputOutput.h 
	gcc -c Map-Reduce.c
	
TextInputOutput.o: TextInputOutput.c ListaAmigos.h
	gcc -c TextInputOutput.c