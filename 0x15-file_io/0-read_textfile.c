#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
	return (0);
	}

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
	return (0);
	}

	char *buffer = (char *) malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
	fclose(file);
	return (0);
	}

	size_t n = fread(buffer, sizeof(char), letters, file);

	if (n == 0)
	{
	free(buffer);
	fclose(file);
	return (0);
	}

	size_t written = 0;

	while (written < n)
	{
	ssize_t bytes_written = write(STDOUT_FILENO, buffer + written, n - written);

	if (bytes_written <= 0)
	{
	free(buffer);
	fclose(file);
return (0);
	}
written += bytes_written;
}
free(buffer);
fclose(file);
return (n);
}

