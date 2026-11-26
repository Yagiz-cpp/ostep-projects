#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void grep_file(FILE *fp, char *looking)
{
	char *line = NULL;
	size_t cap = 0;
	while(getline(&line, &cap, fp) != -1)
	{
		if(strstr(line, looking))
		{
			printf("%s", line);
		}
	}
	free(line);
}

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}

	if (argc < 3)
	{
		grep_file(stdin, argv[1]);
		return 0;
	}
	for (int i = 2; i < argc; i++)
	{
		FILE *fp = fopen(argv[i], "r");
		if (fp==NULL)
		{
			printf("wgrep: cannot open file\n");
			exit(1);
		}
		grep_file(fp, argv[1]);
		fclose(fp);
	}
	return 0;

}


