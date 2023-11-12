#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - A printf alternative function
 *
 * @format: format specifier
 * @...: arguments
 *
 * Return:Number of characters printed
**/
int _printf(const char *format, ...)
{
    int i = 0, ptot = 0;
    va_list args;

    va_start(args, format);

    if (format == NULL)
    {
        fprintf(stderr, "Error: Format string is NULL\n");
        return (-1);
    }

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            ptot++;
        }
        else if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            if (format[i] == 'c')
                ptot += _putchar(va_arg(args, int));
            else if (format[i] == 's')
                ptot += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                ptot += _putchar('%');
            else
            {
                fprintf(stderr, "Error: Unsupported format specifier: %%%c\n", format[i]);
                ptot += _putchar('%');
                ptot += _putchar(format[i]);
            }
        }
        else
            ptot += _putchar('%');
    }
    va_end(args);
    return (ptot);
}

/**
 * _putchar - Writes the character 'c' to the standard output
 * @c: The character be print
 *
 * Return: On success,returns 1.On error,returns -1 with errno set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - prints a string to stdout
 * @str: The string to print
 *
 * Return: On success the length of the string.
 */
int print_string(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        _putchar(str[i]);

    return (i);
}

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    printf("Length:[%d]\n", len);
    len = _printf("Character:[%c]\n", 'H');
    printf("Length:[%d]\n", len);
    len = _printf("String:[%s]\n", "I am a string !");
    printf("Length:[%d]\n", len);
    len = _printf("Percent:[%%]\n");
    printf("Length:[%d]\n", len);
    len = _printf("Unknown:[%r]\n");
    printf("Length:[%d]\n", len);

    return (0);
}
