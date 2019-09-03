
#include "gen.h"

char* create_include_directive(const char* filename) {
    int length = (int) strlen("#include \"\"\n") + strlen(filename);

    char* include_directive = malloc(sizeof (char) * (length + 1));

    if (sprintf(include_directive, "#include \"%s\"\n", filename) != length) {
        fprintf(stderr, "[Error] %s\n", "Error in create_include_directive");
        exit(EXIT_FAILURE);
    }

    return include_directive;
}

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i) {
        char* include_directive = create_include_directive(argv[i]);
        printf("%s", include_directive);
        free(include_directive);
    }

    return EXIT_SUCCESS;
}
