#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - my own printf
 * @format: form for what returned
 *
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;
	va_start (args, format);

	if (!format || format[0])
		return (-1);
	
	while (*format)
	{
		if(*format == '%')
		{
			i++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;

			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);

				for (int j = 0; str[j] != '\0'; j++)
				{
					write(1, &str[j], 1);
					count++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1) ;
				count++;

			}
			else
			{
				write(1, *format, 1);
				count++;
			}
		}
	}


	va_end (args);
	return (count);

}
