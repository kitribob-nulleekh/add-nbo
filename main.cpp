#include <cstdio>
#include <cstdint>
#include <netinet/in.h>


int printTitle() {
    printf("                                                        \n");
    printf("              _       _                   _             \n");
    printf("   __ _    __| |   __| |          _ __   | |__     ___  \n");
    printf("  / _` |  / _` |  / _` |  _____  | \'_ \\  | \'_ \\   / _ \\ \n");
    printf(" | (_| | | (_| | | (_| | |_____| | | | | | |_) | | (_) |\n");
    printf("  \\__,_|  \\__,_|  \\__,_|         |_| |_| |_.__/   \\___/ \n");
    printf("                                                        \n");
    printf("                         Developed by nulLeeKH@KITRI.BoB\n\n\n");
    return 0;
}
int printUsage(char *dir) {
    printf("\n\n\nUsage: %sadd-nbo <filename1> <filename2>\n", dir);
    return 0;
}

int main(int argc, char* argv[]) {
    printTitle();

    if (argc != 3) {
        printUsage(argv[0]);
    } else {
        printf("\nINFO: Start initialize add-nbo\n"); //debugLog
        FILE *firstFile, *secondFile;
        uint32_t firstNum, secondNum, result;
        printf("INFO: Initialized successfully\n\n\n"); //debugLog

        printf("\nINFO: Strat reading data from frist file\n"); //debugLog
        firstFile = fopen(argv[1], "rb");
        printf("INFO: First file has been opened | firstFile=%p\n", firstFile); //debugLog
        fread(&firstNum, sizeof(uint32_t), 1, firstFile);
        printf("INFO: Data has been readed | firstNum=0x%x\n", firstNum); //debugLog
        fclose(firstFile);
        printf("INFO: First file has been closed\n\n\n"); //debugLog

        printf("\nINFO: Strat reading data from second file\n"); //debugLog
        secondFile = fopen(argv[2], "rb");
        printf("INFO: Second file has been opened | secondFile=%p\n", secondFile); //debugLog
        fread(&secondNum, sizeof(uint32_t), 1, secondFile);
        printf("INFO: Data has been readed | secondNum=0x%x\n", secondNum); //debugLog
        fclose(secondFile);
        printf("INFO: Second file has been closed\n\n\n"); //debugLog

        printf("\nINFO: Convert first data from host byte order to network byte order | firstNum=0x%x\n", firstNum); //debugLog
        firstNum = htonl(firstNum);
        printf("INFO: First data has been converted | firstNum=0x%x\n\n\n", firstNum); //debugLog

        printf("\nINFO: Convert second data from host byte order to network byte order | secondNum=0x%x\n", secondNum); //debugLog
        secondNum = htonl(secondNum);
        printf("INFO: Second data has been converted | secondNum=0x%x\n\n\n", secondNum); //debugLog

        printf("\nINFO: Calculating started | firstNum=0x%x | secondNum=0x%x\n", firstNum, secondNum); //debugLog
        result = firstNum + secondNum;
        printf("INFO: Calculating finished | result=0x%x\n\n\n", result); //debugLog

        printf("\n\n\n  0x%0.8x\n+ 0x%0.8x\n------------\n= 0x%0.8x\n\n\n", firstNum, secondNum, result);
    }
    return 0;
}
