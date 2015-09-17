#include <stdio.h>

int my_pow(int a,int b)
{
	int c=1;
	while(b--)
	{
		c *= a;
	}	
	return c;
}

int main()
{
	char input[6],output[32*4];
	int i,j,n,point=0,point_be=0,point_out;
	int R=0;
	int R_tmp[32]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},tmp,tmp_c;
	scanf("%s %d",input,&n);	
	for(i=0;i<6;i++)
	{
		if(input[i]=='.')
		{
			point = i;
			point_be = 1;
		}
		else
			R += (input[i] - '0')*my_pow(10,4-i+point_be);	
	}
	point_out = (5-point) * n;
	R_tmp[0] = 1;
	for(i=0;i<n;i++)
	{
		tmp = R_tmp[0] * R;
		R_tmp[0] = tmp % 10000;
		tmp_c = tmp / 10000;
		for(j=1;j<32;j++)
		{
			tmp = (R_tmp[j]*R+tmp_c);
			R_tmp[j] = tmp % 10000;
			tmp_c = tmp / 10000;
		}
	}
	int first = 1;
	for(i=31;i>=0;i--)
	{

		if(first)
		{
			if((R_tmp[i]!=0) || ((point_out < i*4) &&(point_out >= (i-1)*4) ))
			{
				first =0;
				point_out -= (i-1)*4);
				for(j=3;j>=0;j--)
				{
					if(point_out == j)	
					{
						printf(".");
					}
					if(R_tmp[i])
				}
			}
		}
		
		
		printf("%04d",R_tmp[i]);
	}
	
	
	
	return 0;
}