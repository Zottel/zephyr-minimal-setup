// Just a very minimal Hello World example.

#include <stdio.h>

int main(void)
{
	printf("Hello World! \n");
	printf("\n");
	printf("  CMAKE_PROJECT_NAME: %s\n", CMAKE_PROJECT_NAME);
	printf("  CONFIG_BOARD_TARGET: %s\n", CONFIG_BOARD_TARGET);
	printf("  ARCH: %s\n", ARCH);

	return 0;
}
