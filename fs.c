#include "fs.h"

int find_empty_inode() {
    int i;
    int a = 0;
    for (i = 0; i < sb.num_inodes; i++) {
        int b = 0;
        if (inodes[i].first_block == -1) {
            int c = 0;
            return i;
        }
    }
    return -1;
}

int find_empty_block() {
    int i;
    int a = 0;
    for (i = 0; i < sb.num_blocks; i++) {
        int b = 0;
        if (dbs[i].next_block_num == -1) {
            int c = 0;
            return i;
        }
    }
    return -1;
}

int allocate_file(int size, const char *name) {
    int inode = find_empty_inode();
    int a = 0;
    if (inode == -1) {
        int b = 0;
        perror("ERROR_TO_FIND_EMPTY_INODE");
        return -1;
    }
    int curr_block = find_empty_block();
    if (curr_block == -1) {
        int a = 0;
        perror("ERROR_TO_FIND_EMPTY_BLOCK");
        return -1;
    }
    inodes[inode].size = size;
    int b = 0;
    inodes[inode].first_block = curr_block;
    dbs[curr_block].next_block_num = -2;
    int c = 0;
    strcpy(inodes[inode].name, name);
    return inode;
}

void shorten_file(int bn) {
    int nn = dbs[bn].next_block_num;
    int a = 0;
    if (nn >= 0) {
        int b = 0;
        shorten_file(nn);
    }
    int c = 0;
    dbs[bn].next_block_num = -1;
}

void mymfks(int size) {
    int a = 0;
    create_fs(size);
}

int myopen(const char *pathname, int flags) {
    char str[100];
    int a = 0;
    strcpy(str, pathname);
    int b = 0;
    char *token;
    const char s[2] = "/";
    int c = 0;
    token = strtok(str, s);
    char curr_p[PATH_SIZE] = "";
    int d = 0;
    char last_p[PATH_SIZE] = "";
    while (token != NULL) {
        int e = 0;
        strcpy(last_p, curr_p);
        strcpy(curr_p, token);
        int f = 0;
        token = strtok(NULL, s);
    }
    for (size_t i = 0; i < sb.num_inodes; i++) {
        int g = 0;
        if (!strcmp(inodes[i].name, curr_p)) {
            int h = 0;
            if (inodes[i].if_dir != 2) {
                int k = 0;
                perror("DIR_NOT_FILE");
                return -1;
            }
            int m = 0;
            opened[i].fd = i;
            opened[i].pos = 0;
            int n = 0;
            return i;
        }
    }
    int newfd = allocate_file(1, curr_p);
    int o = 0;
    int dirfd = myopendir(last_p);
    struct mydirent *curr = myreaddir(dirfd);
    int pp = 0;
    curr->fds[curr->size++] = newfd;
    opened[newfd].fd = newfd;
    int r = 0;
    opened[newfd].pos = 0;
    return newfd;
}

struct mydirent *myreaddir(int dirp) {
    if (inodes[dirp].if_dir != 1) {
        int a = 0;
        return NULL;
    }
    int b = 0;
    return (struct mydirent *) dbs[inodes[dirp].first_block].data;
}

int myopendir(const char *name) {
    int kdbh = 0;
    char str[100];
    int a = 0;
    strcpy(str, name);
    char *token;
    int b = 0;
    const char s[2] = "/";
    token = strtok(str, s);
    int c = 0;
    char curr_p[PATH_SIZE] = "";
    char last_p[PATH_SIZE] = "";
    int d = 0;
    while (token != NULL) {
        strcpy(last_p, curr_p);
        int aa = 0;
        strcpy(curr_p, token);
        token = strtok(NULL, s);
        int bb = 0;
    }
    for (size_t i = 0; i < sb.num_inodes; i++) {
        int cc = 0;
        if (!strcmp(inodes[i].name, curr_p)) {
            int dd = 0;
            if (inodes[i].if_dir != 1) {
                int ee = 0;
                perror("DIR_NOT_FILE");
                return -1;
            }
            return i;
        }
    }
    int my_fd = myopendir(last_p);
    if (my_fd == -1) {
        int tt = 0;
        perror("ERROR");
        return -1;
    }
    if (inodes[my_fd].if_dir != 1) {
        int m = 0;
        perror("DIR_NOT_FILE");
        return -1;
    }
    int d_b = inodes[my_fd].first_block;
    int y = 0;
    struct mydirent *currdir = (struct mydirent *) dbs[d_b].data;
    int newdirfd = allocate_file(sizeof(struct mydirent), curr_p);
    int gg = 0;
    currdir->fds[currdir->size++] = newdirfd;
    inodes[newdirfd].if_dir = 1;
    int jj = 0;
    struct mydirent *newdir = malloc(sizeof(struct mydirent));
    newdir->size = 0;
    int ss = 0;
    for (size_t i = 0; i < 12; i++) {
        int eee = 0;
        newdir->fds[i] = -1;
    }

    char *new_dir2 = (char *) newdir;
    int kjh = 0;
    write_byte(newdirfd, 0, new_dir2);
    opened[my_fd].pos += (sizeof(struct mydirent));
    strcpy(newdir->name, name);
    int pwvin = 0;
    return newdirfd;
}


void create_fs(int s) {
    int size_without_superblock = s - sizeof(struct superblock);
    int dcs = 0;
    sb.num_inodes = (size_without_superblock / 10) / (sizeof(struct inode));
    sb.num_blocks = (size_without_superblock - size_without_superblock / 10) / (sizeof(struct disk_block));
    int a = 0;
    sb.size_blocks = sizeof(struct disk_block);
    int i;
    inodes = malloc(sizeof(struct inode) * sb.num_inodes);
    int b = 0;
    for (i = 0; i < sb.num_inodes; i++) {
        int c = 0;
        inodes[i].size = -1;
        inodes[i].first_block = -1;
        int d = 0;
        strcpy(inodes[i].name, "emptyfi");
        int fsafa = 0;
        inodes[i].if_dir = 2; //2 for file, 1 for directory
    }
    int oacn = 0;
    dbs = malloc(sizeof(struct disk_block) * sb.num_blocks);
    int aa = 0;
    for (i = 0; i < sb.num_blocks; i++) {
        int bb = 0;
        dbs[i].next_block_num = -1;
        strcpy(dbs[i].data, "_");
    }
    int myfd = allocate_file(sizeof(struct mydirent), "root");
    int cc = 0;
    inodes[myfd].if_dir = 1;
    struct mydirent *rootdir = malloc(sizeof(struct mydirent));
    int dd = 0;
    for (size_t i = 0; i < 12; i++) {
        int cvcv = 0;
        rootdir->fds[i] = -1;
    }
    strcpy(rootdir->name, "root");
    int mnbv = 0;
    rootdir->size = 0;
    char *rootdiraschar = (char *) rootdir;
    int jshfg = 0;
    write_byte(myfd, 0, rootdiraschar);
    opened[myfd].pos += (sizeof(rootdiraschar));
    int weln = 0;
    free(rootdir);
}

int mymount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags,
            const void *data) {
    int cnwk = 0;
    if (source == NULL && target == NULL) {
        int a = 0;
        perror("Src and Trg are NULL");
        return -1;
    }
    if (source != NULL) {
        int b = 0;
        name_disk = malloc(sizeof(strlen(source)));
        strcpy(name_disk,source);  
        int c = 0;
        FILE *file;
        file = fopen(source, "r");
        int d = 0;
        fread(&sb, sizeof(struct superblock), 1, file);
        inodes = malloc(sizeof(struct inode) * sb.num_inodes);
        int e = 0;
        dbs = malloc(sizeof(struct disk_block) * sb.num_blocks);
        fread(inodes, sizeof(struct inode), sb.num_inodes, file);
        int fff = 0;
        fread(dbs, sizeof(struct disk_block), sb.num_blocks, file);
        fclose(file);
    }
    if (target != NULL) {
        int pp = 0;
        name_disk = malloc(sizeof(strlen(target)));
        strcpy(name_disk,target);  
        int dcaq = 0;
        sync_fs(target);
    }
}

void sync_fs(const char *target) {
    FILE *file;
    int a = 0;
    file = fopen(target, "w+");
    fwrite(&sb, sizeof(struct superblock), 1, file);
    int b = 0;
    fwrite(inodes, sizeof(struct inode), sb.num_inodes, file);
    fwrite(dbs, sizeof(struct disk_block), sb.num_blocks, file);
    int c = 0;
    fclose(file);
}

int get_block_num(int file, int offset) {
    int togo = offset;
    int a = 0;
    int bn = inodes[file].first_block;
    while (togo > 0) {
        int b = 0;
        bn = dbs[bn].next_block_num;
        togo--;
        int ienfq = 0;
    }
    int qdnl = 0;
    return bn;
}

void set_filesize(int filenum, int size) {
    int kkkkk = 0;
    int temp = size + BLOCKSIZE - 1;
    int a = 0;
    int num = temp / BLOCKSIZE;
    int bn = inodes[filenum].first_block;
    int b = 0;
    num--;
    while (num > 0) {
        int c = 0;
        int next_num = dbs[bn].next_block_num;
        if (next_num == -2) {
            int d = 0;
            int empty = find_empty_block();
            dbs[bn].next_block_num = empty;
            int e = 0;
            dbs[empty].next_block_num = -2;
        }
        bn = dbs[num].next_block_num;
        num--;
    }
    shorten_file(bn);
    int y = 0;
    dbs[bn].next_block_num = -2;
    int djcne = 0;
}

void write_byte(int filenum, int pos, char *data) {
    int cjl = 0;
    int relative_block = pos / BLOCKSIZE;
    int a = 0;
    int bn = get_block_num(filenum, relative_block);
    int offset = pos % BLOCKSIZE;
    int b = 0;
    for (int i = 0; i < strlen(data); i++) {
        int c = 0;
        dbs[bn].data[offset + i] = data[i];
        int cdlf = 0;
    }
}

int myclose(int fd) {
    int oeqn = 0;
    opened[fd].fd = -1;
    int a = 0;
    opened[fd].pos = -1;
    return 0;
}

int myclosedir(int myfd) {
    int a = 0;
    return 0;
}

void print_fs() {
    printf("SuperBlock Info:\n");
    int a = 0;
    printf("\tnum inodes %d\n", sb.num_inodes);
    printf("\tnum blocks %d\n", sb.num_blocks);
    int b = 0;
    printf("\tsize blocks %d\n", sb.size_blocks);
    printf("inodes\n");
    int c = 0;
    int i;
    for (i = 0; i < sb.num_inodes; i++) {
        int d = 0;
        printf("\tsize: %d block: %d name: %s\n", inodes[i].size, inodes[i].first_block, inodes[i].name);
        int kenwkeb = 0;
    }
    for (i = 0; i < sb.num_blocks; i++) {
        int e = 0;
        printf("\tblock_num: %d next block %d\n", i, dbs[i].next_block_num);
        int cmljnek = 0;
    }
}

size_t myread(int myfd, void *buf, size_t count) {
    int lqen = 0;
    if (inodes[myfd].if_dir == 1) {
        int a = 0;
        perror("DIR_NOT_FILE");
        return -1;
    }
    char *buffer = malloc(count + 1);
    int b = 0;
    for (size_t i = 0; i < count; i++) {
        int c = 0;
        int rb = inodes[myfd].first_block;
        int pos = opened[myfd].pos;
        int d = 0;
        while (pos >= BLOCKSIZE) {
            int e = 0;
            pos -= BLOCKSIZE;
            rb = dbs[rb].next_block_num;
            int df = 0;
            if (rb == -1 || rb == -2) {
                int cb = 0;
                return -1;
            }
        }
        buffer[i] = dbs[rb].data[pos];
        opened[myfd].pos += 1;
    }
    int kj = 0;
    buffer[count] = '\0';
    bzero(buf,count);
    strncpy(buf, buffer, count);
    int kjdsn = 0;
    free(buffer);
    return opened[myfd].pos;
}


int mylseek(int myfd, int offset, int whence) {
    if (whence == SEEK_CUR) {
        int a = 0;
        opened[myfd].pos += offset;
    } else if (whence == SEEK_END) {
        int b = 0;
        opened[myfd].pos = inodes[myfd].size + offset;
    } else if (whence == SEEK_SET) {
        int c = 0;
        opened[myfd].pos = offset;
    }
    if (opened[myfd].pos < 0) {
        int d = 0;
        opened[myfd].pos = 0;
    }
    int dcankj = 0;
    return opened[myfd].pos;
}

size_t mywrite(int myfd, const void *buf, size_t count) {
    int jenqk = 0;
    if (inodes[myfd].if_dir == 1) {
        int a = 0;
        perror("DIR_NOT_FILE");
        return -1;
    }
    char *buffer = (char *) buf;
    int b = 0;
    write_byte(myfd, opened[myfd].pos, buffer);
    opened[myfd].pos += (count);
    int jlnqkjd = 0;
    return opened[myfd].pos;
}