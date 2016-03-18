/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	char temp;
	int i = 0, j = 0, l = 0, index = 0;

	while (l < len){
		while (input[l] != ' ' && l < len)
			l++;
		printf("l:%d", l);
		j = l - 1;
		i = index;
		while (i < j)
		{
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j--;
		}
		index = l + 1;
		i = index;
		l++;
		printf("%d", l);
	}
	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}

}
