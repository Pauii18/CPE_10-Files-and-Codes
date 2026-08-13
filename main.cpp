#include <iostream>
#include "Playlist.h" // Links the header file definitions

// SongNode Constructor Implementation
SongNode::SongNode(std::string songTitle) {
    title = songTitle;
    next = nullptr;
    prev = nullptr;
}

// Playlist Constructor Implementation
Playlist::Playlist() {
    head = nullptr;
    current = nullptr;
}

// Add song to the end of the playlist
void Playlist::insertSong(std::string title) {
    SongNode* newNode = new SongNode(title);
    
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
        current = head;
        std::cout << "Added first song: " << title << "\n";
        return;
    }

    SongNode* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;

    std::cout << "Added: " << title << "\n";
}

// Remove a song matching the title
void Playlist::removeSong(std::string title) {
    if (head == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    SongNode* currNode = head;
    bool found = false;

    do {
        if (currNode->title == title) {
            found = true;
            break;
        }
        currNode = currNode->next;
    } while (currNode != head);

    if (!found) {
        std::cout << "Song " << title << " not found.\n";
        return;
    }

    if (currNode->next == currNode) {
        head = nullptr;
        current = nullptr;
    } else {
        if (currNode == head) head = head->next;
        if (currNode == current) current = current->next;
        
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
    std::cout << "Successfully removed: " << title << "\n";
}
                                                                                  
void Playlist::nextSong() {
    if (current == nullptr) return;
    current = current->next;
    std::cout << "Skipped Forward. Now Playing: " << current->title << "\n";
}

void Playlist::previousSong() {
    if (current == nullptr) return;
    current = current->prev;
    std::cout << "Skipped Backward. Now Playing: " << current->title << "\n";
}


void Playlist::playAllSongs() {
    if (head == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    std::cout << "\n--- Playing all tracks ---\n";
    SongNode* temp = head;
    do {
        std::cout << "Now Playing: " << temp->title << "\n";
        temp = temp->next;
    } while (temp != head);
    std::cout << "---------------------------\n";
}

// Destructor
Playlist::~Playlist() {
    if (head == nullptr) return;
    head->prev->next = nullptr; 
    SongNode* currNode = head;
    while (currNode != nullptr) {
        SongNode* nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

int main() {
    Playlist myPlaylist;

    myPlaylist.insertSong("Your Guardian Angel");
    myPlaylist.insertSong("Why");
    myPlaylist.insertSong("Her");
    myPlaylist.insertSong("A Dream is a Wish");
    myPlaylist.insertSong("prayer");

    myPlaylist.playAllSongs();
    myPlaylist.nextSong();
    myPlaylist.removeSong("Why");
    myPlaylist.playAllSongs();

    return 0;
}

