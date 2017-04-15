#include "../include/vfs.hpp"

static void just_alloc(std::ofstream *ofs, std::ifstream *ifs);

/*
 *=======================================================================================
 *VirtualFSクラスのコンストラクタ

 *=======================================================================================
 */
VirtualFS::VirtualFS(std::string file_name){

      just_alloc(writer, reader);

      writer->open(file_name.c_str(), std::ios::out);
      reader->open(file_name.c_str());
}

VirtualFS::VirtualFS(){

      just_alloc(writer, reader);

      writer = new std::ofstream();
      reader = new std::ifstream();
}

static inline void just_alloc(std::ofstream *ofs, std::ifstream *ifs){
      ofs = new std::ofstream();
      ifs = new std::ifstream();
}

CHVFS_MANAGER::CHVFS_MANAGER(){
      this->vfs_file = new VirtualFS();
      this->function_table = new Function_Table();
}

CHVFS_MANAGER::CHVFS_MANAGER(std::string file_name){
      this->vfs_file = new VirtualFS(file_name);
      this->function_table = new Function_Table();
}

void CHVFS_MANAGER::RegisterCmdFunction(std::string command, std::function<u64_t (std::string)> function){
      this->function_table->insert(std::make_pair(command, function));
}

void CHVFS_MANAGER::CallCmdFunction(std::string command){
      this->function_table->at(command)(command);
}
