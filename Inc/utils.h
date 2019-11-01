/*******************************************************************************
 * @attention Copyright would go here...
 * @file utils.h
 * @author Paul Czeresko
 * @date 26 Oct 2019
 * @brief Definitions for utility functions
 *******************************************************************************/

#ifndef __UTILS_H
#define __UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/**
 * @brief Macros for using the Bit Set Reset Register
 * These macros increase verbosity when setting or resetting bits in the BSRR.
 * Writing a 1 to [15:0] of this 32-bit register sets the selected pins on that
 * port.
 * Writing a 1 to [31:16] of this 32-bit register resets the selected pins on
 * that port.
 * Writing a 0 to any bit of this register is a don't-care. When used
 * responsibly this eliminates the need for a bit mask. Furthermore, using the
 * BSRR, in contrast to the ODR, is an atomic operation.
 */
#define BSRR_ON( VAL )		( (uint16_t)VAL )
#define BSRR_OFF( VAL )		( (uint16_t)VAL << 16 )

uint32_t uxRand(void);
void vUtilsInit(void);

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_H */
