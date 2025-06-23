#include <stdio.h>   // This enables to use I/O functions
#include <stdbool.h> // This enables to use bool type
#define MAX_LEN 100  // Maximum length of strings in our program

// String operations:
int strlen(char *str);
int strcmp(char *str1, char *str2);
int strncmp(char *str1, char *str2, int n);
bool isPrefix(char *str1, char *str2);
bool isPostfix(char *str1, char *str2);
int strchr(char *str, char c);
int strstr(char *str1, char *str2);
void strcpy(char *dst, char *src);
void strcat(char *dst, char *src);
void strswap(char *str1, char *str2);
void reverse(char *str);
bool isPalindrome(char *str);
bool isDigit(char *str);

int main() {
  printf("strlen(\"hello\") = %d\n", strlen("hello"));
  printf("strlen(\"hello, world!\") = %d\n", strlen("hello, world!"));
  printf("strcmp(\"world\", \"word\") = %d\n", strcmp("world", "word"));
  printf("strcmp(\"hello\", \"word\") = %d\n", strcmp("hello", "word"));
  printf("strcmp(\"word\", \"word\") = %d\n", strcmp("word", "word"));
  printf("strncmp(\"world\", \"word\", 3) = %d\n", strncmp("world", "word", 3));
  printf("strncmp(\"world\", \"word\", 4) = %d\n", strncmp("world", "word", 4));
  printf("isPrefix(\"hello, world\", \"hello\") = %d\n", isPrefix("hello, world", "hello"));
  printf("isPrefix(\"hello, world\", \"world\") = %d\n", isPrefix("hello, world", "world"));
  printf("isPostfix(\"hello, world\", \"hello\") = %d\n", isPostfix("hello, world", "hello"));
  printf("isPostfix(\"hello, world\", \"world\") = %d\n", isPostfix("hello, world", "world"));
  printf("strchr(\"hello, world\", 'l') = %d\n", strchr("hello, world", 'l'));
  printf("strchr(\"hello, world\", 'z') = %d\n", strchr("hello, world", 'z'));
  printf("strstr(\"hello, world\", \"world\") = %d\n", strstr("hello, world", "world"));
  printf("strstr(\"hello, world\", \"word\") = %d\n", strstr("hello, world", "word"));


  char a[MAX_LEN] = "hello, world";
  strcpy(a, "goodbye");
  printf("strcpy(a, \"goodbye\") -> %s\n", a);

  strcpy(a, "hell");
  printf("strcpy(a, \"hell\") -> %s\n", a);

  strcat(a, "o, world");
  printf("strcat(a, \"o, world\") -> %s\n", a);
  
  char b[MAX_LEN] = "data structure";
  strswap(a, b);
  printf("strswap(a, b) -> a: %s / b: %s\n", a, b);
  
  reverse(a);
  printf("reverse(a) -> %s\n", a);
  
  printf("isPalindrome(\"racecar\") = %d\n", isPalindrome("racecar"));
  printf("isPalindrome(\"madam\") = %d\n", isPalindrome("madam"));
  printf("isPalindrome(\"tenet\") = %d\n", isPalindrome("tenet"));
  printf("isPalindrome(\"world\") = %d\n", isPalindrome("world"));

  printf("isDigit(\"01010112158261\") = %d\n", isDigit("01010112158261"));
  printf("isDigit(\"0101011-258261\") = %d\n", isDigit("0101011-258261"));
  printf("isDigit(\"0x0af82524\") = %d\n", isDigit("0x0af82524"));
  return 0;
}

int strlen(char *str) {
  // TODO: compute the length of the string
  int len = 0;
  while (*str != '\0') {
    len ++;
    str ++;
  }
  return len;
}

int strcmp(char *str1, char *str2) {
  // TODO: compare two strings
  while (*str1 != '\0' || *str2 != '\0') {
    if (*str1 < *str2) return -1;
    if (*str1 > *str2) return 1;
    str1 ++;
    str2 ++;
  }
  return 0;
}

int strncmp(char *str1, char *str2, int n) {
  // TODO: compare two strings at most the first n bytes
  while (n > 0 && (*str1 != '\0' || *str2 != '\0')) {
    if (*str1 < *str2) return -1;
    if (*str1 > *str2) return 1;
    str1 ++;
    str2 ++;
    n --;
  }
  return 0;
}

bool isPrefix(char *str1, char *str2) {
  // TODO: check whether str2 is a prefix string of str1 or not
  return strncmp(str1, str2, strlen(str2)) == 0;
}

bool isPostfix(char *str1, char *str2) {
  // TODO: check whether str2 is a postfix string of str1 or not
  int len1 = strlen(str1), len2 = strlen(str2);
  if (len1 < len2) return false;
  return strcmp(str1+len1-len2, str2) == 0;
}

int strchr(char *str, char c) {
  // TODO: search for the occurrence of the character c in the string str
  for (int i = 0; str[i] != '\0'; i ++)
    if (str[i] == c)
      return i;
  return -1;
}

int strstr(char *str1, char *str2) {
  // TODO: search for the occurrence of the string str2 in the string str1
  int len1 = strlen(str1), len2 = strlen(str2);
  for (int i = 0; i <= len1-len2; i ++)
    if (strncmp(str1+i, str2, len2) == 0)
      return i;
  return -1;
}

void strcpy(char *dst, char *src) {
  // TODO: copy the string src to the string dst
  int srclen = strlen(src);
  for (int i = 0; i <= srclen; i++)
    dst[i] = src[i];
}

void strcat(char *dst, char *src) {
  // TODO: append the string src to the end of the string dst
  strcpy(dst+strlen(dst), src);
}

void strswap(char *str1, char *str2) {
  // TODO: swap two strings
  char temp[MAX_LEN];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

void reverse(char *str) {
  // TODO: reverse the order of the string
  int i, len = strlen(str);
  char temp;
  for (i = 0; i < len/2; i ++) {
    temp = str[i];
    str[i] = str[len-i-1];
    str[len-i-1] = temp;
  }
}

bool isPalindrome(char *str) {
  // TODO: check whether the string is palindrome or not
  int i, len = strlen(str);
  for (i = 0; i < len/2; i ++) {
    if (str[i] != str[len-i-1])
      return false;
  }
  return true;
}

bool isDigit(char *str) {
  // TODO: check whether all characters in the string are digits
  int i, len = strlen(str);
  for (i = 0; i < len; i ++) {
    if (str[i] < '0' || str[i] > '9')
      return false;
  }
  return true;
}
