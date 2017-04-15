#ifndef COMMAND_LINE_WIZ_HPP
#define COMMAND_LINE_WIZ_HPP

#include <string>
#include <vector>
#include <memory>

class CommandLineWiz {
private:
      std::unique_ptr<std::string> origin;
      std::unique_ptr<std::vector<std::string>> word_vector;

public:
      CommandLineWiz();
      CommandLineWiz(const char *command_line);
      ~CommandLineWiz();
      std::string At(int index);
};

#endif
