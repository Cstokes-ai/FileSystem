#include <stdio.h>
#include <stdlib.h>
//this focuses on file reading, writing, handling, etc
int main() {
    char string1[1024];
    char string2[1024];
    char string3[1024];
    int year;
   FILE* file;
    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter the second string: ");
    fgets(string2, sizeof(string2), stdin);
    printf("Enter the third string: ");
    fgets(string3, sizeof(string3), stdin);
    printf("Enter the year: ");
    scanf("%d", &year);
   file = fopen("gnu-c-manual.txt", "w");

   if (file == NULL){
       printf("Couldn't open");
       exit(0);
   }
   else{
       printf("file is opened successfully");
       fprintf(file, "%s %s %s %d\n", string1, string2, string3, year);

       fclose(file);
       printf("Entered Successfully");

   }
   return 0;
}
