#include <iostream>
#include <stdexcept>
#include "Playlist.h"
using namespace std;

//PLAYLIST NODE MEMBER FUNCTIONS

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string ID, string sName, string aName, int sLength){ 
    uniqueID = ID;
    songName = sName;
    artistName = aName;
    songLength = sLength;
    nextNodePtr = nullptr;
}

string PlaylistNode::GetID(){
    return uniqueID;
}

string PlaylistNode::GetSongName(){
    return songName;
}

string PlaylistNode::GetArtistName(){
    return artistName;
}

int PlaylistNode::GetSongLength(){
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext(){
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

void PlaylistNode::InsertAfter(PlaylistNode* currSong){
    PlaylistNode* tempNode = this->nextNodePtr;
    this->nextNodePtr = currSong;
    currSong->nextNodePtr = tempNode;
}

void PlaylistNode::SetNext(PlaylistNode* nextSong){
    this->nextNodePtr = nextSong;
}

//PLAYLIST MEMBER FUNCTIONS

void Playlist::printMenu(string playlistName){
    cout << playlistName << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:";
}

void Playlist::outputFullPlaylist(string playlistTitle){
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
    if(head == nullptr){
        cout << "Playlist is empty" << endl << endl;
    }
    else{
        int songNum = 1;
        for(PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
            cout << songNum << "." << endl;
            currNode->PrintPlaylistNode();
            cout << endl;
            ++songNum;
        }
    }
}

void Playlist::addSong(PlaylistNode* addNode){
    if(head == nullptr){
        head = addNode;
        tail = addNode;
    }
    else if(head == tail && head != nullptr){
        head->SetNext(addNode);
        tail = addNode;
    }
    else{
        tail->SetNext(addNode);
        tail = addNode;
    }
}

void Playlist::removeSong(string rID){
    string songName;
    PlaylistNode* prevNode = head;
    for(PlaylistNode* currNode = head->GetNext(); currNode != nullptr; currNode = currNode->GetNext()){
        if(prevNode == head && prevNode->GetID() == rID){
            songName = prevNode->GetSongName();
            PlaylistNode* tempNode = prevNode->GetNext();
            delete prevNode;
            head = tempNode;
        }
        else{
            if(currNode->GetID() == rID){
                if(currNode == tail){
                    songName = currNode->GetSongName();
                    tail = prevNode;
                    delete currNode;
                }
                else{
                    songName = currNode->GetSongName();
                    prevNode->SetNext(currNode->GetNext());
                    delete currNode;
                }
            }
        }
        prevNode = prevNode->GetNext();
    }
    //FIX THIS
    cout << "\"" << songName << "\"" << " removed." << endl << endl;
}

void Playlist::changePosition(int currPos, int newPos){

    PlaylistNode* selecSong;
    PlaylistNode* prevSong;
    string selectedSong;
    int currSong = 2;

    PlaylistNode* prevNode = head;
    for(PlaylistNode* currNode = head->GetNext(); currNode != nullptr; currNode = currNode->GetNext()){
        if(currPos == 1 && prevNode == head){
            selecSong = prevNode;
            prevSong = prevNode;
            selectedSong = prevNode->GetSongName();
        }
        else{ 
            if(currSong == currPos){
                selecSong = currNode;
                selectedSong = currNode->GetSongName();
                prevSong = prevNode;
            }
        }
        ++currSong;
        prevNode = prevNode->GetNext();
    }

    int newPosCount = 1;
    for(PlaylistNode* newCurrNode = head; newCurrNode != nullptr; newCurrNode = newCurrNode->GetNext()){
        if(newPos <= 1 && newPosCount == 1){
            prevSong->SetNext(selecSong->GetNext());
            selecSong->SetNext(newCurrNode);
            head = selecSong;
        }
        else if(newPos >= currSong){
            prevSong->SetNext(selecSong->GetNext());
            selecSong->SetNext(nullptr);
            tail->SetNext(selecSong);
            tail = selecSong;
        }
        else{
            if(newPos > currPos){
                if(newPosCount == newPos){
                    if(currPos == 1){
                        head = selecSong->GetNext();
                        newCurrNode->InsertAfter(selecSong);
                    }
                    else{
                        prevSong->SetNext(selecSong->GetNext());
                        newCurrNode->InsertAfter(selecSong);
                    }
                }
            }
            else{
                if(newPosCount == newPos-1){
                    if(tail == selecSong){
                        prevSong->SetNext(selecSong->GetNext());
                        tail = prevSong;
                        newCurrNode->InsertAfter(selecSong);
                    }
                    else{
                        prevSong->SetNext(selecSong->GetNext());
                        newCurrNode->InsertAfter(selecSong);
                    }
                }
            }
        }
        ++newPosCount;
    }

    cout << "\"" << selectedSong << "\"" << " moved to position " << newPos << endl;
}

void Playlist::songsByArtist(string outputArtist){
    int nodeNum = 1;
    for(PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
        if(currNode->GetArtistName() == outputArtist){
            cout << nodeNum << "." << endl;
            currNode->PrintPlaylistNode();
            cout << endl;
        }
        ++nodeNum;
    }
}

void Playlist::totalTimePlaylist(){
    int totalTime = 0;
    for(PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
        totalTime += currNode->GetSongLength();
    }
    cout << "Total time: " << totalTime << " seconds" << endl << endl;
}

/*
PlaylistNode* tempNode;
    string selectedSong;
    int currSong = 2;

    PlaylistNode* prevNode = head;
    for(PlaylistNode* currNode = head->GetNext(); currNode != nullptr; currNode = currNode->GetNext()){
        if(prevNode == head && currPos == 1){
            tempNode = prevNode;
            selectedSong = prevNode->GetSongName();
            head = currNode;
        }
        else{
            if(currSong == currPos){
                if(tail == currNode){
                    tail = prevNode;
                    tempNode = currNode;
                    selectedSong = currNode->GetSongName();
                }
                else{
                    tempNode = currNode;
                    prevNode->SetNext(currNode->GetNext());
                    selectedSong = currNode->GetSongName();
                }
            }
        }
        ++currSong;
        prevNode = prevNode->GetNext();
    }

    //FIND THE NEW POSITION
    PlaylistNode* newPrevNode = head;
    int newCurrSong = 2;
    for(PlaylistNode* newCurrNode = head->GetNext(); newCurrNode != nullptr; newCurrNode = newCurrNode->GetNext()){
        if(newPrevNode == head && newPos <= 1){
            tempNode->SetNext(newPrevNode);
            head = tempNode;
        }
        else{
            if(newCurrSong == newPos-1){
                if(tail == newCurrNode || newPos >= currSong){
                    newCurrNode->SetNext(tempNode);
                    tempNode->SetNext(nullptr);
                    tail = tempNode;
                }
                else{
                    tempNode->SetNext(newCurrNode);
                    prevNode->SetNext(tempNode);
                }
            }
        }
        ++newCurrSong;
        newPrevNode = newPrevNode->GetNext();
    }
*/