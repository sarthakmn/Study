#include <stdio.h>


int main(void){

    FILE *fp = fopen("file.txt","r+");
    char data[] = "My name is Sarthak Nanivadekar";

    fwrite(data,sizeof(data),sizeof(data),fp);
    fseek(fp, 3, SEEK_SET);
    fread(data,sizeof(data),sizeof(data),fp);
    printf("%s\n",data);
    fclose(fp);

    FILE *fd = fopen("file.txt","w+");
    fgets(data,sizeof(data),fd);
    printf("Data : %s\n",data);
    fclose(fd);
    return 0;
}
