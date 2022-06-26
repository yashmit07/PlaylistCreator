#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <ostream>

using namespace std;

class PlaylistNode {
    public:
        PlaylistNode();
	    PlaylistNode(string ID, string sName, string aName, int sLength);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
        void InsertAfter(PlaylistNode* currSong);
        void SetNext(PlaylistNode* nextSong);
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};

class Playlist {    
    public:
        void printMenu(string playlistName);
        void outputFullPlaylist(string playlistTitle);
        void addSong(PlaylistNode* addNode);
        void removeSong(string rID);
        void changePosition(int currPos, int newPos);
        void songsByArtist(string outputArtist);
        void totalTimePlaylist();
    private:
        PlaylistNode *head = nullptr;
        PlaylistNode *tail = nullptr;
};

#endif

