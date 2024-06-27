#include<stdio.h>
int main(){
    FILE *file,*cfile;
    char filename[50];
    char ch,cch;
    printf("Enter the file name : ");
    scanf("%s",filename);
    file = fopen(filename,"r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    cfile = fopen("copyfile.txt","w");
    while((ch=fgetc(file))!=EOF){
        putc(ch,cfile);
    }
    fclose(file);
    fclose(cfile);
    cfile = fopen("copyfile.txt","r");
    while((cch=getc(cfile))!=EOF){
        printf("%c",cch);
    }
    printf("\nSuccesfully copid.\n");
    fclose(cfile);
    return 0;
}