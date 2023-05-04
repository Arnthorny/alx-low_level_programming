#include "main.h"

/**
  * flip_bits - Returns number of bit to flip to get from n to m.
  * @n: First Number.
  * @m: Flip to this number.
  * Return: Number of bits to be flipped.
  */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	short int tmp;
	unsigned long int xorD = n ^ m;

	while (xorD)
	{
		tmp = xorD & 1;
		if (tmp)
			count++;
		xorD >>= 1;
	}

	return (count);
}
