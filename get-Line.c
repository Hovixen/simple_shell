#include "main.h"
/**
 * getLine - function gets input from user
 * @in_ptr: pointer that points to the input command
 * @n: size of the input
 * @stream: where to read the input from
 * Return: return the size of the the input
 */
ssize_t getLine(char **in_ptr, size_t *n, FILE *stream)
{
	static char in_buff[MAX_CMD_ARG];
	static size_t buff_index = 0;
	static size_t buff_size = 0;
	size_t i = 0;
	char c;

	if (in_ptr == NULL || n == NULL)
		return (-1);
	if (*in_ptr == NULL || n == 0)
	{
		*in_ptr = (char *)malloc(MAX_CMD_ARG);
		if (*in_ptr == NULL)
			return (-1);
		*n = MAX_CMD_ARG;
	}
	while (1)
	{
		if (buff_index >= buff_size)
		{
			buff_size = read(fileno(stream), in_buff, MAX_CMD_ARG);
			if (buff_size <= 0)
			{
				if (i == 0)
					return (-1);
			} else
			{
				(*in_ptr)[i] = '\0'; /*Null terminating string*/
				return (i);
			}
		} buff_index = 0;
		c = in_buff[buff_index++];
		(*in_ptr)[i++] = c;
		if (c == '\n')
		{
			(*in_ptr)[i++] = '\0';
			return (i);
		}
		if (i >= *n - 1)
			resize_buff(in_ptr, n, i + 1);
	}
}
/**
 * resize_buff - function reallocates memory when the buffer is full
 * @in_ptr: pointer to the pointer of the input
 * @n: size of the input
 * @nsize: required size to be reallocated
 * Return: returns void
 */
void resize_buff(char **in_ptr, size_t *n, size_t nsize)
{
	char *temp;
	size_t sizeNew = (*n) * 2, i;

	while (sizeNew <= nsize)
		sizeNew *= 2;
	temp = (char *)malloc(sizeNew);

	if (temp == NULL)
		return;

	for (i = 0; i < nsize; i++)
		temp[i] = (*in_ptr)[i];
	free(*in_ptr);
	*in_ptr = temp;
	*n = nsize;
}

