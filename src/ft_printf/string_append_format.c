#include "ft_string.h"

#include "ft_printf_private.h"

/**
** Append a string formed in a similar manner as printf.
*/
int string_append_format(t_string* self, const char* format, ...)
{
    va_list  arguments;

    va_start(arguments, format);
    ft_string_vprintf(self, format, arguments);
    va_end(arguments);
    return self->size;
}
