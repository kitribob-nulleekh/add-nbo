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

uint32_t getData(char *filePath) {
	FILE *file;
	uint32_t num;

    printf("\nINFO: Strat reading data from file | filePath=%s\n", filePath); //debugLog
    file = fopen(filePath, "rb");
    printf("INFO: File has been opened | file=%p\n", file); //debugLog
    fread(&num, 1, sizeof(uint32_t), file);
    printf("INFO: Data has been readed | num=0x%x\n", num); //debugLog
    fclose(file);
    printf("INFO: File has been closed\n\n\n"); //debugLog

    printf("\nINFO: Convert data from host byte order to network byte order | num=0x%x\n", num); //debugLog
    num = htonl(num);
    printf("INFO: Data has been converted | num=0x%x\n\n\n", num); //debugLog

    return num;
}

int main(int argc, char* argv[]) {
    printTitle();

    if (argc != 3) {
        printUsage(argv[0]);
    } else {
        printf("\nINFO: Start initialize add-nbo\n"); //debugLog
        uint32_t firstNum, secondNum, result;
        printf("INFO: Initialized successfully\n\n\n"); //debugLog

        printf("\nINFO: Get data from first file | argv[1]=%s\n", argv[1]); //debugLog
        firstNum = getData(argv[1]);
        printf("INFO: Get data from second file successfully | firstNum=0x%x\n\n\n", firstNum); //debugLog

        printf("\nINFO: Get data from second file | argv[2]=%s\n", argv[2]); //debugLog
        secondNum = getData(argv[2]);
        printf("INFO: Get data from second file successfully | secondNum=0x%x\n\n\n", secondNum); //debugLog

        printf("\nINFO: Calculating started | firstNum=0x%x | secondNum=0x%x\n", firstNum, secondNum); //debugLog
        result = firstNum + secondNum;
        printf("INFO: Calculating finished | result=0x%x\n\n\n", result); //debugLog

        printf("\n\n\n  0x%0.8x\n+ 0x%0.8x\n------------\n= 0x%0.8x\n\n\n", firstNum, secondNum, result);
    }
    return 0;
}
