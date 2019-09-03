
#include "gen.h"

int exists(const char* filename) {
    errno = 0;

    if (access(filename, F_OK) == -1) {
        switch (errno) {
            case ENOENT: {
                return FALSE;
            } break;

            case ENOTDIR: {
                return FALSE;
            } break;

            default: {
                fprintf(stderr, "[Error] %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            } break;
        }
    }

    return TRUE;
}
