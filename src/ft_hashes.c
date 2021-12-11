#include "ft_hashes.h"

size_t fnv1a_32(char* string, size_t length)
{
	uint32_t hash, c;

	hash = 2166136261;
	while (length-- > 0)
	{
		c = (unsigned char)*string++;
		hash ^= c;
		hash *= 16777619;
	}
	return (size_t)hash;
}

size_t fnv1a_64(char* string, size_t length)
{
	uint64_t hash, c;

	hash = 14695981039346656037UL;
	while (length-- > 0)
	{
		c = (unsigned char)*string++;
		hash ^= c;
		hash *= 1099511628211UL;
	}
	return hash;
}

size_t djb2a(char* string, size_t length)
{
	uint32_t hash, c;

	hash = 5381;
	while (length-- > 0)
	{
		c    = (unsigned char)*string++;
		hash = ((hash << 5) + hash) ^ c;
	}
	return (size_t)hash;
}

size_t djb2(char* string, size_t length)
{
	uint32_t hash, c;

	hash = 5381;
	while (length-- > 0)
	{
		c    = (unsigned char)*string++;
		hash = ((hash << 5) + hash) + c;
	}
	return (size_t)hash;
}

size_t sdbm(char* string, size_t length)
{
	size_t hash, c;

	hash = 0;
	while (length-- > 0)
	{
		c    = (unsigned char)*string++;
		hash = c + (hash << 6) + (hash << 16) - hash;
	}
	return hash;
}
