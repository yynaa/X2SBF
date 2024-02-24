#include "arg_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

x2sbf_arg* parse_args(int argc, char** argv){
    x2sbf_arg* arg = malloc(sizeof(x2sbf_arg));
    arg->console_freq = 60;
    arg->sample_rate = 44100;
    arg->input = 0;

    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
            printf("x2sbf - bruteforce samples into sound chips that cannot produce samples\n\n");
            printf("-h || --help: Show this help message\n");
            printf("-i || --input: Input file\n");
            printf("-cf || --cfreq: Console frequency (60Hz by default)\n");
            printf("-sr || --srate: Console sample rate (44100Hz by default)\n");
            exit(0);
        }
        else if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--input") == 0){
            if (i + 1 < argc){
                arg->input = argv[i + 1];
                i++;
            }
            else{
                printf("Error: -i requires an argument\n");
                exit(1);
            }
        }
        else if (strcmp(argv[i], "-cf") == 0 || strcmp(argv[i], "--cfreq") == 0){
            if (i + 1 < argc){
                arg->console_freq = atoi(argv[i + 1]);
                if (arg->console_freq <= 0){
                    printf("Error: Console frequency must be a positive integer\n");
                    exit(1);
                }
                i++;
            }
            else{
                printf("Error: -cf requires an argument\n");
                exit(1);
            }
        }
        else if (strcmp(argv[i], "-sr") == 0 || strcmp(argv[i], "--srate") == 0){
            if (i + 1 < argc){
                arg->sample_rate = atoi(argv[i + 1]);
                if (arg->sample_rate <= 0){
                    printf("Error: Sample rate must be a positive integer\n");
                    exit(1);
                }
                i++;
            }
            else{
                printf("Error: -sr requires an argument\n");
                exit(1);
            }
        }
    }

    if (!arg->input){
        printf("Error: No input file specified\n");
        exit(1);
    }

    return arg;
}