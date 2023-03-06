// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
  int count = 0;
  int countWithNumber = 0;
  bool isWord = false;
  bool wordWithNumber = false;
  while (*str) {
    if (*str >= '0' && *str <= '9' && wordWithNumber == false) {
        countWithNumber++;
        wordWithNumber = true;
    }
    if (*str != ' ' && isWord == false) {
      isWord = true;
      count++;
    } else if (*str == ' ' && isWord == true) {
      isWord = false;
      wordWithNumber = false;
    }
    ++str;
  }
  return (count - countWithNumber);
}

unsigned int faStr2(const char *str) {
  int count = 0;
  int isOurWord = 0;
  while (*str) {
    if (*str >= 'A' && *str <= 'Z' && isOurWord == 0) {
      isOurWord = 1;
    } else if (*str >= 'a' && *str <= 'z' && isOurWord == 1) {
      isOurWord = 1;
    } else if (*str != ' ' && isOurWord == 1) {
      isOurWord = -1;
    } else if (*str == ' ' && isOurWord == 1) {
      count++;
      isOurWord = 0;
    } else if (*str == ' ') {
      isOurWord = 0;
    }
    ++str;
  }
  return count;
}

unsigned int faStr3(const char *str) {
  int countWord = 0;
  int countLetters = 0;
  bool isWord = false;
  while (*str) {
    if (*str != ' ' && isWord == false) {
      countWord++;
      countLetters++;
      isWord = true;
    } else if (*str != ' ') {
      countLetters++;
    } else if (*str == ' ' && isWord == true) {
      isWord = false;
    }
    ++str;
  }
  return (countLetters/countWord);
}
