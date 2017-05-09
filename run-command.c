#include <windows.h>
#include <stdio.h>
#include<string.h>

BOOL CreateShortcut(char *ptchExecutableFileName, char *ptchShortcutName)
{
    BOOL Res = TRUE;
    FILE *fp;

    if(NULL == (fp = fopen(ptchExecutableFileName, "r")))
    {
        printf("\nCan`t find executable file!\n");
        return FALSE;
    }
    fclose(fp);

    Res &= WritePrivateProfileString("InternetShortcut",
               "URL", ptchExecutableFileName, ptchShortcutName);
    Res &= WritePrivateProfileString("InternetShortcut",
               "IconIndex", "0", ptchShortcutName);
    Res &= WritePrivateProfileString("InternetShortcut",
               "IconFile", ptchExecutableFileName, ptchShortcutName);

    return Res;
}

int main()
{
    char mF[1000],nF[1000],name[]=".url",path[1000]="C:\\Windows\\";
    printf("Main location: ");
    gets(mF);
    printf("Short name: ");
    gets(nF);
    strcat(path,nF);
    strcat(path,name);
    CreateShortcut(mF,path);
}
