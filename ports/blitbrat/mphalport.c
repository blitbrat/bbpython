#include <unistd.h>
#include "py/mpconfig.h"

// Receive single character, blocking until one is available.
int mp_hal_stdin_rx_chr(void) {
    // NOTE: This is just wrapping BlitBrat newlib's read, which itself
    // doesn't really do anything super useful.
    unsigned char c = 0;
    int r = read(STDIN_FILENO, &c, 1);
    (void)r;
    return c;
}

// Send the string of given length.
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    // NOTE: This is just wrapping BlitBrat newlib's write, which itself
    // doesn't really do anything super useful.
    int r = write(STDOUT_FILENO, str, len);
    (void)r;
}

// HACK: These are newlib stubs here just temporarily because the BlitBrat
// newlib port isn't mature enough to include them yet. These should be
// removed before any real use of this micropython port, to use the functions
// built into the toolchain instead.
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>
 
void _exit(int status) { for (;;) asm volatile("nop"); }
int _close(int file) { return -EINVAL; }
char **environ; /* pointer to array of char * strings that define the current environment variables */
int _execve(const char *__path, char * const __argv[], char * const __envp[])  { return -EINVAL; }
int _fork() { return -EINVAL; }
int _fstat(int file, struct stat *st) { return -EINVAL; }
int _getpid() { return -EINVAL; }
int _isatty(int file) { return -EINVAL; }
int _kill(int pid, int sig) { return -EINVAL; }
int _link(const char *__path1, const char *__path2) { return -EINVAL; }
off_t _lseek(int __fildes, off_t __offset, int __whence) { return -EINVAL; }
int _open(const char *name, int flags, ...) { return -EINVAL; }
_READ_WRITE_RETURN_TYPE _read (int __fd, void *__buf, size_t __nbyte) { return -EINVAL; }
void *  _sbrk (ptrdiff_t __incr) { return 0; }
int _stat(const char *file, struct stat *st) { return -EINVAL; }
clock_t _times(struct tms *buf) { return 0; }
int _unlink (const char *__path) { return -EINVAL; }
int _wait(int *status) { return -EINVAL; }
_READ_WRITE_RETURN_TYPE _write (int __fd, const void *__buf, size_t __nbyte) { return -EINVAL; }
int _gettimeofday (struct timeval *__restrict __p, void *__restrict __tz) { return -EINVAL; }
