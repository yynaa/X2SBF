#include <aubio/aubio.h>

#include <stdio.h>

aubio_source_t* source_importer(const char* filename, int sample_rate, int console_frequency){
    uint_t sr = sample_rate;
    uint_t cf = console_frequency;

    aubio_source_t* source = new_aubio_source(filename, sr, sr/cf);
    if (!source){
        printf("Error: Unable to open file\n");
        return 0;
    }

    return source;
}