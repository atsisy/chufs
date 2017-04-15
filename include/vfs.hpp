#ifndef VFS_HPP
#define VFS_HPP

#include <fstream>
#include <string>
#include "../include/types.hpp"

class VirtualFS {
private:
      std::ofstream *writer;
      std::ifstream *reader;

public:
      VirtualFS(std::string file_name);
      VirtualFS();
};


class CHVFS_MANAGER {
private:
      VirtualFS *vfs_file;
      Function_Table *function_table;

public:
      CHVFS_MANAGER(std::string file_name);
      CHVFS_MANAGER();

      void RegisterCmdFunction(std::string command, std::function<u64_t(std::string)> function);
      void CallCmdFunction(std::string command);
};

#endif
