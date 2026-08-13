#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

// 1. Structure Design
struct SongNode {
    std::string title;
    SongNode* next;
    SongNode* prev;

    SongNode(std::string songTitle);
};

// 2. Class Interface Declaration
class Playlist {
private:
    SongNode* head;
    SongNode* current;

public:
    Playlist();
    ~Playlist();

    void insertSong(std::string title);
    void removeSong(std::string title);
    void nextSong();
    void previousSong();
    void playAllSongs();
};

#endif // PLAYLIST_H

