#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */

int append_text_to_file(const char *filename, char *text_content);
{
	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		return (1);
	}
	FILE *file = fopen(filename, "a");

	if (file == NULL)
	{
		return (-1);
	}
	size_t length = strlen(text_content);

	size_t written = fwrite(text_content, sizeof(char), length, file);

	fclose(file);
	if (written != length)
	{
		return (-1);
	}
	return (1);
}

