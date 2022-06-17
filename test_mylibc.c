#include "mylibc.h"

void Failed_test()
{
    int a=0;
    printf("bad test\n");
}

void Good_Test()
{
    int a=0;
    printf("good test\n");
}

int main(int argc, char const *argv[])
{
    int a=0;
    mymount("fs", NULL, NULL, 0, NULL);

    p_myFILE file_ptr1 = myfopen("root/idan/d1", "r");
    // printf("fd: %d, %s\n" ,file_ptr1->fd,file_ptr1->mode);
    int b=0;
    char buf1[4];
    myfread(buf1, 1, 4, file_ptr1);
    int c=0;
    // printf("buf1 : %s\n", buf1);
    if (strncmp("idan", buf1, 4) == 0)
    {
        int d=0;
        Good_Test();
    }
    else{
        int aa=0;
        Failed_test();
    }
    myfclose(file_ptr1);
    int bb=0;
    file_ptr1 = myfopen("root/idan/d1", "w");
    // printf("fd: %d, %s\n" ,file_ptr1->fd,file_ptr1->mode);
    myfseek(file_ptr1, 0, SEEK_SET);
    int cc=0;
    char* test12 = "idan_turji";
    myfwrite(test12,1, strlen(test12), file_ptr1);
    int dd=0;
    myfclose(file_ptr1);
    file_ptr1 = myfopen("root/idan/d1", "r");
    int wr=0;
    char buf2[10];
    myfread(buf2, 1, strlen(test12), file_ptr1);
    int ajdln=0;
    // printf("buf2 : %s\n", buf2);
    if (strcmp("idan_turji",buf2) == 0)
    {
        int efjna=0;
        Good_Test();
    }
    else{
        int enfq=0;
        Failed_test();
    }
    myfclose(file_ptr1);
    int eibvh=0;
    return 0;
}

