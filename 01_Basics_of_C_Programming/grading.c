#include <stdio.h>

int main() {
  char name[20];
  int score;
  char grade;
  scanf("%s", name);
  scanf("%d", &score);
  
  if (score >= 80) grade = 'A';
  else if (score >= 60) grade = 'B';
  else grade = 'C';
  
  printf("%s's grade is %c.", name, grade);
  return 0;
}
