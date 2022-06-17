#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BLOCKSIZE 512
#define PATH_SIZE 12

struct mydirent {
    int size;
    int fds[12];
    char name[PATH_SIZE];
};

struct inode {
    int size;
    int first_block;
    int if_dir;
    char name[8];
};

struct superblock {
    int num_inodes;
    int num_blocks;
    int size_blocks;
};


struct open_file {
    int fd;
    int pos;
};

struct disk_block {
    int next_block_num;
    char data[BLOCKSIZE];
};



int myclose(int fd);
void set_filesize(int filenum, int size);
int mymount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);
int myopendir(const char *name);
void create_fs(int s);
int allocate_file(int size, const char *name);
void sync_fs(const char* target);
size_t myread(int myfd, void *buf, size_t count);
struct superblock sb;
void write_byte(int filenum,int pos, char* data);
int get_block_num(int file, int offset);
void shorten_file(int bn);
void print_fs();
size_t mywrite(int myfd, const void *buf, size_t count);
struct open_file opened[12];
char* name_disk;
int myopen(const char *pathname, int flags);
int mylseek(int myfd, int offset, int whence);
void mymfks(int size);
int myclosedir(int myfd);
struct mydirent *myreaddir(int dirp);
struct inode *inodes;
struct disk_block *dbs;
