#include <stdio.h>
#include <time.h>

void transmission(int i, int tf, int n)
{
}

int main()
{
  int tf, n, i = 1;
  srand(time(NULL));
  printf("Enter total frames: ");
  scanf("%d", &tf);
  printf("Enter the window size: ");
  scanf("%d", &n);
  transmission(i, tf, n);
}