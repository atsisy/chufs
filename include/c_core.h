#ifndef C_CORE_H
#define C_CORE_H

#include "c_types.h"

i32_t read_ata_sector(void *device, u32_t lba, void *buffer, i32_t count);
i32_t write_ata_sector(void *device, u32_t lba, void *buffer, i32_t count);
void register_command_function(const char *command_name,  long long int (*function)(const char *));

#endif
