/**
* _strstr - locate a substring
* description: locate a substring
* @haystack: character
* @needle: character
* Return: NULL
*/
char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
			if (needle[j] == '\0')
				return (haystack + i);
		}
	}
	return (NULL);
}
