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

/*
 *=======================================================================================
 *register_command_function関数
 *関数テーブル登録関数のC/C++ラッパー
 *引数
 *const char *command_name
 *対応するコマンド名
 *u64_t (*function)(const char *)
 *そのコマンドが入力された時に実行される関数のポインタ
 *=======================================================================================
 */
void register_command_function_cxx_wrapper(const char *command_name, long long int (*function)(const char *)){
      manager->RegisterCmdFunction(std::string(command_name), [&](std::string command){
                  return function(command.data());
            });
}
