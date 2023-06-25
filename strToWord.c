#include "monty.h"
#include "lists.h"

/**
 * count_word - counts the number of words in a string
 * @s: str to evaluate
 *
 * Return: number of words
 */

int count_word(char *s)
{
	int pole, counter, word;

	pole = 0;
	word = 0;

	for (counter = 0; s[counter] != '\0'; counter++)
	{
		if (s[counter] == ' ')
			pole = 0;
		else if (pole == 0)
		{
			pole = 1;
			word++;
		}
	}

	return (word);
}

/**
 * **strtow - It splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */

char **strtow(char *str)
{
	char **matrices, *Temp;
	int i, k = 0, length = 0, alpha, c = 0, beg, end;

	length = strlen(str);
	alpha = count_word(str);
	if (alpha == 0)
		return (NULL);

	matrices = (char **) malloc(sizeof(char *) * (alpha + 1));
	if (matrices == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				Temp = (char *) malloc(sizeof(char) * (c + 1));
				if (Temp == NULL)
					return (NULL);
				while (beg < end)
					*Temp++ = str[beg++];
				*Temp = '\0';
				matrices[k] = Temp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			beg = i;
	}

	matrices[k] = NULL;

	return (matrices);
}

/**
 * free_everything - releases array of str
 * @args: array of strings to free
 */

void free_everything(char **args)
{
	int initial;

	if (!args)
		return;

	for (initial = 0; args[initial]; initial++)
		free(args[initial]);

	free(args);
}
