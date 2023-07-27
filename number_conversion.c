#include <stdlib.h>
#include "monty.h"



unsigned int _abs(int);
int get_numberbase_len(unsigned int number, unsigned int base);
void fill_numberbase_buff(unsigned int number, unsigned int base,
char *buff, int buff_size);


/**
* convert_int_to_string - gets a character pointer to new string containing int
* @number: numberber to convert to string
*
* Return: character pointer to newly created string. NULL if malloc fails.
*/
char *convert_int_to_string(int number)
{
unsigned int temp;
int length = 0;
long number_l = 0;
char *ret;


temp = _abs(number);
length = get_numberbase_len(temp, 10);


if (number < 0 || number_l < 0)
length++; /* negative sign */
ret = malloc(length + 1); /* create new string */
if (!ret)
return (NULL);


fill_numberbase_buff(temp, 10, ret, length);
if (number < 0 || number_l < 0)
ret[0] = '-';


return (ret);
}

/**
* _abs - gets the absolute value of an integer
* @i: integer to get absolute value of
*
* Return: unsigned integer abs rep of i
*/
unsigned int _abs(int i)
{
if (i < 0)
return (-(unsigned int)i);
return ((unsigned int)i);
}


/**
* get_numberbase_len - gets length of buffer needed for an unsigned int
* @number: numberber to get length needed for
* @base: base of numberber representation used by buffer
*
* Return: integer containing length of buffer needed (doesn't contain null bt)
*/
int get_numberbase_len(unsigned int number, unsigned int base)
{
int len = 1; /* all numberbers contain atleast one digit */


while (number > base - 1)
{
len++;
number /= base;
}
return (len);
}


/**
* fill_numberbase_buff - fills buffer with correct numberbers up to base 36
* @number: numberber to convert to string given base
* @base: base of numberber used in conversion, only works up to base 36
* @buff: buffer to fill with result of conversion
* @buff_size: size of buffer in bytes
*
* Return: always void.
*/
void fill_numberbase_buff(unsigned int number, unsigned int base,
char *buff, int buff_size)
{
int rem, i = buff_size - 1;


buff[buff_size] = '\0';
while (i >= 0)
{
rem = number % base;
if (rem > 9) /* return lowercase ascii val representation */
buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
else
buff[i] = rem + '0';
number /= base;
i--;
}
}
