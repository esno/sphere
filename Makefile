all: composite sphere

composite:
	${CC} -c ./src/composite.c -I./src/include -lX11 -lXcomposite

sphere: composite
	${CC} -c ./src/sphere.c -I./src/include -lX11
	${CC} -o sphere composite.o sphere.o -lX11 -lXcomposite

clean:
	rm -rf ./sphere ./*.o
