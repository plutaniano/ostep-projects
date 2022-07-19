#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL)
        {
            printf("wunzip: cannot read file\n");
            exit(EXIT_FAILURE);
        }
        int count;
        char ch;
        while (1)
        {
            fread(&count, sizeof(count), 1, fp);
            fread(&ch, sizeof(ch), 1, fp);
            if (feof(fp))
            {
                break;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    printf("%c", ch);
                }
            }
        }
    }
}