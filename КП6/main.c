#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include "student.h"
#include "types.h"

typedef struct {
    FILE *in, *out;
} Data;


bool get(Student *student, void *data);
//void put(char classmateLetter, void *data);

bool get(Student * const student, void * const data) {
    FILE * const in = ((Data *) data)->in;
    const size_t count = fread(student, sizeof(Student), 1U, in);
    if (count != 1U && ferror(in) != 0) {
        perror("fread");
        exit(EXIT_FAILURE);
    } else if (count != 1U)
        return false;
    return true;
}

void put(const char classmateLetter, void * const data) {
    FILE * const out = ((Data *) data)->out;
    fprintf(out, "classmateLetter = %c\n", classmateLetter);
}

int main(const int argc, char ** const argv) {
    if (argc != 5) {
        fprintf(stderr, "%s: wrong count of arguments\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (strcmp(argv[1], "--help") == 0) {
        printf("Usage:\n  %s -f FILE -p PARAMETER\n", argv[0]);
        exit(EXIT_SUCCESS);
    };

    const char *file = NULL;
    llong parameter = 0;
    for (int opt; opt = getopt(argc, argv, "f:p:"), opt != -1; ) {
        switch (opt) {
            case ':':
                fprintf(stderr, "%s: unknown option -- %c\n", argv[0], optopt);
                break;
            case '?':
                break;
            case 'f':
                file = optarg;
                break;
            case 'p':
                char *end;
                parameter = strtoll(optarg, &end, 10);
                break;
            default:
                assert(false);
        }
    }
    /*
        на отл: добавить проверок при парсинге (не убирая getopt)
    */

    printf("file: %s, parameter: %lld\n", file, parameter);

    FILE *in = fopen("in.dat", "rb");
    if (in == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    Data data = { .in = in, .out = stdout };
    select(get, put, &data);

    if (fclose(in) == EOF) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    return 0;
}