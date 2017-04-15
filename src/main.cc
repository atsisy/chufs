#include <iostream>
#include "../include/types.hpp"
#include "../include/value.hpp"
#include "../include/vfs.hpp"
#include "../include/cmdline_wiz.hpp"
#include "../include/shell.hpp"

#define BLOCK_SIZE 512

i8_t init(int argc, char **argv);
i8_t translate_command(std::string command);

CHVFS_MANAGER *manager;

u64_t vfs_create(std::string string){
      std::cout << string << std::endl;
      return 0;
}

u64_t vfs_quit(std::string string){
      exit(-1);
      return 0;
}


int main(int argc, char **argv){

      if(IS_FAILURE(init(argc, argv))){
            std::cerr << "FAILD TO INITALIZE" << std::endl;
            exit(-1);
      }

      Shell shell;
      shell.MainLoop(manager);

      return 0;
}

i8_t init(int argc, char **argv){

      manager = (argc > 1) ? new CHVFS_MANAGER(argv[1], BLOCK_SIZE) : new CHVFS_MANAGER(BLOCK_SIZE);

      if(IS_NULLPO(manager))
            return FAILURE;

      manager->RegisterCmdFunction(std::string("vfs"), vfs_create);
      manager->RegisterCmdFunction(std::string("quit"), vfs_quit);

      return SUCCESS;
}

