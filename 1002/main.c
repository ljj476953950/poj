#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n;
	char input[100];
	int num[26]={2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
	int *in_data;
	int i,j,tmp,tmp1;;

	scanf("%d",&n);
	in_data = (int*)malloc(9999999*4);
	memset(in_data,0,9999999*4);
	for(i=0;i<n;i++)
	{
		scanf("%s",input);
		j=0;
		tmp=0;
		while(input[j]!='\0')
		{
			
			if(input[j]>='A')
			{
				tmp = (tmp+num[input[j]-'A'])*10;
			}
			else if(input[j]=='-')
			{
				j++;
				continue;
			}
			else
			{
				tmp =  (tmp+(input[j] - '0'))*10;	
			}
			j++;
		}
		in_data[tmp/10]++;
	}
	tmp=0;
	for(i=0;i<=9999999;i++)
	{
		if(in_data[i]>1)
		{
			tmp++;
			printf("%03d-",i/10000);
			printf("%04d ",i%10000);
			printf("%d\n",in_data[i]);
		}
		
	}
	if(tmp==0)
		printf("No duplicates.");
	
	
	
	return 0;
}
