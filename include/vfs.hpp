#ifndef VFS_HPP
#define VFS_HPP

#include <fstream>
#include <string>
#include "../include/types.hpp"

class VirtualFS {
private:
      std::ofstream *writer;
      std::ifstream *reader;
      u16_t block_size;

public:
      VirtualFS(std::string file_name, u16_t block_size);
      VirtualFS(u16_t block_size);

      void Seek(u64_t lba);
      void ReadSector(u64_t lba, char *buffer);
      void WriteSector(u64_t lba, char *buffer);
      void MoveBufferPointer(char **buffer);
};


class CHVFS_MANAGER {
private:
      VirtualFS *vfs_file;
      Function_Table *function_table;

public:
      CHVFS_MANAGER(std::string file_name, u16_t block_size);
      CHVFS_MANAGER(u16_t block_size);

      void RegisterCmdFunction(std::string command, std::function<u64_t(std::string)> function);
      void CallCmdFunction(std::string command);
      void Read(u32_t lba, void *buffer, i32_t count);
      void Write(u32_t lba, void *buffer, i32_t count);
};

#endif

