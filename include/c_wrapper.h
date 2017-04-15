#ifndef C_WRAPPER_H
#define C_WRAPPER_H

#ifdef __cplusplus
#include "types.hpp"
#endif

#ifndef __cplusplus
#include "c_types.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif
      i32_t read_ata_sector_cxx_wrapper(u32_t lba, void *buffer, i32_t count);
      i32_t write_ata_sector_cxx_wrapper(u32_t lba, void *buffer, i32_t count);
#ifdef __cplusplus
};
#endif

#endif
