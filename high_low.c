#include <stdio.h>

void high_and_low (const char *strnum, char *result)
{
  int offset = 0, high = -0xffffffff, low = 0xffffffff,  num = 0, negative = 1;
  while(strnum[offset] != '\0') {
    while (strnum[offset] != '\0' && strnum[offset] != ' ') {
      if (strnum[offset] == '-') { negative = 1; } else {
        num = num * 10 + (strnum[offset]-48);
      }
      offset++;
    }
    if (negative) {
      num *= -1;
      negative = 0;
    }
    if (num < low) { low = num; }
    if (num > high) { high = num; }
    num = 0;
    if (strnum[offset] != '\0') { offset++; }
  }
	sprintf(result, "%d %d", high, low);
}
