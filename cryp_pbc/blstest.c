#include <stdio.h>

#include "/usr/local/include/pbc/pbc.h"  //必须包含头文件pbc.h
//#include "/usr/local/include/pbc/pbc_test.h"
int main(int argc, char const *argv[]) {

  pairing_t pairing;
  /*
  pairing_t定义： pairings where elements belong本例子用a.param去初始化pairing; a pairing is a map 例如:e:G1×G2->Gt
  a.param是pbc库中标准的参数集，其提供对称的pairing ，在所有的param中有最高的速度(根据看过的一篇论文中说明的没做实验～～)
  */
  char param[1024];
  size_t count = fread(param, 1, 1024, stdin);//读大小为1的个数最大为1024到param，返回真实读入的个数
  //printf("param = %s\n", param);
  printf("count = %lu\n", count);//size_t是标准C库中定义的，应为unsigned int，在64位系统中为 long unsigned int
  if (!count) pbc_die("input error");
  pairing_init_set_buf(pairing, param, count);
  //pairing 初始化结束

  //定义变量-初始化-用于保存系统参数、公私秘钥以及其他变量
  element_t g, h;
  element_t public_key, secret_key;
  element_t sig;
  element_t temp1, temp2;

  element_init_G2(g, pairing);//用pairing 初始化g
  element_init_G2(public_key, pairing);
  element_init_G1(h, pairing);
  element_init_G1(sig, pairing);
  element_init_GT(temp1, pairing);
  element_init_GT(temp2, pairing);
  element_init_Zr(secret_key, pairing);

  element_random(g);//随机生成g
  element_random(secret_key);//随机生成secret_key
  element_pow_zn(public_key, g, secret_key);//public_key = g^secret_key
  //当要对一个消息进行签名时，首先需要对其进行hash，使用一些标准的哈希算法，哈希过程没有涉及到pairing 所以 很遗憾pbc库中没有提供
  element_from_hash(h, "ABCDEF", 6);//假设hash消息后得ABCDEF（48bit的哈希），这个函数的作用时map these bytes to an element h of G1
  element_pow_zn(sig, h, secret_key);//sig = h^secret_key

  pairing_apply(temp1, sig, g, pairing);//temp1 = e(sig,g)
  pairing_apply(temp2, h, public_key, pairing); // e(h,public_key)
  if (!element_cmp(temp1, temp2)) {    //e(sig,g)=e(h^secret_key,g)//e(h,public_key)=e(h,g^secret_key)只要sig正确那么就有temp1=temp2
    printf("signature verifies\n");
  } else {
    printf("signature does not verify\n");
  }
  return 0;
}
