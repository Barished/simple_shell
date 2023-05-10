#include "main.h"
#include <stdio.h>

/**
 **_strcpy - copies the string pointed to by src, including
 *the terminating null byte to the buffer pointed to by dest
 *@dest: destination
 *@src: source
 *Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int inc = 0;

	while (*(src + inc) != '\0')
	{
		*(dest + inc) = *(src + inc);
		inc++;
	}
	*(dest + inc) = '\0';
	return (dest);
}
