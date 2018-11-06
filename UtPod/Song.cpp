//Fatima Sheikh
//fs7487
//EE 312, 11/01/2018

#include "Song.h"

using namespace std;

  Song::Song() {
    title = "";
    artist = "";
    size = 0;
  }

  Song::Song(string artist, string title, int size) {
    this->artist = artist;
    this->title = title;
    this->size = size;
  }

  string Song::getArtist() const {
    return artist;
  }

  void Song::setArtist(string a) {
    artist = a;
  }

  string Song::getTitle() const {
    return title;
  }

  void Song::setTitle(string t) {
    title = t;
  }

  int Song::getSize() const {
    return size;
  }

  void Song::setSize(int s) {
    size = s;
  }

  bool Song::operator ==(Song const &rhs) {
    return (artist == rhs.artist && title == rhs.title && size == rhs.size);
  }

  bool Song::operator >(Song const &rhs) {
    if (artist > rhs.artist)
      return true;
    else if (artist < rhs. artist)
      return false;
    else if (title > rhs.title)
      return true;
    else if (title < rhs.title)
      return false;
    else if (size > rhs.size)
      return true;
    else if (size < rhs.size)
      return false;
    else
      return false;
  }

  bool Song::operator <(Song const &rhs) {
    if (artist > rhs.artist)
      return false;
    else if (artist < rhs. artist)
      return true;
    else if (title > rhs.title)
      return false;
    else if (title < rhs.title)
      return true;
    else if (size > rhs.size)
      return false;
    else if (size < rhs.size)
      return true;
    else
      return false;
  }

  Song::~Song() {}
