//
// Created by corne on 5/22/2024.
//Systems Programming
//Assignment 5: File Management
//Description:
//
//Write a program that performs basic file management operations such as creating, reading, writing, and deleting files.
//Implement functionalities like copying contents from one file to another and searching for a specific pattern in a file.
//Ensure error handling for file operations.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void choice() {
    char stringforfile[1000];
    char choice;
    char buffer[1000];
    char directory[1000];
    char filepath[1100]; // to accommodate the directory and file name
    FILE *file, *file2;

    // Prompt the user to enter the directory path
    printf("Enter the directory path (e.g., C:\\Users\\corne\\Downloads\\GNUManual): ");
    fgets(directory, sizeof(directory), stdin);
    // Remove the newline character that fgets may have read
    size_t len = strlen(directory);
    if (len > 0 && directory[len - 1] == '\n') {
        directory[len - 1] = '\0';
    }

    while (choice != '0') {
        printf("Enter your choice to work on a file (press 0 to exit)\n");
        scanf(" %c", &choice);  // Added space before %c to consume any leading whitespace
        getchar();  // To consume the newline left by scanf

        switch (choice) {
            case 'r':
                snprintf(filepath, sizeof(filepath), "%s\\Data.txt", directory);
                file = fopen(filepath, "r");
                if (file == NULL) {
                    printf("Could not open/find the file: %s\n", filepath);
                    exit(0);
                } else {
                    printf("Reading file\n");
                    while (fgets(buffer, sizeof(buffer), file) != NULL) {
                        printf("%s", buffer);
                    }
                    fclose(file);
                }
                break;
            case 'w':
                printf("Enter a string for the file to be written: ");
                fgets(stringforfile, sizeof(stringforfile), stdin);

                // Remove the newline character that fgets may have read
                len = strlen(stringforfile);
                if (len > 0 && stringforfile[len - 1] == '\n') {
                    stringforfile[len - 1] = '\0';
                }

                printf("Writing to the file\n");
                snprintf(filepath, sizeof(filepath), "%s\\Data1.txt", directory);
                file = fopen(filepath, "w");
                if (file == NULL) {
                    printf("Couldn't open the file: %s\n", filepath);
                } else {
                    fprintf(file, "%s\n", stringforfile);
                    fclose(file);
                    printf("String written to the file successfully\n");
                }
                break;
            case 'R':
                snprintf(filepath, sizeof(filepath), "%s\\Data1.txt", directory);
                if (remove(filepath) == 0) {
                    printf("The file has been deleted successfully\n");
                } else {
                    printf("The file could not be removed: %s\n", filepath);
                }
                break;
            case 'c':
                snprintf(filepath, sizeof(filepath), "%s\\Data1.txt", directory);
                file = fopen(filepath, "r");
                if (file == NULL) {
                    printf("Could not open/find the source file: %s\n", filepath);
                    exit(0);
                }
                snprintf(filepath, sizeof(filepath), "%s\\Data2.txt", directory);
                file2 = fopen(filepath, "w");
                if (file2 == NULL) {
                    printf("Could not open/create the destination file: %s\n", filepath);
                    fclose(file);
                    exit(0);
                }
                while (fgets(buffer, sizeof(buffer), file) != NULL) {
                    fputs(buffer, file2);
                }
                fclose(file);
                fclose(file2);
                printf("Contents copied from Data1.txt to Data2.txt successfully\n");
                break;
            case '0':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    choice();
    return 0;
}