#include "../include/c_wrapper.h"
#include "../include/vfs.hpp"

extern CHVFS_MANAGER *manager;

/*
 *=======================================================================================
 *read_ata_sector_cxx_wrapper関数
 *read_ata_sector関数（C側）のC++実装
 *=======================================================================================
 */
i32_t read_ata_sector_cxx_wrapper(u32_t lba, void *buffer, i32_t count){
      manager->Read(lba, buffer, count);
      return 1;
}

/*
 *=======================================================================================
 *write_ata_sector_cxx_wrapper関数
 *write_ata_sector関数（C側）のC++実装
 *=======================================================================================
 */
i32_t write_ata_sector_cxx_wrapper(u32_t lba, void *buffer, i32_t count){
      manager->Write(lba, buffer, count);
      return 1;
}
