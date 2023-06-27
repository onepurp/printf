#include <unistd.h>
#include <stdarg.h>

int _putchar(char c)
{
	return write(1, &c, 1);
}

int print_integer(int n)
{
	int ra9m = 0;

	if (n == 0)
	{
		_putchar('0');
		return 1;
	}

	if (n < 0)
	{
		n = -n;
		_putchar('-');
		ra9m++;
	}

	while (n > 0) {
		int digit = n % 10;
		_putchar('0' + digit);
		n /= 10;
		ra9m++;
	}

	return ra9m;
}

int _printf(const char *format, ...)
{
	va_list ag;
	const char *no9ta;
	int pc = 0;

	va_start(ag, format);

	for (no9ta = format; *no9ta != '\0'; no9ta++)
	{
		if (*no9ta == '%')
		{
			no9ta++;

			if (*no9ta == '%')
			{
				pc += _putchar('%');
			} else if (*no9ta == 'c')
			{
				int c = va_arg(ag, int);
				pc += _putchar(c);
			} else if (*no9ta == 's')
			{
				char *str = va_arg(ag, char*);
				if (str == NULL)
					str = "(null)";

				while (*str != '\0')
				{
					pc += _putchar(*str);
					str++;
				}
			} else if (*no9ta == 'd' || *no9ta == 'i')
			{
				int n = va_arg(ag, int);
				pc += print_integer(n);
			}
		} else
		{
			pc += _putchar(*no9ta);
		}
	}

	va_end(ag);

	return pc;
}

