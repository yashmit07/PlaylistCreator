# Playlist Creator

A C++ application that implements a music playlist manager using a linked list data structure. This program allows users to create and manage their music playlists with various features for organizing and manipulating song entries.

## Features

- Add new songs to the playlist
- Remove songs from the playlist
- Change position of songs within the playlist
- View the complete playlist
- Search songs by artist
- Calculate total playlist duration
- Print individual song information

## Project Structure

- `Playlist.h` - Header file containing the class definitions for `PlaylistNode` and `Playlist`
- `Playlist.cpp` - Implementation of the playlist functionality
- `main.cpp` - Main program file containing the user interface

## Classes

### PlaylistNode
Represents a single song in the playlist with properties:
- Unique ID
- Song Name
- Artist Name
- Song Length
- Pointer to next song

### Playlist
Manages the entire playlist with features:
- Add/remove songs
- Change song positions
- Display playlist
- Search functionality
- Time calculation

## Building the Project

To compile the project, use a C++ compiler (g++ recommended):

```bash
g++ main.cpp Playlist.cpp -o playlist_creator
```

## Usage

Run the compiled program:

```bash
./playlist_creator
```

Follow the on-screen menu to:
1. Add songs to your playlist
2. Remove songs using their unique ID
3. Change the position of songs
4. Search for songs by a specific artist
5. View the total duration of your playlist
6. Display the entire playlist

## Data Structure

The project uses a linked list implementation where:
- Each node represents a song
- Nodes are connected through pointers
- The playlist maintains head and tail pointers for efficient operations

## Contributing

Feel free to fork this project and submit pull requests for any improvements or bug fixes. 