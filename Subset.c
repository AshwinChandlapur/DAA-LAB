

#include<stdio.h>
int x[10],s[10],c,sum=0,n,d;
void sub(int p,int k,int r)
{
	int i,j;
	if(p+s[k]>d || p+r<d)
	{
		return ;
	}
	x[k]=1;
	if(p+s[k]==d)
	{
		printf("The Subset %d{",++c);
		for(i=1;i<=k;i++)
		{
			if(x[i]==1)
			{
				printf("%d",s[i]);
			}
		}
		printf("}\n");
		return;
	}
	sub(p+s[k],k+1,r-s[k]);
	x[k]=0;
	sub(p,k+1,r-s[k]);
}
void main()
{
	int i;
	printf("Enter the No of Elements\n");
	scanf("%d",&n);
	printf("Enter the elements is ascending order\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		sum=sum+s[i];
	}
	printf("Enter the Max Subset value\n");
	scanf("%d",&d);
	sub(0,1,sum);
}

