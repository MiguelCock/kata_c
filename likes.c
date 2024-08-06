#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *likes(size_t n, const char *const names[n]) {
  char* res;
  int len;
  int amount = n;
  switch (n) {
    case 0:
      res = (char*)malloc(17);
      sprintf(res, "no one likes this"); 
      break;
    case 1:
      len = strlen(names[0]);
      res = (char*)malloc(len + 12);
      sprintf(res, "%s likes this", names[0]);
      break;
    case 2:
      len = strlen(names[0]) + strlen(names[1]);
      res = (char*)malloc(len + 16);
      sprintf(res, "%s and %s like this", names[0], names[1]);
      break;
    case 3:
      len = strlen(names[0]) + strlen(names[1]) + strlen(names[2]);
      res = (char*)malloc(len + 18);
      sprintf(res, "%s, %s and %s like this", names[0], names[1], names[2]);
      break;
    default:
      len = strlen(names[0]) + strlen(names[1]) - 2;
      while (amount > 9) { len++; amount/=10; }
      res = (char*)malloc(len + 24);
      sprintf(res, "%s, %s and %lu others like this", names[0], names[1], n-2);
      break;
  }
  return res;
}
