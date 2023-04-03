/**************************************************************************
 * ファイル一覧
 * (http://kaworu.jpn.org/kaworu/2008-05-05-1.php より引用)
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h>
#include <err.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

// ディレクトリエントリをリストに含めるかどうかを決めるための関数
int selects(const struct dirent *dir) {
  if (dir->d_name[0] == '.') {
    return FALSE; // .(ドット)で始まるファイル名を除外する
  }
  return TRUE;
}

// 自作の並び替えの為の比較関数
int compare(const struct dirent **s1, const struct dirent **s2) {
  return strcmp((*s2)->d_name, (*s1)->d_name); // 逆順に並び替える例
}

int main(int argc, char const *argv[]) {
  int i;

  const char *dirname = "./"; // ディレクトリ名
                              // (./はカレントディレクトリ)
  struct dirent **namelist; // ディレクトリにあるファイル名を格納する構造体

  // scandir関数で、ディレクトリにあるファイル名を取得する
  // 第三引数は、ディレクトリエントリをリストに含めるかどうかを決めるための関数
  // 第四引数は、並び替え関数名 alphasortはアルファベット順
  int r = scandir(dirname, &namelist, selects, alphasort);
  // 自作の並び替え用の比較関数compareを用いた例
  // int r = scandir(dirname, &namelist, selects, compare);

  if (r == NOT_FOUND) {
    err(EXIT_FAILURE, "%s というディレクトリは見つかりませんでした\n", dirname);
  }
  printf("%d 個のファイルが見つかりました\n", r);
  for (i = 0; i < r; i++) {
    printf("%s %d %d\n", namelist[i]->d_name, namelist[i]->d_reclen,
           namelist[i]->d_namlen);
    // そのディレクトリにいくつのファイルがあるかは予測不可
    // なので、namelistはmallocで取得されている
    // 使用が終わったら、freeが必要
    free(namelist[i]);
  }
  free(namelist);

  exit(EXIT_SUCCESS);
}
