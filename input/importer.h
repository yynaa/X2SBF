#include <aubio/aubio.h>

// * intitializes sample from the file
// ! the file has to be of the same sample rate as the console
aubio_source_t* source_importer(const char* filename, int sample_rate, int console_frequency);