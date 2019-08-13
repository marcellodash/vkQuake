/*

vkQuake launcher

*/
#include <platform.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int Utl_FindBaseDir(const char* path, char* buf, size_t buflen)
{
	size_t len = strlen(path);
	for(int i = len; i >= 0; i--)
	{
		if(path[i] == '\0')
		{
			size_t nbuflen = strlen((path+i));
			if(nbuflen > buflen)
				return -1;
			strcpy(buf, (path+i+1));
			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	printf("Starting vkQuake...\n");
	char path[512];
	printf("cwd: %s\n", argv[0]);
	memset(path, 0, 512);
	int status = Utl_FindBaseDir(argv[0], path, 512);
	if(status)
	{
		printf("Unable to find base dir, please specify it with -basedir\n");
		exit(1);
	}
	printf("Game base directory: %s\n", path);

	HANDLE engine = Plat_LoadLibrary("engine.so");

	if(!engine)
	{
		printf("Unable to load the engine.\n");
	}
}
