#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int		x = atoi(argv[1]);

	printf("x = %d\n", x);
    printf("there are %d args\n", argc);
    for (int i = 0; i < argc; i++)
        printf("%d: \"%s\"\n", i, argv[i]);
    
    return 0;
}
