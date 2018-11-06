#include "UtPod.h"
#include "Song.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

  UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = 0;
    srand(time(NULL));
  }

  UtPod::UtPod(int size) {
    if (size > MAX_MEMORY || size <= 0) {
      memSize = MAX_MEMORY;
    }
    else {
      memSize = size;
    }
    songs = 0;
    srand(time(NULL));
  }

  int UtPod::addSong(Song const &s) {
    int remMem = getRemainingMemory();
    int songSize = s.getSize();
    if ((remMem-songSize) >= 0) { //add song if enough memory
      SongNode *temp = new SongNode;
      temp->s = s;
      temp->next = songs;
      songs = temp;
      return SUCCESS;
  }

    else {
      return NO_MEMORY;
    }
  }

  int UtPod::removeSong(Song const &s) {
    SongNode *ptr = songs;
    SongNode *trail = songs;
    int n = numSongs();

    if (n == 0) { //no songs to remove if 0 songs in UtPod
      return NOT_FOUND;
    }

    else if (n == 1){ //when removing only song in UtPod, reset head ptr
      if (ptr->s == s) {
        songs = NULL;
        delete ptr;
        return SUCCESS;
      }
        return NOT_FOUND;
    }

    else {
      if ((ptr->s == s) && (ptr == songs)) { //check if first node and reset head ptr
        songs = ptr->next;
        return SUCCESS;
      }
      ptr = ptr->next;
      while (ptr != NULL) { //check all other nodes
        if (ptr->s == s) {
          trail->next = ptr->next;
          delete ptr;
          return SUCCESS;
        }
          ptr = ptr->next;
          trail = trail->next;
      }

      return NOT_FOUND;
    }
  }

  void UtPod::shuffle() {
    SongNode *ptr1;
    SongNode *ptr2;
    int song1;
    int song2;
    Song temp;

    int n = numSongs();

    if (n >= 2) { //shuffle if 2 or more songs in UtPod
      for (int i=0; i<n; i++) {
        ptr1 = songs;
        ptr2 = songs;
        song1 = (rand() % n);
        song2 = (rand() % n);
        for (int j=0; j<song1; j++) {
          ptr1 = ptr1->next; //ptr to first song location
        }
        for (int k=0; k<song2; k++) {
          ptr2 = ptr2->next; //ptr to second song location
        }
        if (song1 != song2) { //if songs are not same, then swap
        temp = ptr1->s;
        ptr1->s = ptr2->s;
        ptr2->s = temp;
        }
      }
    }
  }

  void UtPod::showSongList() {
    SongNode *ptr = songs;
    while (ptr != NULL) {
      cout << "ARTIST:" << ptr->s.getArtist() << "\tTITLE:" << ptr->s.getTitle()
           << "\tSIZE:" <<ptr->s.getSize() << "MB" << endl;
      ptr = ptr ->next;
    }

  }

  void UtPod::sortSongList() {
    int n = numSongs();

    SongNode *ptr1;
    SongNode *ptr2;
    Song temp;

    for (int i=0; i<n; i++) {
      ptr1 = songs->next;
      ptr2 = songs;
      while (ptr1 != NULL) {
        if (ptr2->s > ptr1->s) { //swap songs
          temp = ptr2->s;
          ptr2->s = ptr1->s;
          ptr1->s = temp;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
      }
    }
  }

  void UtPod::clearMemory() {
    SongNode *ptr1;
    SongNode *ptr2;
    SongNode *temp;
    ptr1 = songs;
    ptr2 = songs;
    temp = ptr2;

    while(ptr1 != NULL) {
      ptr1 = ptr1->next;
      temp = ptr2;
      delete temp;
      ptr2 = ptr2->next;
    }
  }

  int UtPod::getRemainingMemory() {
    int remMem = memSize;
    SongNode *ptr = songs;

    while (ptr != NULL) {
      remMem = remMem - (ptr->s.getSize());
      ptr = ptr->next;
    }

    return remMem;

  }
//returns the number of songs in UtPod
  int UtPod::numSongs() {
    SongNode *ptr;
    ptr = songs;
    int numSongs = 0;

    if (ptr == NULL) {
      return 0;
    }
    else {
      while (ptr != NULL) {
        numSongs++;
        ptr = ptr->next;
      }
      return numSongs;
    }
  }

  UtPod::~UtPod() {
    clearMemory();

  }
