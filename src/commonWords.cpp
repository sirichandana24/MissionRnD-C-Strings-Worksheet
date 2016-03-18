/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int length(char *, int);
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	char *string1, *string2, **string;
	int i = 0, j = 0, k = 0, index = 0, n, length1 = 0, length2 = 0, l = 0;
	string = (char**)malloc(length1*sizeof(char));
	length1 = length(str1, length1);
	length2 = length(str2, length2);
	if (length1 > length2)
	{
		string1 = &str1[0];
		string2 = &str2[0];
	}
	else
	{
		string1 = &str2[0];
		string2 = &str1[0];
	}
	while (*string1 != '\0')
	{
		while (*string1 == ' ')
			string1++;
		while (*string2 == ' ')
			string2++;
		if (*string1 == '\0' || *string2 == '\0')
			return NULL;
		while (*string1 != *string2 && *string1 != '\0' && *string2 != '\0')
			string2++;
		if (*string1 == *string2)
		{
			n = 0;
			while (*string1 != ' ' && *string2 != ' ' && *string1 != '\0' && *string2 != '\0')
			{
				if (*string1 == *string2)
					n++;
				else
					break;
				string1++;
				string2++;
			}
			if ((*string1 == ' ' && *string2 == ' ') || (*string1 == '\0' && *string2 == '\0') || (*string1 == '\0' && *string2 == ' ') || (*string2 == '\0' && *string1 == ' '))
			{
				k = 0; i = 0;
				while (i < n)
				{
					i++;
					string1--;
				}
				n--;
				string[l] = (char*)malloc(n*sizeof(char));
				while (k <= n && *string1 != ' ')
				{
					string[l][k] = *string1;
					string1++;
					k++;
				}
				string[l][k] = '\0';
				string1++;
				l++;
				if (length1 > length2)
					string2 = str2;
				else
					string2 = str1;
			}
			else
			{
				string1 = string1 - n;
				while (*string2 != ' ' && *string2 != '\0')
					string2++;
				if (*string2 == ' ')
					string2++;
				if (*string2 == '\0')
				{
					if (length1 > length2)
						string2 = str2;
					else
						string2 = str1;
					while (*string1 != ' ')
						string1++;
				}
			}
		}
		else
			if (*string1 != '\0')
			{
				while (*string1 != ' ' && *(string1 + 1) != '\0')
					string1++;
				string1++;
				if (length1 > length2)
					string2 = str2;
				else
					string2 = str1;
			}
	}
	return string;
}
int length(char *str1, int length1)
{
	int i = 0;
	if (*str1 == '\0')
		return length1;
	else
		while (str1[i] != '\0')
			i++;
	return length1;
}


