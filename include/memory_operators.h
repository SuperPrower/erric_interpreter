#ifndef ERRIC_MEMORY_OPERATORS_H
#define ERRIC_MEMORY_OPERATORS_H

#include "erric_interpreter.h"

/**
 * @brief Rj = *Ri
 * Load contents from memory address in Ri to Rj
 *
 * @param[in] erric - pointer to erric structure
 * @param[in] i	- no. of register
 * @param[in] j	- no. of register
 * @param[in] format - operation format, F_32_BIT required
 *
 * @returns ERRIC_STATUS_NONE on success, appropriate ERRIC_STATUS_* on error
 */
sword_t ld(struct erric_t *erric, sword_t i, sword_t j, enum format_t format);

/**
 * @brief Rj = Ri + constant
 * Takes the value from the next in-memory 32-bit word, adds it with the value of Ri, then stores into Rj
 * Side-effects: PC is updated and increased by 1, with the assumption that the function is called from a loop and PC
 *  will be incremented by 1 after calling this one
 *
 * @param[in] erric - pointer to erric structure
 * @param[in] i	- no. of register
 * @param[in] j	- no. of register
 * @param[in] format - operation format, F_8_BIT required
 *
 * @returns ERRIC_STATUS_NONE on success, appropriate ERRIC_STATUS_* on error
 */
sword_t lda(struct erric_t *erric, sword_t i, sword_t j, enum format_t format);

/**
 * @brief Rj = constant
 * Put the value of a constant inside the command into Rj register
 *
 * @param[in] erric - pointer to erric structure
 * @param[in] i	- constant
 * @param[in] j	- no. of register
 * @param[in] format - operation format, F_32_BIT required
 *
 * @returns ERRIC_STATUS_NONE on success, appropriate ERRIC_STATUS_* on error
 */
sword_t ldc(struct erric_t *erric, sword_t i, sword_t j, enum format_t format);

/**
 * @brief *Rj = Ri
 * Put the value from Ri register into memory pointed to by Rj register
 *
 * @param[in] erric - pointer to erric structure
 * @param[in] i	- no. of register
 * @param[in] j	- no. of register
 * @param[in] format - operation format, F_32_BIT required
 *
 * @returns ERRIC_STATUS_NONE on success, appropriate ERRIC_STATUS_* on error
 */
sword_t st(struct erric_t *erric, sword_t i, sword_t j, enum format_t format);

/**
 * @brief Rj = Ri
 * Copy Ri into Rj
 *
 * @param[in] erric - pointer to erric structure
 * @param[in] i	- no. of register
 * @param[in] j	- no. of register
 * @param[in] format - operation format, F_32_BIT required
 *
 * @returns ERRIC_STATUS_NONE on success, appropriate ERRIC_STATUS_* on error
 */
sword_t mov(struct erric_t *erric, sword_t i, sword_t j, enum format_t format);

// Utility function for the execution table
sword_t ldaldc(struct erric_t *erric, sword_t i, sword_t j, enum format_t format);

#endif //ERRIC_MEMORY_OPERATORS_H
