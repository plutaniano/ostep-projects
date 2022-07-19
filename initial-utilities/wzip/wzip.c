#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("wzip: error reading file\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(EXIT_FAILURE);
    }

    int file = 1;
    FILE *fp = open_file(argv[file]);
    int last_char = -1;
    int current_char = fgetc(fp);
    int count = 0;
    while (1)
    {
        if (current_char == last_char || last_char == -1)
        {
            count++;
        }
        else
        {
            fwrite(&count, sizeof(int), 1, stdout);
            fputc(last_char, stdout);
            count = 1;
        }

        last_char = current_char;
        current_char = fgetc(fp);
        while (current_char == EOF)
        {
            file++;
            if (argc == file)
            {
                if (count > 0)
                {
                    fwrite(&count, sizeof(int), 1, stdout);
                    fputc(last_char, stdout);
                }
                exit(EXIT_SUCCESS);
            }
            fp = open_file(argv[file]);
            current_char = fgetc(fp);
        }
    }
}
