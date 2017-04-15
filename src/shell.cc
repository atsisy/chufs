#include "../include/shell.hpp"
#include "../include/value.hpp"
#include "../include/cmdline_wiz.hpp"
#include <iostream>

/*
 *=======================================================================================
 *コンストラクタ
 *=======================================================================================
 */
Shell::Shell(){
      /*
       *今のところ何もしない
       */
}

/*
 *=======================================================================================
 *デストラクタ
 *=======================================================================================
 */
Shell::~Shell(){
      /*
       *今のところ何もしない
       */
}

/*
 *=======================================================================================
 *Shell::MainLooメソッド
 *シェルのメインループ処理を行うメソッド
 *コマンドを受け取って、Translationcommandメソッドに投げるだけ
 *引数
 *CHVFS_MANAGER *manager
 *こいつの関数テーブルがほしい
 *返り値なし
 *=======================================================================================
 */
void Shell::MainLoop(CHVFS_MANAGER *manager){
      while(true){
            //入力を促す
            std::cout << first_string;

            //コマンドを受け取る
            std::getline(std::cin, command);

            //投げる
            TranslationCommand(manager);
      }
}

/*
 *=======================================================================================
 *Shell::TranslationCommandメソッド
 *コマンドを解読して、関数テーブルに登録された関数を呼び出すメソッド
 *引数
 *CHVFS_MANAGER *manager
 *こいつの関数テーブルがほしい
 *返り値
 *コマンドがあった
 *SUCCESS
 *コマンドがない
 *FAILURE
 *=======================================================================================
 */
i8_t Shell::TranslationCommand(CHVFS_MANAGER *manager){

      //コマンド処理オブジェクトを生成
      CommandLineWiz wiz(command.data());

      try{
            //関数呼び出し
            manager->CallCmdFunction(wiz.At(0));
      }
      catch(std::out_of_range&){
            std::cerr << "command not found: " << wiz.At(0) << std::endl;
            return FAILURE;
      }

      return SUCCESS;

}
