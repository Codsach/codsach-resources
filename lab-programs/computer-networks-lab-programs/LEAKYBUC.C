#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MIN(x,y)((x)>(y) ? (y):(x))

int main(){
	int outputrate, drop=0, cap, x ,count=0;
	int inp[10]={0},i=0, nsec, ch;

	printf("\n Enter bucket size:");
	scanf("%d",&cap);

	printf("\n Enter output rate:");
	scanf("%d",&outputrate);

	do{
	   printf("\n Enter number of packets arriving at second %d:",i+1);
	   scanf("%d",&inp[i]);
	   i++;

	   printf("Enter 1 to continue or 0 to quit:");
	   scanf("%d",&ch);
	}

	while(ch==1);
	nsec=i;

	printf("\n Second\t Recieved\t Sent\t Dropped\t Remaining\n");
	for(i=0;count>0||i<nsec;i++){
	   printf("%d",i+1);
	   printf("\t%d\t",inp[i]);
	  int sent=MIN((inp[i]+count),outputrate);
	   printf("\t%d\t",sent);

	   x=inp[i]+count-sent;
	   if(x>cap){
		count=cap;
		drop=x-cap;
		}else{
		count=x;
		drop=0;
	   }
	   printf("\t%d\t%d\n",drop,count);
	}
	getch();
	return 0;
}