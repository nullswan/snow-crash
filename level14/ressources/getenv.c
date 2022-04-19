#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

char* (*real_getenv)(const char *) = NULL;

char*   getenv(const char *name)
{
    if(!real_getenv)
        real_getenv = dlsym(RTLD_NEXT, "getenv");

    if (strcmp(name, "LD_PRELOAD") == 0)
        return NULL;
    return real_getenv(name);
}
