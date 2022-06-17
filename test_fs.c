#include "fs.h"

void Failed_test() {
    int a=0;
    printf("Test Failed! :(\n");
}

void Good_Test() {
    int b=0;
    printf("Test Passed! :)\n");
}

int main(int argc, char const *argv[]) {
    int a =0;
    mymfks(10000);
    int t1 = myopendir("root/ohad");
    int b=0;
    int t2 = myopendir("root/dvir");
    if (t1 == t2) {
        int c=0;
        Failed_test();
    } else {
        int d=0;
        Good_Test();
    }

    int fd1 = myopen("root/ohad/o1", 0);
    int aa=0;
    int fd2 = myopen("root/ohad/o1", 0);

    if (fd1 == fd2) {
        int bb=0;
        Good_Test();
    } else {
        int cc=0;
        Failed_test();
    }
    int fd3 = myopen("root/dvir/d1", 0);
    if (fd1 == fd3) {
        int aaa=0;
        Failed_test();
    } else {
        int q =0;
        Good_Test();
    }

    fd1 = myclose(fd1);
    int r =0;
    if (fd1 == fd2) {
        int t=0;
        Failed_test();
    } else {
        int y=0;
        Good_Test();
    }
    int g=0;
    char *test1 = " ohad_test";

    int ptr2 = mywrite(fd2, test1, 12);
    char ohad_buf[12];
    int fs=0;
    mylseek(fd2, -13, SEEK_CUR);
    myread(fd2, ohad_buf, 12);
    int vfs=0;
    if (strcmp(ohad_buf, "ohad_test") == 0) {
        int dsv=0;
        Good_Test();
    } else {
        int pijo=0;
        Failed_test();
    }

    int rsf=0;
    char *test2 = "dvir_test";

    int ptr = mywrite(fd3, test2, 12);
    char dvir_buf[12];
    int wrbe=0;
    mylseek(fd3, 0, SEEK_SET);
    myread(fd2, dvir_buf, 12);
    int njl=0;
    if (strcmp(ohad_buf, dvir_buf) == 0) {
        int odnca=0;
        Failed_test();
    } else {
        int oefnqw=0;
        Good_Test();
    }
    int owfn=0;
    char *ohad_buf2 = malloc(4);
    mylseek(fd2, -9, SEEK_END);
    int lefqmn=0;
    myread(fd2, ohad_buf2, 4);

    if (strcmp(ohad_buf, ohad_buf2) == 0) {
        int ofeqn=0;
        Failed_test();
    } else {
        int orwn=0;
        Good_Test();
    }

    if (strcmp("ohad", ohad_buf2) == 0) {
        int rwonsa=0;
        Good_Test();
    } else {
        int lvsn=0;
        Failed_test();
    }

    mymount(NULL, "fs_data", NULL, 0, NULL);
    int wfejn=0;
    return 0;
}