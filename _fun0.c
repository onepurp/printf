#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _putchar: #
 *
 * @c: #
 *
 * Return: #
 */

int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf: #
 *
 * format: #
 *
 * Return: pc
 */

int _printf(const char *format, ...)
{
	va_list ag;
	const char *no9ta;
	int pc = 0;

	va_start(ag, format);

	no9ta = format;

	while (*no9ta != '\0') {
		if (*no9ta == '%') {
			no9ta++;

			if (*no9ta == '%') {
				pc += _putchar('%');
			} else if (*no9ta == 'c') {
				int c = va_arg(ag, int);
				pc += _putchar(c);
			} else if (*no9ta == 's') {
				char *str = va_arg(ag, char*);
				if (str == NULL)
					str = "(null)";

				{
					int i = 0;
					while (str[i] != '\0') {
						pc += _putchar(str[i]);
						i++;
					}
				}
			}
		} else {
			pc += _putchar(*no9ta);
		}

		no9ta++;
	}

	va_end(ag);

	return pc;
}

