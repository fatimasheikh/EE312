/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe, Fatima Sheikh
EE 312 11/01/18

This is a driver for the UtPod.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
  UtPod t1; //Case: create UtPod t1 of default memory size
  UtPod t2(100); //Case: create UtPod t2 of specified memory size

  //Case: check if UtPod memory sizes are correct
  int totalMem = t1.getTotalMemory();
  cout << "t1 total memory = " << totalMem << endl;
  int remMem = t1.getRemainingMemory();
  cout << "t1 remaining memory = " << remMem << endl;

  totalMem = t2.getTotalMemory();
  cout << "t2 total memory = " << totalMem << endl;
  remMem = t2.getRemainingMemory();
  cout << "t2 remaining memory = " << remMem << endl;
  cout << endl;

  //Case: remove song that does not exist in UtPod
  Song s1;
  int result = t1.removeSong(s1);
  cout << "result = " << result << endl;
  cout << endl;

  //Case: add song to UtPod t1 and show song list
  Song s2("Beatles", "Hey Jude", 500);
  result = t1.addSong(s2);
  cout << "result = " << result << endl;

  cout << "t1 song list: " <<endl;
  t1.showSongList();
  cout << endl;

  //Case: add song that is larger than size of UtPod t2 and show song list
  result = t2.addSong(s2);
  cout << "result = " << result << endl;

  cout << "t2 song list: " <<endl;
  t2.showSongList();
  cout << endl;

  //Case: add more songs to UtPod t2
  Song s3("Britney Spears", "Toxic", 12);
  Song s4("ABBA", "Waterloo", 5);
  Song s5("Drake", "In My Feelings", 30);
  Song s6("Britney Spears", "Womanizer", 21);
  Song s7("Michael Jackson", "Thriller", 6);
  Song s8("Drake", "In My Feelings", 1);

  result = t2.addSong(s3);
  cout << "result = " << result << endl;
  result = t2.addSong(s4);
  cout << "result = " << result << endl;
  result = t2.addSong(s5);
  cout << "result = " << result << endl;
  result = t2.addSong(s6);
  cout << "result = " << result << endl;
  result = t2.addSong(s7);
  cout << "result = " << result << endl;
  result = t2.addSong(s8);
  cout << "result = " << result << endl;

  cout << "t2 song list: " <<endl;
  t2.showSongList();
  cout << endl;


  //Case: shuffle, sort, and show list
  //Sort songs with different artists
  //Sort songs with same artist but different titles
  //Sort songs with same artist, title but diffent sizes
  t2.sortSongList();
  t2.showSongList();
  cout << endl;
  t2.shuffle();
  t2.showSongList();
  cout << endl;
  t2.sortSongList();
  t2.showSongList();
  cout << endl;
  t2.shuffle();
  t2.showSongList();
  cout << endl;
  t2.sortSongList();
  t2.showSongList();
  cout << endl;
  t2.shuffle();
  t2.showSongList();
  cout << endl;

  //Case: check total and remaining memory after adding songs
  totalMem = t2.getTotalMemory();
  cout << "t2 total memory = " << totalMem << endl;
  remMem = t2.getRemainingMemory();
  cout << "t2 remaining memory = " << remMem << endl;
  cout << endl;

  //Case: remove songs, resort, and reshuffle
  result = t2.removeSong(s2);
  cout << "result = " << result << endl;
  result = t2.removeSong(s3);
  cout << "result = " << result << endl;
  result = t2.removeSong(s6);
  cout << "result = " << result << endl;
  result = t2.removeSong(s7);
  cout << "result = " << result << endl;
  t2.showSongList();
  cout << endl;
  t2.sortSongList();
  t2.showSongList();
  cout << endl;
  t2.shuffle();
  t2.showSongList();

  //Case: check total and remaining memory after removing songs
  totalMem = t2.getTotalMemory();
  cout << "t2 total memory = " << totalMem << endl;
  remMem = t2.getRemainingMemory();
  cout << "t2 remaining memory = " << remMem << endl;
  cout << endl;

}
