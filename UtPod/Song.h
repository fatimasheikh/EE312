
#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
  private:
    string artist;
    string title;
    int size; //size of song in MB

  public:
    Song();
    Song(string artist, string title, int size);

    //input - none
    //output - returns artist name (string)
    string getArtist() const;

    //input - artist name (string)
    //output - none
    void setArtist(string a);

    //input - none
    //output - returns song title (string)
    string getTitle() const;

    //input - song title (string)
    //output - none
    void setTitle(string t);

    //input - none
    //output - returns song size (int)
    int getSize() const;

    //input - song size (int)
    //output - none
    void setSize(int s);

    //Evaluates if songs are same, when artist, title, and size are exactly same
    bool operator ==(Song const &rhs);

    //Songs are evaluated to be greater following this order:
    //alphabetical order of artists (following ASCII), then
    //alphabetical order of titles (following ASCII), then
    //ascending order of numeric size (following ASCII)
    bool operator >(Song const &rhs);

    //Songs are evaluated to be lesser following this order:
    //reverse alphabetical order of artists (following ASCII), then
    //reverse alphabetical order of titles (following ASCII), then
    //descending order of numeric size (following ASCII)
    bool operator <(Song const &rhs);

    ~Song();
};




#endif
