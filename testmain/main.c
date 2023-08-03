#include <stdio.h>

int main(void)
{
	int num;
	unsigned long long ptr;

	ptr = (unsigned long long)&num;
	num = 0;
	printf("%-+3.4dG\n", num);
	printf("%#05xG\n", num + 1);
	printf("%0 .dG\n",num);
	printf("%dG\n",num);
	printf("%dG\n",num);
	printf("%dG\n",num);

	/*num = printf("%0pG\n", &num);
	printf("%d\n", num);

	num = printf("%#.3xG\n", -0x0);
	printf("%d\n", num);*/

	/*num = 123;
	printf("%x\n", 23131561);
	printf("%0+50d\n", 1);
	printf("%0#10.20x", 1);
	//(0#)(10)(.)(20)(x)
	printf("%0+50d\n", 1);
	num = printf("");
	printf("%d\n", num);
	printf("%c\n", CS[8]);
	printf("%8.6d끝\n", 1234);
	printf("%p끝\n", &num);
	printf("%#llx끝\n", ptr);*/

	/*printf("-----------------\n");
	printf("(1)%d끝\n", 1234);
	printf("(2)%8d끝\n", 1234);
	printf("(3)%+8d끝\n", 1234);
	printf("(4)%+8d끝\n", -1234);
	printf("(5)% 8d끝\n", -1234);
	printf("(6)% -8d끝\n", -1234);
	printf("(7)%-8d끝\n", 1234);
	printf("(8)% -8d끝\n", 1234);
	printf("(9)%08dend\n", 1234);
	printf("(10)% 08d끝\n", 1234);

	printf("-----------------\n");
	printf("%8.6d끝\n", 1234);
	printf("% 6.6d끝\n", 1234);
	printf("% 7.6d끝\n", 1234);
	printf("%-8.6d끝\n", 1234);
	printf("%+8.6d끝\n", 1234);
	printf("%8.3d끝\n", 1234);
	printf("%3.3d끝\n", 1234);
	printf("%08.6d끝\n", 1234);	 //컴파일 오류

	printf("%d\n", ft_atoi("123d"));*/
	return 0;
}
