#include<stdio.h>

char findClass(char str[]){
  char arr[4];
  int i=0;
  while(str[i]!='.'){
    arr[i] = str[i];
    i++;
  }
  i--;
  int ip=0,j=1;
  while(i>=0){
    ip = ip+(str[i]-'0')*j;
    j*=10;
    i--;
  }
  if(ip>=1 && ip<=127)
     return 'A';
    if(ip>=128 && ip<=191)
     return 'B';
    if(ip>=192 && ip<=223)
     return 'C';
    if(ip>=224 && ip<=237)
     return 'D';
    else
     return 'E';
}

void seperateClass(char str[], char ipClass){
  char net[12], host[12];
  for(int k=0;k<12;k++){
    net[k] = host[k] = '\0';
  }

  if(ipClass=='A'){
    int i=0,j=0;
    while(str[j]!='.')
      net[i++] = str[j++];
    i=0;
    j++;
    while(str[j]!='\0')
      host[i++] = str[j++];
    printf("Network id is: %s\n", net);
    printf("Host id is: %s\n", host);

  }

  else if(ipClass=='B'){
    int i=0,j=0,doCount=0;
    while(doCount<2){
      net[i++] = str[j++];
      if(str[i]=='.')
        doCount++;
    }
    i=0;
    j++;
    while(str[j]!='\0'){
      host[i++] = str[j++];
    }
    printf("Network id is: %s\n", net);
    printf("Host id is: %s\n", host);
  }
  else if(ipClass=='C'){
    int i=0,j=0,doCount=0;
    while(doCount<3){
      net[i++] = str[j++];
      if(str[i]=='.')
        doCount++;
    }
    i=0;
    j++;
    while(str[j]!='\0'){
      host[i++] = str[j++];
    }
    printf("Network id is: %s\n", net);
    printf("Host id is: %s\n", host);
  }
  else
    printf("D and E are reserved classes\n");
}

int main(){
  char str[100];
  scanf("%s", str);
  char ipClass = findClass(str);
  printf("ip class is: %c\n", ipClass);
  seperateClass(str, ipClass);
}