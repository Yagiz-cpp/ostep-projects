#include <stdio.h>
#include <stdlib.h>

void write_run(int count, int prev)
{
	fwrite(&count, sizeof(int),1, stdout);
	fputc(prev, stdout);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
	printf("wzip: file1 [file2 ...]\n");
	exit(1);
	}

	int prev=-1;
	int count=0;


	for( int i =1; i<argc; i++)
	{
		FILE *fp = fopen(argv[i], "r");

		if(fp==NULL)
		{
			printf("wzip: cannot open file\n");
			exit(1);
		}

		int c;
		while((c=fgetc(fp)) != EOF)
		{
			//printf("%c", c);
			if(count==0)//First element problem
			{
				prev =c;
			}
			if(c==prev)
			{
				count++;
			}
			else
			{
				write_run(count, prev);
				//printf("%d%c\n",count,prev);
				prev = c;
				count = 1;
			}
		}

		fclose(fp);
	}
	if(count !=0)
	{
		write_run(count, prev);
		//printf("%d%c",count,prev);
	}
	return 0;

}
