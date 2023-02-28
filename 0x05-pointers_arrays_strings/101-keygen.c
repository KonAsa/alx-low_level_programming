#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
int random;
int i;
int j;

srand(time(0));
for (i = 0, j = 2772; j > 122; i++)
{
random = (rand() % 125) + 1;
printf("%c", random);
j -= random;
}
printf("%c", j);

return (0);
}
