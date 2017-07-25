bin/WorldMapSimple.o: src/Thing.cpp src/WorldMap.h src/WorldMapSimple.cpp
	g++ -c -o bin/WorldMapSimple.o src/WorldMapSimple.cpp
	
bin/SpatialVector.o: src/SpatialVector.cpp
	g++ -c -o bin/SpatialVector.o src/SpatialVector.cpp
	
all: bin/WorldMapSimple.o bin/SpatialVector.o

clear:
	rm bin/*.o