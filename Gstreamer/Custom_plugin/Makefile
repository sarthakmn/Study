CC = gcc
CFLAGS = -Wall -g `pkg-config --cflags gstreamer-1.0`
LIBS = `pkg-config --libs gstreamer-1.0`

plugin: plugin.o
	$(CC) -shared -o libloudnessfilter.so plugin.o $(LIBS)

plugin.o: plugin.c
	$(CC) -fPIC -c plugin.c $(CFLAGS)

clean:
	rm -f *.o libloudnessfilter.so

