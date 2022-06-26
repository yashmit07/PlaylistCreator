#include <iostream>
using namespace std;
#include "Playlist.h"


int main(){
    Playlist playlist;
    string playlistTitle;
    int currPos;
    int newPos;
    string rSong;
    string outANAME;
    bool validInput = false;
    cout << "Enter playlist's title:" << endl << endl;
    getline(cin, playlistTitle);

    //you have to call all the functions on a playlist object

    while(validInput == false){
        char userInput;
        playlist.printMenu(playlistTitle);
        cin >> userInput;
        cout << endl;

        if(userInput == 'a'){
            string id;
            string sName;
            string aName;
            int sLength;

            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, id);
            cout << "Enter song's name:" << endl;
            getline(cin, sName);
            cout << "Enter artist's name:" << endl;
            getline(cin, aName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> sLength;
            cout << endl;
            PlaylistNode* newNode = new PlaylistNode(id, sName, aName, sLength);
            playlist.addSong(newNode);
        }
        else if(userInput == 'd'){
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, rSong);
            playlist.removeSong(rSong);
        }
        else if(userInput == 'c'){
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> currPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            playlist.changePosition(currPos, newPos);
            cout<< endl;
        }
        else if(userInput == 's'){
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();
            getline(cin, outANAME);
            cout << endl; 
            playlist.songsByArtist(outANAME);
        }
        else if(userInput == 't'){
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            playlist.totalTimePlaylist();
        }
        else if(userInput == 'o'){
            playlist.outputFullPlaylist(playlistTitle);
        }
        else if(userInput == 'q'){
            validInput = true;
        }
    }
}