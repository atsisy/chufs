#include "../include/vfs.hpp"

static void just_alloc(std::ofstream *ofs, std::ifstream *ifs);

/*
 *=======================================================================================
 *VirtualFSクラスのコンストラクタ
 *=======================================================================================
 */
VirtualFS::VirtualFS(std::string file_name, u16_t block_size){

      just_alloc(writer, reader);

      writer->open(file_name.c_str(), std::ios::binary | std::ios::out);
      reader->open(file_name.c_str(), std::ios::binary | std::ios::in);

      this->block_size = block_size;
}

VirtualFS::VirtualFS(u16_t block_size){

      just_alloc(writer, reader);

      writer = new std::ofstream();
      reader = new std::ifstream();

      this->block_size = block_size;
}

static inline void just_alloc(std::ofstream *ofs, std::ifstream *ifs){
      ofs = new std::ofstream();
      ifs = new std::ifstream();
}

/*
 *=======================================================================================
 *VirtualFS::Seekメソッド
 *指定したlbaにシークするメソッド
 *=======================================================================================
 */
void VirtualFS::Seek(u64_t lba){
      reader->seekg(lba * block_size, std::ios_base::beg);
      writer->seekp(lba * block_size, std::ios_base::beg);
}

void VirtualFS::ReadSector(u64_t lba, char *buffer){
      reader->seekg(lba * block_size, std::ios_base::beg);
      reader->read(buffer, block_size);
}

void VirtualFS::WriteSector(u64_t lba, char *buffer){
      writer->seekp(lba * block_size, std::ios_base::beg);
      writer->write(buffer, block_size);
}

void VirtualFS::MoveBufferPointer(char **buffer){
      *buffer += block_size;
}

CHVFS_MANAGER::CHVFS_MANAGER( u16_t block_size){
      this->vfs_file = new VirtualFS(block_size);
      this->function_table = new Function_Table();
}

CHVFS_MANAGER::CHVFS_MANAGER(std::string file_name, u16_t block_size){
      this->vfs_file = new VirtualFS(file_name, block_size);
      this->function_table = new Function_Table();
}

void CHVFS_MANAGER::RegisterCmdFunction(std::string command, std::function<u64_t (std::string)> function){
      this->function_table->insert(std::make_pair(command, function));
}

void CHVFS_MANAGER::CallCmdFunction(std::string command){
      this->function_table->at(command)(command);
}

void CHVFS_MANAGER::Read(u32_t lba, void *buffer, i32_t count){
      if(count <= 0)
            return;

      while(count){
            vfs_file->ReadSector(lba, (char *)buffer);
            vfs_file->MoveBufferPointer((char **)(&buffer));
            ++lba;
            --count;
      }
}

void CHVFS_MANAGER::Write(u32_t lba, void *buffer, i32_t count){
      if(count <= 0)
            return;

      while(count){
            vfs_file->WriteSector(lba, (char *)buffer);
            vfs_file->MoveBufferPointer((char **)(&buffer));
            ++lba;
            --count;
      }
}
