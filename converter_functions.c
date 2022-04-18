#include "main.h"

/**
 * convert_c - convert argument to a char
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_c(va_list args, buffer_t *output)
{
	char c;
	unsigned int len = 0;

	c = va_arg(args, int);

	len += _memcpy(output, &c, 1);

	return (len);
}

/**
 * convert_s - convert argument to a string
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_s(va_list args, buffer_t *output)
{
	char *str;
	unsigned int len = 0;
	int i = 0;

	str = va_arg(args, char *);
	while (str[i])
	{
		len += _memcpy(output, str + i, 1);
		i++;
	}
	return (len);
}

/**
 * c_percent - convert percent argument
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int c_percent(va_list args __attribute__((unused)), buffer_t *output)
{
	char c = '%';
	unsigned int len = 0;

	len += _memcpy(output, &c, 1);

	return (len);
}

/**
 * convert_d - convert argument to a integer
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_d(va_list args, buffer_t *output)
{
	int d;
	unsigned int len = 0;
	char minus = '-';

	d = va_arg(args, int);
	if (d < 0)
	{
		len += _memcpy(output, &minus, 1);
		d = -d;
	}
	len += convert_base(d, 10, "0123456789", output);
	return (len);
}
