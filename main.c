#include "arg_parser.h"

#include "input/importer.h"

#include <stdio.h>
#include <stdlib.h>

#include <aubio/aubio.h>

int main(int argc, char** argv) {
    // params
    x2sbf_arg* params = parse_args(argc, argv);

    // * input management
    aubio_source_t* input_source = source_importer(params->input, params->sample_rate, params->console_freq);



    // ! cleanup
    aubio_source_close(input_source);
    free(params);
    return 0;
}