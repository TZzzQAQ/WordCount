#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void c_num(char file){
    FILE *f=NULL;
    char c;
    int num=0;
    f=fopen(file,"r");
    while(!feof(f)){
        c=fgetc(f);
        if(c!=' '&&c!='\n'&&c!='\t'){
            num++;
        }
    }
    fclose(f);
    printf("c_num:%d",num);
}

void word_num(char file){
    FILE *f=NULL;
    int aword=0;
    int cword=0;
    f=fopen(file,"r");
    char ch=fgetc(f);
    if((ch>='a'&&ch<='z')||(ch<='Z'&&ch>='A')||ch=='_'){
        aword=1;
    }
    else if(aword){
        aword=0;
        cword++;
    }
}

int main(int argc, char* argv[])
{
    FILE *fp;
    while(1){
        if((fp=fopen(argv[2],"r"))==NULL){
            printf("¿ÕÎÄ¼þ!");
            putchar(10);
            scanf("%s%s%s",argv[0],argv[1],argv[2]);
            continue;
        }
        else if(!strcmp(argv[1],"-w")){
            word_num(argv[2]);
        }
        else if(!strcmp(argv[1],"-c")){
            c_num(argv[2]);
        }
        else{
            printf("¿ÕÖ¸Õë!");
            putchar(10);
            scanf("%s%s%s",argv[0],argv[1],argv[2]);
        }
    }
    return 0;
}
