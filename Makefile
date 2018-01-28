all: sphere

sphere:
	${CC} ./src/sphere.c -lX11 -lXcomposite -o sphere

clean:
	rm -rf ./sphere
