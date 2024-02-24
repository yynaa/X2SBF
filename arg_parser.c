#include "arg_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

x2sbf_arg* parse_args(int argc, char** argv){
    x2sbf_arg* arg = malloc(sizeof(x2sbf_arg));

    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
            printf("x2sbf - bruteforce samples into sound chips that cannot produce samples\n\n");
            printf("-h || --help: Show this help message\n");
            exit(0);
        }
    }
}