#include "../include/c_wrapper.h"
#include "../include/vfs.hpp"

extern CHVFS_MANAGER *manager;

i32_t read_ata_sector_cxx_wrapper(u32_t lba, void *buffer, i32_t count){
      manager->Read(lba, buffer, count);
}

i32_t write_ata_sector_cxx_wrapper(u32_t lba, void *buffer, i32_t count){
      manager->Write(lba, buffer, count);
}
