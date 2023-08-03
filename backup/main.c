#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main(void)
{
	void *gg;
	int num = 0;
	unsigned long long ptr;

	ptr = (unsigned long long)&gg;

	//TEST(5, print(" %.s ", "-"));
	//TEST(8, print(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
	//TEST(9, print(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
	num = ft_printf(" %.s ", "-");
	printf(":end");
	printf("\n%d\n", num);

	num = printf(" %.s ", "-");
	printf(":endO");
	printf("\n%d\n", num);

	num = ft_printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", "");
	printf(":end");
	printf("\n%d\n", num);

	num = printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", "");
	printf(":endO");
	printf("\n%d\n", num);

	num = ft_printf(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 ");
	printf(":end");
	printf("\n%d\n", num);

	num = printf(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 ");
	printf(":endO");
	printf("\n%d\n", num);

	num = printf("%.5s", "-");
	printf("\n%d\n", num);
	return (0);
}