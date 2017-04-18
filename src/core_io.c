#include "../include/c_wrapper.h"


/*
 *=======================================================================================
 *read_ata_sector関数
 *セクタごとにデータを読み込む関数
 *引数
 *struct ATA_DEVICE *device
 *=>ターゲットデバイス
 *u32_t lba
 *LBA方式でセクタを指定
 *void *buffer
 *読み込んだデータを格納するバッファへのポインタ
 *i32_t count
 *=>読み込むデータ数（セクタ数）
 *返り値
 *終了状況
 *=======================================================================================
 */
i32_t read_ata_sector(void *device, u32_t lba, void *buffer, i32_t count){
      read_ata_sector_cxx_wrapper(lba, buffer, count);
      return 1;
}

/*
 *=======================================================================================
 *ata_write_sector関数
 *ATAデバイスにセクタごとにデータを書き込む関数
 *引数
 *i32_t device
 *=>デバイス選択
 * *i32_t count
 *=>書き込むセクタ数
 *void *buffer
 *=>書き込むデータのバッファへのポインタ
 *返り値
 *1以上
 *=>コマンド実行前エラー
 *0
 *=>正常終了
 *0未満
 *=>コマンド実行ごエラー
 *=======================================================================================
 */
i32_t write_ata_sector(void *device, u32_t lba, void *buffer, i32_t count){
      write_ata_sector_cxx_wrapper(lba, buffer, count);
      return 1;
}

/*
 *=======================================================================================
 *register_command_function関数
 *コマンドの関数テーブルに関数を登録する関数（C向けラッパ）
 *引数
 *const char *command_name
 *対応するコマンド
 *long long int (*function)(const char *)
 *コマンドが入力された時に実行する関数
 *返り値なし
 *=======================================================================================
 */
void register_command_function(const char *command_name,  long long int (*function)(const char *)){
      register_command_function_cxx_wrapper(command_name, function);
}
