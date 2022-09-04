#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
    int fd1, fd2, fd3;
    fd1 = socket(PF_INET, SOCK_STREAM, 0);
    fd2 = open("test.dat", O_CREAT | O_WRONLY | O_TRUNC);
    fd3 = socket(PF_INET, SOCK_DGRAM, 0);

    // fd가 3부터 출력되는 이유 : 표준 입력/출력/에러가 0,1,2 로 먼저 할당되기 때문
    printf("fd1: %d\n", fd1);
    printf("fd2: %d\n", fd2);
    printf("fd3: %d\n", fd3);

    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}