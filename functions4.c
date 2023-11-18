#include "myshell.h"

/**
 * my_realloc - reallocates a memory block
 * @ptr: pointer to the memory block
 * @size: size of the memory block
 * Return: void
 */
void *my_realloc(void *ptr, size_t size)
{
void *new_p;
size_t old_size, copying_size, i;
if (ptr == NULL)
{
return (malloc(size));
}
if (size == 0)
{
free(ptr);
return (NULL);
}
new_p = malloc(size);
if (new_p == NULL)
{
return (NULL);
}
old_size = usable_size(ptr);
copying_size = (old_size < size) ? old_size : size;
for (i = 0; i < copying_size; ++i)
{
((char *)new_p)[i] = ((char *)ptr)[i];
}
free(ptr);
return (new_p);
}

/**
 * usable_size - returns the size of a memory block
 * @ptr: pointer to the memory block
 * Return: size of the memory block
 */
size_t usable_size(const void *ptr)
{
size_t *size = (size_t *)ptr - 1;
return (*size);
}
