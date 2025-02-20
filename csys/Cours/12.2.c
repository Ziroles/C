#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd;
    fd = open(argv[1], O_RDONLY|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR|S_IRGRP);
    if(fd == -1) {
    perror("Open ");
    return errno;
    }
    return 0;
}