#include "ft_ctype.h"

int ft_isdigit(int c) { return ('0' <= c && c <= '9'); }
int ft_isgraph(int c) { return (' ' < c && c <= '~'); }
int ft_islower(int c) { return ('a' <= c && c <= 'z'); }
int ft_isprint(int c) { return (' ' <= c && c <= '~'); }
int ft_isascii(int c) { return (0 <= c && c <= 127); }
int ft_isblank(int c) { return (c == ' ' || c == '\t'); }
int ft_isspace(int c) { return ((c == ' ') || ('\t' <= c && c <= '\r')); }
int ft_iscntrl(int c) { return ((0 <= c && c < ' ') || (c == 127)); }
int ft_isupper(int c) { return ('A' <= c && c <= 'Z'); }
int ft_ispunct(int c)
{
	return ((' ' < c && c < '0') || ('9' < c && c < 'A') || ('Z' < c && c < 'a') ||
	        ('z' < c && c <= '~'));
}

int ft_isalpha(int c) { return (ft_islower(c) || ft_isupper(c)); }
int ft_isalnum(int c) { return (ft_isalpha(c) || ft_isdigit(c)); }
int ft_isxdigit(int c)
{
	return (ft_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'));
}

int ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c | ('A' ^ 'a'));
	else
		return (c);
}

int ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	else
		return (c);
}
