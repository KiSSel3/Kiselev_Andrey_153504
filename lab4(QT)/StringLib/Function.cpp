#include "function.h"

void* memcpy(void* s1, const void* s2, size_t n) {
    char* csrc = (char*)s2;
    char* cdest = (char*)s1;

    for (size_t i = 0; i < n; i++)
        cdest[i] = csrc[i];
}

void* memmove(void* s1, const void* s2, size_t n) {
    char* csrc = (char*)s2;
    char* cdest = (char*)s1;

    char* temp = new char[n];

    for (size_t i = 0; i < n; i++)
        temp[i] = csrc[i];

    for (size_t i = 0; i < n; i++)
        cdest[i] = temp[i];

    delete[] temp;
}

char* strcpy(char* s1, const char* s2) {
    if (s1 == NULL) {
        return NULL;
    }
    char* ptr = s1;

    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';
    return ptr;
}

char* strncpy(char* s1, const char* s2, size_t n) {
    if (s1 == NULL) {
        return NULL;
    }

    char* ptr = s1;

    while (*s2 && n--) {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return ptr;
}

char* strcat(char* destination, const char* source) {
    char* ptr = destination + strlen(destination);

    while (*source != '\0') {
        *ptr++ = *source++;
    }

    *ptr = '\0';

    return destination;
}

char* strncat(char* destination, const char* source, size_t num) {
    char* ptr = destination + strlen(destination);

    while (*source != '\0' && num--) {
        *ptr++ = *source++;
    }

    *ptr = '\0';

    return destination;
}

int memcmp(const void* buf1, const void* buf2, size_t count) {
    if (!count)
        return(0);

    while (--count && *(char*)buf1 == *(char*)buf2) {
        buf1 = (char*)buf1 + 1;
        buf2 = (char*)buf2 + 1;
    }

    return(*((unsigned char*)buf1) - *((unsigned char*)buf2));
}

int strcmp(const char* X, const char* Y) {
    while (*X) {
        if (*X != *Y) {
            break;
        }

        X++;
        Y++;
    }

    return *(const unsigned char*)X - *(const unsigned char*)Y;
}

int strncmp(const char* s1, const char* s2, size_t n) {
    while (n && *s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0) {
        return 0;
    }
    else {
        return (*(unsigned char*)s1 - *(unsigned char*)s2);
    }
}

char* strtok(char* s, const char* d) {
    int i = 0;
    for (; s[i] != '\0'; i++) {
        int ii=0;
        for (; d[ii] != '\0'; ii++) {
        if (s[i] == d[ii])
            s[i] = '\n';
        }
    }
    return s;
}

void* memset(void* b, int c, size_t len) {
    bool a=0;
    unsigned char* p = (unsigned char* )b;

    while (len > 0) {
        if(*p=='\0') a=1;
        *p = c;
        p++;
        len--;
    }
    if(a){
        p--;
        *p='\0';
    }

    return(b);
}

size_t strlen(const char* str) {
    const char* s;
    for (s = str; *s; ++s);
    return (s - str);
}


int strcoll(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
    }

    if (*s1 == '\0' && *s2 == '\0') return 0;

    return (*(unsigned char*)s1 - *(unsigned char*)s2);
}


size_t strxfrm(char* s1, const char* s2, size_t n) {
    size_t buf = 0;
    if (s1 == NULL) {
        return NULL;
    }

    while (*s2 && n--) {
        *s1 = *s2;
        s1++;
        s2++;
        buf++;
    }

    *s1 = '\0';

    return buf;
}

char* strerror(int errnum) {
    char* a = new char[60];
    switch (errnum) {
    default: strcpy(a, "Undefined error: 0"); break;
    case 1: strcpy(a, "Operation not permitted"); break;
    case 2: strcpy(a, "No such file or directory"); break;
    case 3: strcpy(a, "No such process"); break;
    case 4: strcpy(a, "Interrupted system call"); break;
    case 5: strcpy(a, "Input/output error"); break;
    case 6: strcpy(a, "Device not configured"); break;
    case 7: strcpy(a, "Argument list too long"); break;
    case 8: strcpy(a, "Exec format error"); break;
    case 9: strcpy(a, "Bad file descriptor"); break;
    case 10: strcpy(a, "No child processes"); break;
    case 11: strcpy(a, "Resource deadlock avoided"); break;
    case 12: strcpy(a, "Cannot allocate memory"); break;
    case 13: strcpy(a, "Permission denied"); break;
    case 14: strcpy(a, "Bad address"); break;
    case 15: strcpy(a, "Block device required"); break;
    case 16: strcpy(a, "Device busy"); break;
    case 17: strcpy(a, "File exists"); break;
    case 18: strcpy(a, "Cross-device link"); break;
    case 19: strcpy(a, "Operation not supported by device"); break;
    case 20: strcpy(a, "Not a directory"); break;
    case 21: strcpy(a, "Is a directory"); break;
    case 22: strcpy(a, "Invalid argument"); break;
    case 23: strcpy(a, "Too many open files in system"); break;
    case 24: strcpy(a, "Too many open files"); break;
    case 25: strcpy(a, "Inappropriate ioctl for device"); break;
    case 26: strcpy(a, "Text file busy"); break;
    case 27: strcpy(a, "File too large"); break;
    case 28: strcpy(a, "No space left on device"); break;
    case 29: strcpy(a, "Illegal seek"); break;
    case 30: strcpy(a, "Read-only file system"); break;
    case 31: strcpy(a, "Too many links"); break;
    case 32: strcpy(a, "Broken pipe"); break;
    case 33: strcpy(a, "Numerical argument out of domain"); break;
    case 34: strcpy(a, "Result too large"); break;
    case 35: strcpy(a, "Resource temporarily unavailable"); break;
    case 36: strcpy(a, "Resource temporarily unavailable"); break;
    case 37: strcpy(a, "Operation now in progress"); break;
    case 38: strcpy(a, "Operation already in progress"); break;
    case 39: strcpy(a, "Socket operation on non-socket"); break;
    case 40: strcpy(a, "Destination address required"); break;
    case 41: strcpy(a, "Message too long"); break;
    case 42: strcpy(a, "Protocol wrong type for socket"); break;
    case 43: strcpy(a, "Protocol not available"); break;
    case 44: strcpy(a, "Protocol not supported"); break;
    case 45: strcpy(a, "Socket type not supported"); break;
    case 46: strcpy(a, "Operation not supported"); break;
    case 47: strcpy(a, "Protocol family not supported"); break;
    case 48: strcpy(a, "Address family not supported by protocol family"); break;
    case 49: strcpy(a, "Address already in use"); break;
    case 50: strcpy(a, "Can't assign requested address"); break;
    case 51: strcpy(a, "Network is down"); break;
    case 52: strcpy(a, "Network is unreachable"); break;
    case 53: strcpy(a, "Network dropped connection on reset"); break;
    case 54: strcpy(a, "Software caused connection abort"); break;
    case 55: strcpy(a, "Connection reset by peer"); break;
    case 56: strcpy(a, "No buffer space available"); break;
    case 57: strcpy(a, "Socket is already connected"); break;
    case 58: strcpy(a, "Socket is not connected"); break;
    case 59: strcpy(a, "Can't send after socket shutdown"); break;
    case 60: strcpy(a, "Too many references: can't splice"); break;
    case 61: strcpy(a, "Operation timed out"); break;
    case 62: strcpy(a, "Connection refused"); break;
    case 63: strcpy(a, "Too many levels of symbolic links"); break;
    case 64: strcpy(a, "File name too long"); break;
    case 65: strcpy(a, "Host is down"); break;
    case 66: strcpy(a, "No route to host"); break;
    case 67: strcpy(a, "Directory not empty"); break;
    case 68: strcpy(a, "Too many processes"); break;
    case 69: strcpy(a, "Too many users"); break;
    case 70: strcpy(a, "Disc quota exceeded"); break;
    case 71: strcpy(a, "Stale NFS file handle"); break;
    case 72: strcpy(a, "Too many levels of remote in path"); break;
    case 73: strcpy(a, "RPC struct is bad"); break;
    case 74: strcpy(a, "RPC version wrong"); break;
    case 75: strcpy(a, "RPC prog. not avail"); break;
    case 76: strcpy(a, "Program version wrong"); break;
    case 77: strcpy(a, "Bad procedure for program"); break;
    case 78: strcpy(a, "No locks available"); break;
    case 79: strcpy(a, "Function not implemented"); break;
    case 80: strcpy(a, "Inappropriate file type or format"); break;
    case 81: strcpy(a, "Authentication error"); break;
    case 82: strcpy(a, "Need authenticator"); break;
    case 83: strcpy(a, "Identifier removed"); break;
    case 84: strcpy(a, "No message of desired type"); break;
    case 85: strcpy(a, "Value too large to be stored in data type"); break;
    case 86: strcpy(a, "Operation canceled"); break;
    case 87: strcpy(a, "Illegal byte sequence"); break;
    case 88: strcpy(a, "Attribute not found"); break;
    case 89: strcpy(a, "Programming error"); break;
    case 90: strcpy(a, "Bad message"); break;
    case 91: strcpy(a, "Multihop attempted"); break;
    case 92: strcpy(a, "Link has been severed"); break;
    case 93: strcpy(a, "Protocol error"); break;
    }

    return a;
}
