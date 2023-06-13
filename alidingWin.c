#include<stdio.h>

int main(){
  int w,i,f,frames[50];
  printf("Enter the window size: ");
  scanf("%d", &w);
  printf("Enter the number of frames: ");
  scanf("%d", &f);
  printf("Enter the %d frames: ", f);
  for(i=1;i<=f;i++)
    scanf("%d", &frames[i]);
  
  for(i=1;i<=f;i++){
    if(i%w==0){
      printf("%d\n", frames[i]);
      printf("Ack for the above frames sent and received by the sender\n\n");
    }
    else
      printf("%d ", frames[i]);
  }
  if(f%w!=0){
    printf("\nAck for above frames sent and received by the sender");
  }
}