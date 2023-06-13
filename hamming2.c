#include<stdio.h>

int main(){
  int data[7], datarec[7];
  int c,c1,c2,c3;

  printf("Enter the 4 bits one by one: ");
  scanf("%d",&data[0]);
  scanf("%d",&data[1]);
  scanf("%d",&data[2]);
  scanf("%d",&data[4]);

  data[6] = data[0] ^ data[2] ^ data[4];
  data[5] = data[0] ^ data[1] ^ data[4];
  data[3] = data[0] ^ data[1] ^ data[2];

  printf("The entered data bits are: ");
  for(int i=0;i<7;i++)
    printf("%d ", data[i]);
  printf("\n");

  printf("Enter the received bits: ");
  for(int i=0;i<7;i++)
    scanf("%d", &datarec[i]);
  
  c1 = data[6] ^ data[4] ^ data[2] ^ data[0];
  c2 = data[5] ^ data[4] ^ data[1] ^ data[0];
  c3 = data[3] ^ data[2] ^ data[1] ^ data[0];
  c = c3*4 + c2*2 + c1;

  if(c==0){
    printf("No error");
  }
  else{
    printf("Error detected on bit %d", c);
    if(datarec[7-c]==0)
      datarec[7-c] = 1;
    else datarec[7-c] = 0;

    printf("Corrected Data:\n");
    for(int i=0;i<7;i++)
      printf("%d ", datarec[i]);
    printf("\n");
  }

  return 0;

}