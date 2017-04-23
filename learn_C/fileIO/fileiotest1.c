#include <stdio.h>
int main(int argc, char const *argv[]) {

  char buff[255];
  FILE * fp;
  fp = fopen("./outfile.md","w+");//文件不需要已经存在
  fprintf(fp, "%s\n", "this is fprintf~");
  fputs("this is fputs~\n",fp);
  fputs("this is fputs2~\n",fp);
  fclose(fp);
/*
this is fprintf text~
this is fputs~
this is fputs2~
*/
  FILE * fp1;
  fp1 = fopen("./outfile.md","r");
  fscanf(fp1,"%s",buff);
  printf("1:%s\n", buff);//输出一个字符
  fscanf(fp1,"%s",buff);//第二个单词
  printf("1-1:%s\n", buff);//输出一个字符
  //char *fgets( char *buf, int n, FILE *fp );
  fgets(buff,255,(FILE*)fp);
  printf("2:%s\n", buff);//输出一行

  fgets(buff,255,(FILE*)fp); //
  fgets(buff,255,(FILE*)fp);//下一行
  printf("3:%s\n", buff);//输出一行
  fclose(fp1);
  return 0;
}
