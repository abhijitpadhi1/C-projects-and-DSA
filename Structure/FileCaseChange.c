#include<stdio.h>
#include<string.h>
int main(){
    FILE *file1,*file2;
    char ch,input[30];
    file1=fopen("textfile.txt","w");
    printf("Enter the text to store : ");
    fgets(input,sizeof(input),stdin);
    fprintf(file1,"%s",input);
    fclose(file1);
    file1 = fopen("textfile.txt","r");
    file2 = fopen("textfile2.txt","w");
    if (file1 == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    while((ch=fgetc(file1))!=EOF){
        if(ch>64&&ch<91){
            ch = ch+32;
        }else if(ch>96&&ch<123){
            ch = ch-32;
        }
        fputc(ch,file2);
    }
    fclose(file1);
    fclose(file2);
    file2 = fopen("textfile2.txt","r");
    printf("File after change : ");
    while((ch=fgetc(file2))!=EOF){
        printf("%c",ch);
    }
    printf("\nSuccesfully changed.\n");
    fclose(file2);
    return 0;
}