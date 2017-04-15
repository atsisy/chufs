#ifndef SHELL_HPP
#define SHELL_HPP

#include <string>
#include "types.hpp"
#include "vfs.hpp"

/*
 *=======================================================================================
 *Shellクラス
 *ユーザとの対話を行うクラス
 *=======================================================================================
 */
class Shell {
  private:
      //行の最初に表示する文字列
      const std::string first_string{"> "};

      //受け取ったコマンドを入れておく変数
      std::string command;

      //コマンドを読み取って登録された関数を呼び出すプライベートメソッド
      i8_t TranslationCommand(CHVFS_MANAGER *manager);

  public:
      //コンストラクタ
      Shell();

      //デストラクタ
      ~Shell();

      //シェルのループ処理を担うメソッド
      void MainLoop(CHVFS_MANAGER *manager);
};

#endif
