#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar(int upper, int lower)
{
    int i = (rand() % (upper - lower + 1) + lower);
    char c = (char) i;

    return c;
}

char *inputString()
{
    char toBuild[6];
    char* string = toBuild;
    int i;

    for(i = 0; i < 5; i++)
    {
        toBuild[i] = inputChar(116, 101);
    }

    toBuild[5] = '\0';

    return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  time_t begin, end;

  time (&begin);

  while (1)
  {
    tcCount++;
    c = inputChar(125, 32);
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      time (&end);
      int elapsedTime = difftime (end, begin);
      printf("Elapsed time: %d seconds\n", elapsedTime); 
      printf("error\n");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
