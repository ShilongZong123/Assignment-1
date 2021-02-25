#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/types.h>

asmlinkage int sys_shilong(char* str)
{
	int n = strnlen(str, 128+1);

	if (n > 128)
	{
		return -1;
	}

	int counter = 0;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (str[i] == 'x')
		{
			str[i] = 'y';
			counter += 1;
		}
	}

	return counter;
}
