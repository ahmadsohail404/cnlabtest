#include<stdio.h> #include<stdlib.h>
void main() {
int p,i=1,a,w,nac,ack,j=0;
printf("Enter the frame length : "); 
scanf("%d",&a);
printf("Enter the window size : "); 
scanf("%d",&w); 
printf("\nTransmission started....\n\n"); 
while(i<=a)
{
printf("Packets from %d to %d are transmitted\n",i,w+i-1); 
for(p=i;p<w+i;p++)
{
printf("Transmitting packet %d\n",p); }
nac=i+rand()%w; 
if(nac==i)
{
printf("No Nack received\n");
printf("All the packets in the current window are sent successfully!!!\n"); 
i=i+w;
continue;
}
printf("\nNack = %d\n\n",nac);
printf("Ack received for all the packets except for packet %d\n",nac); 
printf("Sending packet %d back\n\n",nac);
printf("Ack is received for packet %d\n\n",nac);
printf("All the packets in the current window are sent successfully!!!\n\n"); 
i=i+w;
}
printf("USN : 4NI18IS022\n"); 
}