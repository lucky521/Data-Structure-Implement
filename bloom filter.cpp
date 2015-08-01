#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 256
#define SIZE 48000000
#define MAX 384000000

//典型的bitmap操作
#define SETBIT(ch,n) ch[n/8]=1<<(7-n%8)
#define GETBIT(ch,n) (ch[n/8]&1<<(7-n%8))>>(7-n%8)

unsigned int len(char *ch)
{
	int m=0;
	while(ch[m]!='\0')
		m++;
	return m;
}

unsigned int RS_hash(char *str, unsigned int len)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	unsigned int i = 0;
	for(i=0;i<len;str++,i++)
	{
		hash = hash*a + (*str);
		a = a*b;
	}
	return hash;
}

unsigned int JS_hash(char *str, unsigned int len)
{
	unsigned int hash = 1315423911;
	unsigned int i = 0;
	for(i=0;i<len;str++,i++)
	{
		hash ^= ((hash<<5) + (*str) + (hash>>2));
	}
	return hash;
}

int main()
{
	int i, num ,num2=0;
	unsigned int tt=0;
	int flag;
	char buf[257];
	time_t tmp = time(NULL);

	char file1[100], file2[100];
	FILE *fp1, *fp2;
	char ch[ARRAY_SIZE];

	//申请ve这段连续空间用来存储hash表
	char *ve;
	ve = (char*)calloc(SIZE, sizeof(char));

	scanf("%s", &file1);
	if((fp1 = fopen(file1, "rb")) == NULL)
		return -1;

	scanf("%s", &file2);
	if((fp2 = fopen(file2, "rb")) == NULL)
		return -1;

	for(i=0;i<SIZE;i++)
		ve[i] = 0;


	while(!feof(fp1))
	{
		fgets(ch, ARRAY_SIZE, fp1);
		flag = 0;
		if( GETBIT(ve, RS_hash(ch, len(ch))%MAX) )
			flag++;
		else
			SETBIT(ve, RS_hash(ch, len(ch))%MAX )



		if(flag<6)
			


	}


}
