CC = gcc
OPTIONS = -lglut -lGLU -lGL
CFLAGS = -Wall -W
CSUBFLAGS = -lm




game :  Aim.o ArrayList.o WorldGenerator.o Human.o Game.o Cube.o Car.o Conversion.o Vec.o Camera.o main.o 
	$(CC) $(FLAGS)  "$(PWD)/Aim.o" "$(PWD)/ArrayList.o" "$(PWD)/WorldGenerator.o" "$(PWD)/Human.o" "$(PWD)/Game.o" "$(PWD)/Cube.o" "$(PWD)/Car.o" "$(PWD)/Conversion.o" "$(PWD)/Vec.o" "$(PWD)/Camera.o" "$(PWD)/main.o" -o game $(OPTIONS) $(CSUBFLAGS)

main.o :  src/main.c include/Conversion.h include/Vec.h include/Aim.h include/Camera.h  include/ArrayList.h include/Car.h include/Game.h include/Camera.h include/WorldGenerator.h include/Human.h
	$(CC) $(OPTIONS) -c src/main.c

Camera.o : src/main.c include/Camera.h
	$(CC) $(OPTIONS) -c src/Camera.c $(CSUBFLAGS)

Vec.o : src/main.c include/Vec.h
	$(CC) $(OPTIONS) -c src/Vec.c $(CSUBFLAGS)

Conversion.o : src/main.c include/Conversion.h
	$(CC) $(OPTIONS) -c src/Conversion.c $(CSUBFLAGS)

Car.o : src/main.c include/Car.h
	$(CC) $(OPTIONS) -c src/Car.c $(CSUBFLAGS)

Cube.o : src/main.c include/Cube.h
	$(CC) $(OPTIONS) -c src/Cube.c $(CSUBFLAGS)

Game.o : src/main.c include/Game.h
	$(CC) $(OPTIONS) -c src/Game.c $(CSUBFLAGS)

Human.o : src/main.c include/Human.h
	$(CC) $(OPTIONS) -c src/Human.c $(CSUBFLAGS)

WorldGenerator.o : src/main.c include/WorldGenerator.h
	$(CC) $(OPTIONS) -c src/WorldGenerator.c $(CSUBFLAGS)

ArrayList.o : src/main.c include/ArrayList.h
	$(CC) $(OPTIONS) -c src/ArrayList.c $(CSUBFLAGS)

Aim.o : src/main.c include/Aim.h
	$(CC) $(OPTIONS) -c src/Aim.c $(CSUBFLAGS)


clean :
	rm -rf *.o *~ game