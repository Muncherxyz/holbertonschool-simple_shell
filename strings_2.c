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
		for (j = 0; needle[j] != '\0';     j++)192                 {193                         if (haystack[i + j] !=     needle[j])194                                 break;195                 }196                 if (needle[j] == '\0')197                         return (haystack + i); 198         }199         return (NULL);200 }
