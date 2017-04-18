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
      void register_command_function_cxx_wrapper(const char *command_name, long long int (*function)(const char *));
#ifdef __cplusplus
};
#endif

#endif
