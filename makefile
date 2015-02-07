CXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS = 

playlist: playlist.o doublylinkedlist.o
	$(CXX) $(LDFLAGS) playlist.o doublylinkedlist.o -o playlist

playlist.o: playlist.cpp playlist.h doublylinkedlist.h
	$(CXX) $(CXXFLAGS) playlist.cpp

doublylinkedlist.o: doublylinkedlist.cpp doublylinkedlist.h
	$(CXX) $(CXXFLAGS) doublylinkedlist.cpp

clean:
	rm *o playlist
