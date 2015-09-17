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
	int n;
	char input[7],buffer[129] = {0};
	int i,j,point=0,point_be=0,point_out,point_out2,int_be=1,end=0,zero_num=0,zero_num2;
	int first = 1, first_num;
	int R=0;
	int tmp,tmp_c,R_tmp[32];	
	while(scanf("%s %d",input,&n)!=EOF){
		
	R_tmp[0] = 1;
	for(i=1;i<32;i++)R_tmp[i]=0;
		first = 1;point=0;point_be=0;int_be=1;end=0;zero_num=0;first = 1;R=0;
	for(i=0;i<6;i++)
	{
		if(point_be && input[i]!='0')
			{
			int_be=0;
			zero_num=0;
			}
		if(point_be && input[i]=='0')
			zero_num +=1;
		if(input[i]=='.')
		{
			point = i;
			point_be = 1;
		}
		else
			R += (input[i] - '0')*my_pow(10,4-i+point_be);
		
	}	
	point_out = (5-point) * n;
	zero_num = zero_num * n;
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
	
	for(i=31;i>=0;i--)
	{
		buffer[4*(31-i)] = R_tmp[i]/1000+'0';
		buffer[4*(31-i)+1] = R_tmp[i]/100%10+'0';
		buffer[4*(31-i)+2] = R_tmp[i]/10%10+'0';
		buffer[4*(31-i)+3] = R_tmp[i]%10+'0';
		if(first)
		{
			
			if(R_tmp[i]!=0)
			{
				first=0;
				first_num = 4*(31-i);
				if(R_tmp[i]>=1000)
					continue;
				else if(R_tmp[i]>=100)
					first_num += 1;
				else if(R_tmp[i]>=10)
					first_num += 2;
				else
					first_num += 3;
			}
		}
			
	}
	
	if(int_be)
	{
		buffer[128-point_out] = '\0';
	}
	else buffer[128-zero_num] = '\0';
	
	if(first_num>point_out)
	{
		buffer[point_out] = '\0';
		printf("%s",&buffer[first_num]);
		if(int_be)break;
		else
		printf(".");
		printf("%s",&buffer[point_out+1]);
	}
		
		
	
	//tmp = buffer[64];
//	buffer[64] = '\0';
//	printf("%s",buffer);
//	buffer[128] =  '\0';
//	printf("%s",&buffer[65]);
/*
	for(i=31;i>=0;i--)
	{
		if(end)break;
		if(first)
		{
			if((R_tmp[i]!=0) || ((point_out < (i+1)*4+1) &&(point_out >= i*4+1) ))
			{
				zero_num2 = zero_num-i*4-1;
				if((point_out < (i+1)*4+1) &&(point_out >= i*4+1) )
				{
					point_out2 = point_out-i*4-1;
					for(j=3;j>=0;j--)
					{
						if(point_out2 == j)	
						{
							if(int_be)
							{
								end = 1;
								break;
							}
							printf(".");
							
							first=0;
						}
						if(zero_num2 == j)	
						{
							end = 1;
							break;
						}
						tmp=(R_tmp[i]/my_pow(10,j))%10;
						if(tmp)
						{
							first=0;
						}
						if(first==0)
							printf("%d",tmp);
					}	
				}
				
				else 
				{
					printf("%d",R_tmp[i]);
					first=0;
				}
					
		
			}
		}
		else 
		{
		if(((point_out < (i+1)*4+1) &&(point_out >= i*4+1) ))
		{
			point_out2 = point_out-i*4;
			zero_num2 = zero_num-i*4-1;
			for(j=3;j>=0;j--)
			{
				if(point_out2-1 == j)	
				{
					if(int_be)
					{
						end = 1;
						break;
					}
						
					printf(".");
					
				}
				if(zero_num2 == j)	
						{
							end = 1;
							break;
						}
				printf("%d",(R_tmp[i]/my_pow(10,j))%10);
			}
		}
		else if((zero_num < (i+1)*4+1) &&(zero_num >= i*4+1) )
		{
			zero_num = zero_num-i*4;
			for(j=3;j>=0;j--)
			{
				if(zero_num-1 == j)	
				{
					end = 1;
					break;
				}
				printf("%d",(R_tmp[i]/my_pow(10,j))%10);
			}
			
		}
		else 
			printf("%04d",R_tmp[i]);
		
		}
	}*/
	printf("\n");
	
	}
	
	return 0;
}