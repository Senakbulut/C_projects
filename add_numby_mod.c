#include <stdio.h>
#include <stdlib.h>
int find(int sayi,int d1);
int lastNo(int number,int add);

int main(int argc,char *argv[])
{ int sonsayi;
  int girilen;
  int total;
  int eklenen;
  printf("%d\n",argc);
  girilen=atoi(argv[1]);
  printf("%d\n",girilen);
  eklenen=find(girilen,total);
  sonsayi=lastNo(girilen,eklenen);
  printf("%d\n",sonsayi);

  return 0;
}

int find(int sayi,int d1 ){

 int toplam;
 int d2,d3,d4,d5,d6,d7,d8,d9,d10;

 d10=sayi/100000000;
 sayi=sayi-(d10*100000000);
 d9=sayi/10000000;
 sayi=sayi-(d9*10000000);
 d8=sayi/1000000;
 sayi=sayi-(d8*1000000);
 d7=sayi/100000;
 sayi=sayi-(d7*100000);
 d6=sayi/10000;
 sayi=sayi-(d6*10000);
 d5=sayi/1000;
 sayi=sayi-(d5*1000);
 d4=sayi/100;
 sayi=sayi-(d4*100);
 d3=sayi/10;
 sayi=sayi-(d3*10);
 d2=sayi;

 toplam=2*d2+3*d3+4*d4+5*d5+6*d6+7*d7+8*d8+9*d9+10*d10;


 d1=11-(toplam%11);
 if(d1<10){
   printf("d1 sayisi:%d\n",d1);
 }
 else if(d1=10){
   printf("d1 sayisi hesaplanmaya uygun degil");

 return d1;
}
int lastNo(int number,int add){
  int sonno;
  if(add<10){
    sonno=(number*10)+add;
    }

  return sonno;
}
