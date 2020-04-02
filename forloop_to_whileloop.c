Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@Senakbulut 
Senakbulut
/
for_loop_to_while_loop
0
00
 Code Issues 0 Pull requests 0 Actions Projects 0 Wiki Security Insights Settings
for_loop_to_while_loop/main.c
@Senakbulut Senakbulut Add files via upload
45e967d on 29 Apr 2019
289 lines (283 sloc)  9.99 KB
  
#include <stdio.h>
#include <stdlib.h>

int main(int arg,char *argv[]){
char forici2[500];//kullanacagim dizilerin adini ve boyutunu belirledim
char forici[500];
char girdi[5000];
  FILE*input; //input dosyasini tanimladim
  input=fopen(argv[1],"r+");//inputu okuma islemi icin actim
  if(input==NULL){//eger input bossa dosyayi okuyamayacagini belirttim
    printf("dosya acma basarisiz\n");
    return 0;
  }
  FILE*output;//output dosyasini tanimladım
  output=fopen(argv[2],"w+");//outputu yazma icin actim
  if(output==NULL){
    printf("dosya acma basarisiz\n");
    return 0;
  }
  int i=0;
  while(girdi[i]!=EOF){//inputta yazilanlarin sonuna gelene kadar
        girdi[i]=getc(input);//input dosyasini aldim
        printf("%c",girdi[i]);
        i++;//artirdim
  }
    printf("\n");
    forbul(girdi,forici);//kullandigim fonksiyonlari mainde tanimladim
    printf("\n");
    printf("\n");
    printf("\n");
    forbul2(girdi,forici2);
    printf("\n");
    iciniokuma1(output,forici2);
    printf("\n");
    printf("\n");
    donustur(output,girdi,forici,forici2);

    fclose(output);//outout dosyasini kapattim
    fclose(input);//input dosyasini kapattim
    return 0;
}
void forbul(char text[5000],char forici[500]){//foru bulma fonsiyonu
    char aranan[]={'f','o','r'};//for'un elemanlarini dizide tanimladim
    int i=0,t=0;
    for(i=0;i<5000;i++){//dosya icindeki belirlenen boyutta i dolasacak
        if(aranan[0]==text[i]){//eger inputta yazan harf f'e esitse
            i++;//arttiriyor
            if(aranan[1]==text[i]){//eger inputtaki harf o'ya esitse
                i++;//arttiriyor
                if(aranan[2]==text[i]){//eger inputtaki harf r'ye esitse
                    i++;//arttiriyor
                 printf("for bulundu\t");
                 printf("\n");
                }
            }
        }
        forici[t]=text[i];// )'e kadarki kismi forici dizisine attim
        printf("%c",forici[t]);
        t++;
        if(text[i]==')'){// )'e kadar okudu
            break;//sonra gerisini okumadi
         }
   }
}
void iciniokuma1(FILE*output,char metin[5000]){//for icinin ilk kismini okuma fonk.
   int i=0;
   for(i=1;metin[i]!=';';i++){//;'e kadar okudum
      printf("%c",metin[i]);
      fprintf(output,"%c",metin[i]);//dosyaya yazdirmak icin
      if(metin[i]==';'){//;'den sonrasini okumadi
        break;
 }
   }
   printf("\n");
}
void iciniokuma2(FILE*output,char metin2[5000]){//iki ; arasini okuma fonk.
   int i=0;
   for(i=0;metin2[i]!=';';i++){//ilk ;'e kadar okuma kismi
      if(metin2[i]==';'){//;'den sonra i'yi artirdi
 }
   }
   i++;//;'den sonra i'yi artirdi
 for(i;metin2[i]!=';';i++){//ilk ;'ü okuduktan sonra
      printf("%c",metin2[i]);//ikinci ;'e kadar okuyor
      fprintf(output,"%c",metin2[i]);//dosyaya yazdirmak icin
      if(metin2[i]==';'){//;'den sonrasini okumuyor
        break;
 }
}
}
void iciniokuma3(FILE*output,char metin3[5000]){//forun 3.kismini okuma fonk.
   int i=0;
   for(i=0;metin3[i]!=';';i++){//forun ilk kismini okuyan kisim
      if(metin3[i]==';'){
 }
   }
   i++;//;'den sonra i'yi artirdi
 for(i;metin3[i]!=';';i++){//forun ikinci kismini okuyan kisim
      if(metin3[i]==';'){
 }
}
i++;//;'den sonra i'yi artirdi
for(i;metin3[i]!=')';i++){// )'e kadar okudu
        printf("%c",metin3[i]);
        fprintf(output,"%c",metin3[i]);//dosyaya yazdirmak icin
    if(metin3[i]==')'){// )'den sonrasini okumadi
        break;
    }
}
}
void donustur(FILE*output,char girendosya[5000],char forici[500],char forici2[500])
{//iki for'u while'a donusturup geri kalanini yazan fonksiyon
   int i=0;
char aranan[]={'f','o','r'};//for kelimeleri dizisi
for(i=0;girendosya[i]!=EOF;i++){//yazanlarin sonuna kadar okuyup
        if(aranan[0]==girendosya[i]){
            i++;
            if(aranan[1]==girendosya[i]){
                i++;
                if(aranan[2]==girendosya[i]){//foru buldugum kisim
                    i++;
                    girendosya[i-2]='\b';//for'u sildim
                    girendosya[i-1]='\b';
                    for(i;girendosya[i-1]!=')';i++){
                        if(girendosya[i-1]==')'){
                            continue;
                        }
                    }
                    fprintf(output,"\n\n");
                    iciniokuma1(output,forici);//ilk for'un ilk kismi
                    fprintf(output,"\n");//bosluk biraktim
                    printf("while(");//while yazdirdim
                    fprintf(output,"while(");//dosyaya yazdirdim
                    iciniokuma2(output,girendosya);//icine iki ; arasi
                    printf(")");//parantezi kapayip while icini yazdim
                    fprintf(output,")");//dosyaya yazdirdim
                    while(i<100){
    if(aranan[0]==girendosya[i]){//foru buluyorum
            i++;
            if(girendosya[i-2]=='t'){
                printf("f");

            }
            if(aranan[1]==girendosya[i]){
                i++;
                if(aranan[2]==girendosya[i]){
                i++;
                //foru bulduktan sonra diger foru bulana kadar ilerliyor
                    for(i;girendosya[i-1]!=')';i++){
                        if(girendosya[i-1]==')'){
                            break;
                        }
                    }
                    iciniokuma1(output,forici2);//ikinci forun ilk kismi
                    fprintf(output,"\n");
                    printf("while(");//while yazdirdim
                    fprintf(output,"while(");//dosyaya yazdirdim
                    iciniokuma2(output,forici2);//icine ikinci forun ikinci kismi
                    printf(")");//parantezi kapattim
                    fprintf(output,")");//dosyaya yazdirdim
                    if(i+1==parantezsay2(girendosya)){//parantezleri saydim
                    iciniokuma3(output,forici);//ikinci forun son kismi
                    printf("\n");


                    }
                }
            }
            }
                    printf("%c",girendosya[i]);
                    fprintf(output,"%c",girendosya[i]);//dosyaya yazdirdim
                    if(i+1==parantezsay(girendosya)){
                    //parantezi sayan foksiyonu cagirdim
                    iciniokuma3(output,forici);//forun 3.kisminin fonksiyonunu cagirdim
                    printf("\n");
                    }
                    i++;//i yi artirdim
                    }
            }
            }
        }
        }
  }
int parantezsay(char butunmetin[5000])
{//ilk for icin parantezleri sayan fonksiyon
char aranan[]={'f','o','r'};//for elemanlari dizisi
    int i=0;//i,k ve counter degiskenleri tanimladim
    int k=0;
    int counter=0;
    for(i=0;i<5000;i++){// önceden yaptigim for bulma kismi
        if(aranan[0]==butunmetin[i]){
            i++;
            if(aranan[1]==butunmetin[i]){
                i++;
                if(aranan[2]==butunmetin[i]){
                    i++;
                        for(k=0;butunmetin[k]!='{';k++)
                            {//{ görene kadar okur
                    if(butunmetin[k]=='{'){//{ gorunce okumadı
                           break;
                           }
                            }
                    for(k;butunmetin[k]!=EOF;k++)
                        {//metin sonuna gelinceye kadar
                        if(butunmetin[k]=='{'){
                           counter++;//{ gorunce sayaci arttirdim
                           }
                           if(butunmetin[k]=='}'){
                            counter--;//} gorunce sayaci azalttim
                           }
                           if(counter==0){// sayac 0 olunca k döndü
                            return k;
                           }
                    }
                }
            }
        }
   }
}
void yazdir(char tummetin[5000],char forici[500]){//yazdirma fonk.
int i=0;
while(i<100){
printf("%c",tummetin[i]);//metni yazdirdim

i++;
}
}
void forbul2(char text2[5000],char forici2[500])
{//ikinci foru bulma fonksiyonu
    char aranan[]={'f','o','r'};//ilk for'u buldugum gibi ikincisini
    int i=0,t=0;//de buldum.
    for(i=0;text2[i]!=EOF;i++){
        if(aranan[0]==text2[i]){
            i++;
            if(aranan[1]==text2[i]){
                i++;
                if(aranan[2]==text2[i]){
                        i++;
                        t=0;
                while(1){
                    forici2[t]=text2[i];//2.for icini metne esitledim
                    printf("%c",forici2[t]);
                    t++;//t arttirdim
                    i++;//i arttirdim
                    if(text2[i]=='{'){//{ gorunce okumadi
                    break;
                 }
                }
                printf("\n");
                }
            }
        }
}
}
int parantezsay2(char butunmetin[5000]){
//ikinci for icin parantezleri sayan fonksiyon
char aranan[]={'f','o','r'};
    int i=0;
    int k=0;
    int counter=0;
    for(i=0;i<5000;i++){
        if(aranan[0]==butunmetin[i]){
            i++;
            if(aranan[1]==butunmetin[i]){
                i++;
                if(aranan[2]==butunmetin[i]){
                        i++;
                    for(k=0;butunmetin[k]!='{';k++){//{'e kadar okuyor
                    if(butunmetin[k]=='{'){
                           break;
                           }
                            }
                    for(k;butunmetin[k]!=EOF;k++){
                            //metin sonuna gelene kadar
                        if(butunmetin[k]=='{'){//{ olunca
                           counter++;// sayac artiyor
                           }
                           if(butunmetin[k]=='}'){//} olunca
                            counter--;//sayaci azaltiyor
                           }
                           if(counter==0){//0 oldugunda k döner
                           return k;
                           }
                    }
                }
            }
        }
   }
}
© 2020 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
