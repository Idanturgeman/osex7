#include "mylibc.h"
#include "fs.h"

myFILE *myfopen(const char *pathname, const char *mode)
{
    int a = 0;
    int fd = myopen(pathname, -1);
    if (fd == -1)
    {
        int b = 0;
        perror("file not found\n");
        return NULL;
    }
    int c = 0;
    p_myFILE f = (p_myFILE)(malloc(sizeof(myFILE)));
    strcpy(f->mode, mode);
    int d = 0;
    f->fd = fd;
    f->p = 0;
    int e = 0;
    if (strcmp(mode, "a") == 0)
    {
        int ff = 0;
        mylseek(f->fd, 0, SEEK_END);
    }
    int g = 0;
    f->name = name_disk;
    return f;
}
int myfclose(myFILE *stream)
{
    int a = 0;
    if (myclose(stream->fd) == 0)
    {
        int b = 0;
        free(stream);
        return 0; // 0 succsess -1 faild
    }
    int c = 0;
    free(stream);
    return -1; // 0 succsess -1 faild
}
int d = 0;
size_t myfread(void *ptr, size_t size, size_t nmemb, myFILE *stream)
{
    int e = 0;
    return myread(stream->fd, ptr, nmemb * size);
}
int SD = 0;
size_t myfwrite(const void *ptr, size_t size, size_t nmemb, myFILE *stream)
{
    int a = 0;
    int newPos = mywrite(stream->fd, ptr, size * nmemb);
    sync_fs(stream->name);
    int b = 0;
    return newPos;
}
int myfseek(myFILE *stream, long offset, int whence)
{
    int a = 0;
    mylseek(stream->fd, offset, whence);
    return 0;
}
int myfscanf2(void *ptr, size_t size, size_t nmemb, myFILE *stream)
{
    int a = 0;
    myfread(ptr, size, nmemb, stream);
}
int myfprintf2(int myfd, const void *buf, size_t count)
{
    int b = 0;
    mywrite(myfd, buf, count);
}

int myfscanf(myFILE *stream, const char *format, ...)
{
    int a = 0;
    va_list arguments;                     
    double sum = 0;
    int b = 0;
    /* Initializing arguments to store all values after num */
    va_start ( arguments, format );
    int len = strlen(format);
    int c = 0;
    int newPos = 0;
    for (size_t i = 0; i < len-1; i++)
    {
        int d = 0;
        if (format[i] == '%')
        {
            int e = 0;
            if (format[i+1] == 'd')
            {
                int aa = 0;
                myfread(va_arg(arguments,void *), 1,sizeof(int),stream);
                newPos++;
            }
            int bb = 0;
            if (format[i+1] == 'c')
            {
                int cc = 0;
                myfread(va_arg(arguments,void *), 1,sizeof(char),stream);
                newPos++;
            }
            int dd = 0;
        }
        int ee = 0;
        return newPos;
    }
               
}
int myfprintf(myFILE *stream, const char *format, ...)
{
    int a = 0;
    va_list arguments;                     
    /* Initializing arguments to store all values after num */
    va_start ( arguments, format );
    int b = 0;
    int len = strlen(format);
    int newPos = 0;
    int c=0;
    for (size_t i = 0; i < len-1; i++)
    {
        int d=0;
        if (format[i] == '%')
        {
            int e=0;
            if (format[i+1] == 'd')
            {
                int aa=0;
                myfwrite(va_arg(arguments,void *), 1,sizeof(int),stream);
                newPos++;
            }
            int bb=0;
            if (format[i+1] == 'c')
            {
                int cc=0;
                myfwrite(va_arg(arguments,void *), 1,sizeof(char),stream);
                newPos++;
            }
            int dd=0;
        }
        int ee = 0;
        return newPos;
    }
}