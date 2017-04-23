#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct{
  char count;
  char total;
  char name[5];
}item[2];

int main(int argc, char const *argv[]) {
  printf("File :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );
  printf("\n二进制输出%s\n", "");
  item[0].count='1';
  item[0].total = '0';
  strcpy(item[0].name,"1010");

  item[1].count='0';
  item[1].total = '0';
  strcpy(item[1].name,"0010");
  FILE * bFp;
  bFp = fopen("./bfile.md","ab+");
  /*
  1.buffer是一个指向用于保存数据的内存位置的指针
  2.size是缓冲区中每个元素的字节数，
  3.count是读取或写入的元素数，
  4.当然stream是数据读取或写入的流。
  */
  //fwrite(ch1,sizeof(char),10,bFp);
  fwrite(item,sizeof(item[1]),2,bFp);

  char ch[100];
  size_t num= fread(ch,1,4,bFp);

  printf("%c\n", ch);
  /*
  if(fwrite(&item,sizeof(item),1,bFp)==1)
  {
    //err_sys("fwrite_error~");
    printf("%s\n", "over");
  }*/
  fclose(bFp);
  return 0;
}
