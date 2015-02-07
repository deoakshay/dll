/**
* @file playlist.cpp   Implementation of a Playlist for music.
*
* @brief
*    Implementation of a Playlist for music. A doubly linked list is
*    used to store the song names.
*
* @author Judy Challinger
* @date 2/1/13
*/

#include <iostream>
#include <string>
#include<string.h>
//#include<sstream>
#include "playlist.h"
#ifndef CSCI_311_PLAYLIST_CPP
#define CSCI_311_PLAYLIST_CPP
#include "doublylinkedlist.h"
#endif
using std::string;
using std::cin;
using std::cout;
using std::endl;

/**
* Process a playlist command.
*
* Gets an entire line from std::cin, extracts the first word as the command,
* and calls the appropriate processing function. Invalid commands are
* ignored.
*/
void Playlist::processCommand()
{
	string c;
	while (cin >> c)
	{
		if (!(strcmp(c.c_str(), "appendSong")))
		{
			getline(cin, c);
			appendSong(c);
		}
		if (!(strcmp(c.c_str(), "insertBefore")))
		{
			getline(cin, c);
			insertBefore(c);
		}
		if (!(strcmp(c.c_str(), "insertAfter")))
		{
			getline(cin, c);
			insertAfter(c);
		}
		if (!(strcmp(c.c_str(), "gotoSong")))
		{
			getline(cin, c);
			gotoSong(c);
		}
		if (!(strcmp(c.c_str(), "removeSong")))
		{
			getline(cin, c);
			removeSong(c);
		}
		if (!(strcmp(c.c_str(), "gotoFirstSong")))
		{
		
			gotoFirstSong();
		}
		if (!(strcmp(c.c_str(), "gotoLastSong")))
		{

			gotoLastSong();
		}
		if (!(strcmp(c.c_str(), "playForward")))
		{

			playForward();
		}
		if (!(strcmp(c.c_str(), "playReverse")))
		{

			playReverse();
		}
		if (!(strcmp(c.c_str(), "playCurrent")))
		{

			playCurrent();
		}
		if (!(strcmp(c.c_str(), "nextSong")))
		{

			nextSong();
		}
		if (!(strcmp(c.c_str(), "prevSong")))
		{

			prevSong();
		}
		if (!(strcmp(c.c_str(), "print")))
		{

			print();
		}
	}
	
}

/**
* The Playlist main loop will process command lines until eof.
*/
void Playlist::mainLoop()
{
	while (!cin.eof()) processCommand();         // process all commands
}

/**
* The main entry point for the program.
*/
int main()
{
	Playlist myPlaylist;
	myPlaylist.mainLoop();
	return 0;
}


void Playlist::print()
{
	dll.show();
}

void Playlist::appendSong(string&as)
{
	dll.append(as);
}

void Playlist::removeSong(string&s)
{
    dll.remove(s);
}
void Playlist::gotoSong(string&s)
{
	dll.find(s);
}

void Playlist::insertBefore(string&s)

{
	dll.insertBefore(s);
}

void Playlist::insertAfter(string&s)
{
	dll.insertAfter(s);
}

void Playlist::gotoFirstSong()
{
	dll.begin();
}

void Playlist::gotoLastSong()
{
	dll.end();
}

void Playlist::playCurrent()
{
	cout << "\n playing current:";
	if (dll.empty())
	{
		return;
	}
	else
	{
		string s =dll.getData();
		cout << s << endl;
	}
}

void Playlist::playForward()
{
	if (dll.empty())
	{
		return;
	}
	else
	{
		string s;
		cout << "\n playing Forward" << endl;
		s = dll.getData();
	    cout <<"\n"<<s<<endl;
		     while (dll.next())
			{
				s = dll.getData();
				cout << s << endl;
			}
	
	}
}

void Playlist::playReverse()
{
	if (dll.empty())
	{
		return;
	}
	else
	{
		string s;
		cout << "\n playing reverse:" << endl;
		s = dll.getData();
		cout << s << endl;
			while (dll.prev())
			{
				s = dll.getData();
				cout << s << endl;
			}
		
	}
}

void Playlist::nextSong()
{
	dll.next();
}

void Playlist::prevSong()
{
	dll.prev();
}
