#include<stdio.h>
#include<stdbool.h>
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int, int);
int reverseInt(int);

// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 *
 * Name: Fatima Sheikh
 * email address: tammysheikh@sbcglobal.net
 * UTEID: fs7487
 * Section 5 digit ID: 16195
 *
 */

int main() {
  // my test 1, hammingDistance
  int h1[] = {1, 3, 3, 4, -8, -7};
  int h2[] = {1, 2, 10, 4, 5, 4};
  int expected = 4;
  int actual = hammingDistance(h1, h2, 6);
  printf("My Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 1, hamming distance\n\n");
  else printf("**** FAILED **** my test 1, hamming distance\n\n");

  // my test 2, hamming distance
  int h3[] = {0, 6, 3, 3, 3, 15, -4, 13, -5, 4};
  int h4[] = {-6, 6, 3, -6, 9, 2, 21, 2, -6, -6};
  expected = 8;
  actual = hammingDistance(h3, h4, 10);
  printf("My Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 2, hamming distance\n\n");
  else printf("**** FAILED **** my test 2, hamming distance\n\n");

  // my test 3, hamming distance
  int h5[] = {1,1,1};
  int h6[] = {-1,-1,-1};
  expected = 3;
  actual = hammingDistance(h5, h6, 3);
  printf("My Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 3, hamming distance\n\n");
  else printf("**** FAILED **** my test 3, hamming distance\n\n");

  // my test 4, last digit
  int n1 = 5;
  int n2 = 1325;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("My Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 4, last digit\n\n");
  else printf("**** FAILED **** my test 4, last digit\n\n");

  // my test 5, last digit
  n1 = -1;
  n2 = 15;
  expected = false;
  actual = lastDigit(n1, n2);
  printf("My Test 5 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 5, last digit\n\n");
  else printf("**** FAILED **** my test 5, last digit\n\n");

  // my test 6, last digit
  n1 = 148;
  n2 = 38;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("My Test 6 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 6, last digit\n\n");
  else printf("**** FAILED **** my test 6, last digit\n\n");

  // test 7, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed test 7, sum of multiples of 3 or 5\n\n");
  else printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");

  // my test 8, reverse int
  n1 = -639;
  expected = -936;
  actual = reverseInt(n1);
  printf("My Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 8, reverse int\n\n");
  else printf("**** FAILED **** my test 8, reverse int\n\n");

  // My test 9, reverse int
  n1 = 500;
  expected = 5;
  actual = reverseInt(n1);
  printf("My Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 9, reverse int\n\n");
  else printf("**** FAILED **** My test 9, reverse int\n\n");

  // My test 10, reverse int
  n1 = 50934;
  expected = 43905;
  actual = reverseInt(n1);
  printf("My Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  printf("passed my test 10, reverse int\n");
  else printf("**** FAILED **** my test 10, reverse int\n");

}
