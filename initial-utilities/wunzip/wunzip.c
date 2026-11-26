#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}

	int count =0;
	char ch ;

	for(int i =1; i < argc; i++)
	{
		FILE *fp = fopen(argv[i], "r");

		if(fp==NULL)
		{
			printf("wunzip: canot open file\n");
			exit(1);
		}

		while(fread(&count, sizeof(int), 1, fp))
		{
			fread(&ch,1, 1, fp);
			for(int i =0; i<=count-1 ;i++)
			{
				printf("%c", ch);
			}
		}
		fclose(fp);
	 }
	return 0;
}
