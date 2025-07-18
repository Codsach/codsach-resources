#include<stdio.h>
#include<conio.h>

struct node{
	unsigned dist[20];
	unsigned from[20];
}rt[10];

int main(){
	int i,j,k,n,count;
	int dmat[20][20];

	printf("Enter the Number of Nodes:");
	scanf("%d",&n);

	printf("Enter the Cost Matrix:\n");
	  for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		scanf("%d",&dmat[i][j]);

	if(i==j){
	  dmat[i][j]=0;
	}
	rt[i].dist[j]=dmat[i][j];
	rt[i].from[j]=j;
	}
      }

      do{
	count=0;
	for(i=0;i<n;i++){
	  for(j=0;j<n;j++){
	    for(k=0;k<n;k++){
		if(rt[i].dist[j] > dmat[i][k]+rt[k].dist[j]){
			rt[i].dist[j] = dmat[i][k]+rt[k].dist[j];
			rt[i].from[j] = k;

		}
	    }
	  }
	}
      }
      while(count != 0);
	for(i=0;i<n;i++){
	  printf("\n State the value for %d is\n",i+1);
	for(j=0;j<n;j++){
	  printf("\n Node %d via %d Distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
	}
      }
      printf("\n\n");
      getch();
      return 0;
}
