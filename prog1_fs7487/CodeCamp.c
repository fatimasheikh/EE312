#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Fatima Sheikh, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Fatima Sheikh
 * email address: tammysheikh@sbcglobal.net
 * UTEID: fs7487
 * Section 5 digit ID: 16195
 *
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/
int hammingDistance(int aList[], int bList[], int len) {
  int hamDist = 0;
  for(int i = 0; i < len; i++) {
    if(aList[i] != bList[i]) {
      hamDist++;
    }
  }
  return hamDist;
}

/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2.
   post: return true if x and y have the same last digit, false otherwise.
*/
bool lastDigit(int x, int y) {
  int xLastDigit = abs(x%10);
  int yLastDigit = abs(y%10);
  if (xLastDigit == yLastDigit) {
    return true;
  }
  return false;
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/
int sum3or5Multiples() {
  int sum = 0;
  for(int num = 1; num < 1000; num ++) {
    if ((num%3) == 0) {
      sum = sum + num;
    }
    else if ((num%5) == 0) {
      sum = sum + num;
    }
  }
  return sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return x with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/
int reverseInt(int x) {
  int reverse = 0;
  while (x != 0) {
    int digit = x%10;
    reverse = (reverse*10)+digit;
    x = (x-digit)/10;
  }
  return reverse;
}
