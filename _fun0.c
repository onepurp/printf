#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar- #
 *
 * @c: #
 *
 * Return: #
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * pi- #
 *
 * @n: #
 *
 * Return: #
 */

int pi(int n)
{
	int ra9m = 0;
	int dis = 1;
	int mm = n;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	if (n < 0)
	{
		n = -n;
		_putchar('-');
		ra9m++;
	}

	while (mm > 9)
	{
		mm /= 10;
		dis *= 10;
	}

	while (dis > 0)
	{
		int ra9m0 = n / dis;
		_putchar('0' + ra9m0);
		n %= dis;
		dis /= 10;
		ra9m++;
	}

	return (ra9m);
}

/**
 * pu- #
 *
 * @n: #
 * @bb: #
 * @ra9m: #
 *
 * Return: count
 */

int pu(unsigned int n, int bb, char *ra9m)
{
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		int ra9m0 = n % bb;
		_putchar(ra9m[ra9m0]);
		n /= bb;
		count++;
	}

	return (count);
}

/**
 * _printf- #
 *
 * @format: #
 *
 * Return: pc
 */

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
			}
		else if (*no9ta == 'c')
		{
				int c = va_arg(ag, int);
				pc += _putchar(c);
			}
		else if (*no9ta == 's')
		{
				char *str = va_arg(ag, char*);
				if (str == NULL)
					str = "(null)";

				while (*str != '\0')
		{
					pc += _putchar(*str);
					str++;
				}
			}
		else if (*no9ta == 'd' || *no9ta == 'i')
		{
				int n = va_arg(ag, int);
				pc += pi(n);
			}
		else if (*no9ta == 'u')
		{
				unsigned int n = va_arg(ag, unsigned int);
				pc += pu(n, 10, "0123456789");
		}
		else if (*no9ta == 'o')
		{
				unsigned int n = va_arg(ag, unsigned int);
				pc += pu(n, 8, "01234567");
			}
		else if (*no9ta == 'x' || *no9ta == 'X')
		{
				unsigned int n = va_arg(ag, unsigned int);
				char *ra9m = (*no9ta == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
				pc += pu(n, 16, ra9m);
			}
		}
	else
	{
			pc += _putchar(*no9ta);
		}
	}

	va_end(ag);

	return (pc);
}

