#ifndef ERRIC_FILE_READING_H
#define ERRIC_FILE_READING_H

#include <stdio.h>
#include "erric_interpreter.h"

// A macro to swap bytes for endianness in a quick and easy manner
#define CHANGE_ENDIAN(x) swap_bytes((uint8_t*)&(x), sizeof(x))

/**
 * Tries to swap bytes in a byte array
 * Used here to swap between little and big endianness by casting values to arrays with sizeof(variable)
 *
 * @param bytes pointer to an array of uint8_t (usually cast from other types)
 * @param length length of the array (sizoef(original variable)
 */
void swap_bytes(uint8_t *bytes, size_t length);

/**
 * Reads a version 0 executable file
 * See documentation for the format itself
 *
 * @param erric			pointer to the erric structure
 * @param executable	file to read from
 * @return ERRIC_STATUS_NONE on success, error status code on failure
 */
sword_t read_v0_file(struct erric_t *erric, FILE *executable);

/**
 * Reads a version 1 executable file
 * See documentation for the format itself
 *
 * @param erric			pointer to the erric structure
 * @param executable	file to read from
 * @return ERRIC_STATUS_NONE on success, error status code on failure
 */
sword_t read_v1_file(struct erric_t *erric, FILE *executable);

#endif //ERRIC_FILE_READING_H
