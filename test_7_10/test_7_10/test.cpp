#include<iostream>
using namespace std;

int my_strlen(char* str)
{
	int count = 0;
	char* tmp = str;
	while (*tmp)
		count++;
	return count;
}

char* my_strcat(char* dst, char* src)
{
	char* t_dst;
	while (*t_dst)
		t_dst++;
	while (*t_dst++ = *src++);
	return dst;
}

int my_strcmp(char* str1, char* str2)
{
	char* d_str1 = str1;
	char* d_str2 = str2;
	while (*d_str1&&*d_str2)
	{
		if (*d_str1 > *d_str2)
			return 1;
		if (*d_str1 < *d_str2)
			return -1;
		else
		{
			d_str1++;
			d_str2++;
		}
	}
	if (*d_str1&&*d_str2=='\0')
		return 1;
	if (*d_str2&&*d_str1=='\0')
		return -1;
	else
		return 0;

}

char* my_strstr(char* dst, char* src)
{
	char* dsti = dst;
	char* srci = src;
	while (*dsti)
	{
		while (*dsti == *srci&&*srci)
		{
			dsti++;
			srci++;
		}
		if (*srci == '\0')
			return dsti;
		else
		{
			srci = src;
			dst++;
			dsti = dst;
		}
	}
	return NULL;
}

void* my_memcopy(void* dst, void* src, int n)
{
	char* dsti = (char*)dst;
	char* srci = (char*)src;
	for (int i = 0; i < n; i++)
	{
		dsti[i] = srci[i];
	}
	return dst;
}

void* my_memmove(void* dst, void* src, int n)
{
	char* dsti = (char*)dst;
	char* srci = (char*)src;
	if (dsti > srci&&dsti < srci + n)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			dsti[i] = srci[i];
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
			dsti[i] = srci[i];
	}
}
