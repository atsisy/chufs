#include "../../include/cmdline_wiz.hpp"
#include <sstream>

/*
 *=======================================================================================
 *str_shrink関数
 *文字列中の指定した文字列が連続で出現した場合、それを圧縮する関数
 *std::unique_ptr<std::string> str
 *対象の文字列へのスマートポインタ
 *short index
 *どこから検索を始めるか
 *char target
 *検索する文字
 *返り値
 *
 *=======================================================================================
 */
static std::unique_ptr<std::string> str_shrink(std::unique_ptr<std::string> str, short index, char target){
      bool flag = false;

      for(unsigned short i = index; i < str->length(); ++i){
            if(str->data()[i] == target){
                  if(!flag){
                        flag = true;
                  }
                  else{
                        str_shrink(std::move(str), i, target);
                        str->erase(str->begin() + i);
                  }
            }
            else{
                  flag = false;
            }
      }
      return str;
}

/*
 *=======================================================================================
 *コンストラクタ
 *=======================================================================================
 */
CommandLineWiz::CommandLineWiz()
      : origin(new std::string), word_vector(new std::vector<std::string>) {}

CommandLineWiz::CommandLineWiz(const char *command_line)
      : origin(new std::string(command_line)), word_vector(new std::vector<std::string>)
{
      std::stringstream string_stream(command_line);
      std::string buffer;

      origin = str_shrink(std::move(origin), 0, ' ');

      while(std::getline(string_stream, buffer, ' ')) {
            word_vector->push_back(buffer);
      }
}

/*
 *=======================================================================================
 *デストラクタ
 *=======================================================================================
 */
CommandLineWiz::~CommandLineWiz(){
      origin.reset(nullptr);
      word_vector.reset(nullptr);
}

/*
 *=======================================================================================
 *CommandLineWiz::Atメソッド
 *コマンドラインのindex番目の文字列を返す関数
 *引数
 *int index
 *インデックス
 *返り値
 *文字列
 *=======================================================================================
 */
std::string CommandLineWiz::At(int index){
      return word_vector->at(index);
}

