struct _x2sbf_arg {
    int help;

    char* input;

    int console_freq;
    int sample_rate;
};

typedef struct _x2sbf_arg x2sbf_arg;

x2sbf_arg* parse_args(int argc, char** argv);