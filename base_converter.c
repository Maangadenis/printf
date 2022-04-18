#include "main.h"

/**
 * convert_b - convert argument to binary
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_b(va_list args, buffer_t *output)
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
	len += convert_base(d, 2, "01", output);
	return (len);
}


/**
 * convert_o - convert argument to base8
 * and put it in the output
 *
 * @args: list of arguments
 * @output: the result output
 *
 * Return: the number of bytes stored in buffer
 */
unsigned int convert_o(va_list args, buffer_t *output)
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
	len += convert_base(d, 8, "01234567", output);
	return (len);
}
