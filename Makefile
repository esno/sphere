all: composite window sphere

composite:
	${CC} -c ./src/composite.c -I./src/include -lX11 -lXcomposite

window:
	${CC} -c ./src/window.c -I./src/include -lX11

sphere: composite window
	${CC} -c ./src/sphere.c -I./src/include -lX11
	${CC} -o sphere composite.o window.o sphere.o -lX11 -lXcomposite

clean:
	rm -rf ./sphere ./*.o
