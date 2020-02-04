#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int fileDesc = open("myFile.txt", O_RDONLY);
    if (fileDesc == -1)
    {
        fprintf(stderr, "Cannot open myFile.txt .. error: %d\n", fileDesc);
        fprintf(stderr, "errno code = %d\n", errno);
        fprintf(stderr, "errno meaningn = %s\n", strerror(errno));
        exit(1);
    }
}

