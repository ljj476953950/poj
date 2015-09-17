#include <stdio.h>

//求a的b次方
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
	int i,j,point=0,point_be=0,point_out,int_be=1,zero_num=0,first_num;
	int first = 1;
	int R=0;
	int tmp,tmp_c,R_tmp[32];	
	while(scanf("%s %d",input,&n)!=EOF){
		
	R_tmp[0] = 1;
	for(i=1;i<32;i++)R_tmp[i]=0;
		first = 1;point=0;point_be=0;int_be=1;zero_num=0;first = 1;R=0;
	//将输入的字符串转为不带小数点的整数，并记录小数点的位置。
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
	point_out = 128-(5-point) * n;
	zero_num = zero_num * n;
	//以4位数为单位，将大数据用拆分，以数组的形式保存，参考乘法进行进位和计算。
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
	//将保存有最终整数结果的数据从数组中提取出来存入buffer字符串中
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
	//找到小数点和首数字的位置进行显示
	if(int_be)
	{
		buffer[128-point_out] = '\0';
	}
	else buffer[128-zero_num] = '\0';
	
	if(first_num<point_out)
	{
		tmp=buffer[point_out];
		buffer[point_out] = '\0';
		printf("%s",&buffer[first_num]);
		if(int_be){
			printf("\n");
			continue;
		}
		else
		printf(".");
		buffer[point_out] = tmp;
		printf("%s",&buffer[point_out]);
	}
	else
	{
		printf(".");
		printf("%s",&buffer[point_out]);
	}

	printf("\n");
	
	}
	
	return 0;
}