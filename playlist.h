/**
* @file playlist.h   Declaration of a Playlist for music.
*
* @brief
*    Implementation of Playlist for music, where a doubly linked list is
*    used to store the song names.
*
* @author Judy Challinger
* @date 2/1/13
*/

#ifndef CSCI_311_PLAYLIST_H
#define CSCI_311_PLAYLIST_H

#include "doublylinkedlist.h"
using std::string;

class Playlist {
public:
	void mainLoop();                    // process commands until done
private:
	DoublyLinkedList dll;               // playlist stored in doubly linked list

	void processCommand();              // read and process one playlist command

//	void seperation(string&);


	//   void appendSong(string&)
	void appendSong(string&);

	void removeSong(string&);

	void gotoSong(string&);

	void insertBefore(string&);

	void insertAfter(string&);

	void gotoFirstSong();

	void gotoLastSong();

	void playCurrent();

	void playForward();

	void playReverse();

	void nextSong();

	void prevSong();

	void print();

};

#endif // CSCI_311_PLAYLIST_H
