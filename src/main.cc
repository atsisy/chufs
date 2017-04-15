#include <iostream>
#include "../include/types.hpp"
#include "../include/value.hpp"
#include "../include/vfs.hpp"
#include "../include/cmdline_wiz.hpp"

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

      std::string command;

      while(true){
            std::cout << "> ";
            std::getline(std::cin, command);
            translate_command(command);
      }


      return 0;
}

i8_t init(int argc, char **argv){

      if(argc > 1)
            manager = new CHVFS_MANAGER(argv[1]);
      else
            manager = new CHVFS_MANAGER();


      if(IS_NULLPO(manager))
            return FAILURE;

      manager->RegisterCmdFunction(std::string("vfs"), vfs_create);
      manager->RegisterCmdFunction(std::string("quit"), vfs_quit);

      return SUCCESS;
}

i8_t translate_command(std::string command){

      CommandLineWiz wiz(command.data());

      try{
            manager->CallCmdFunction(wiz.At(0));
      }
      catch(std::out_of_range&){
            std::cerr << "command not found: " << wiz.At(0) << std::endl;
      }

      return SUCCESS;
}
