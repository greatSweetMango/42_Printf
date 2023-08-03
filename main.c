#include <stdio.h>
#include "./include/ft_printf.h"

int main(void)
{
	void *gg;
	int num = 0;
	unsigned long long ptr;

	ptr = (unsigned long long)&gg;

	num = ft_printf(" %c %c %c ", '2', '1', 0);
	printf("%d\n", num);

	num = printf(" %c %c %c ", '2', '1', 0);
	printf("%d\n", num);
	return (0);
}