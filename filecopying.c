#include<stdio.h>
#include<conio.h>
int main()
{
    char ch, name_file1[20], name_file2[20];
    FILE *fs, *ft;
    printf("Enter Source File Name (with extension): ");
    gets(name_file1);
    fs = fopen(name_file1, "r");
    if(fs == NULL)
    {
        printf("\nError in Opening the file, %s", name_file1);
        getch();
        return 0;
    }
    printf("Enter Target File Name (with extension): ");
    gets(name_file2);
    ft = fopen(name_file2, "w");
    if(ft == NULL)
    {
        printf("\nError in Opening the file, %s", name_file2);
        getch();
        return 0;
    }
    ch = fgetc(fs);
    while(ch != EOF)
    {
        fputc(ch, ft);
        ch = fgetc(fs);
    }
    printf("\nFile copied successfully.");
    fclose(fs);
    fclose(ft);
    getch();
    return 0;
}