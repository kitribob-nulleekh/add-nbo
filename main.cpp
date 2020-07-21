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

    file = fopen(filePath, "rb");
    size_t dataSize = fread(&num, 1, sizeof(uint32_t), file);
    fclose(file);

    if (dataSize == 4) {
	    num = htonl(num);
	    return num;
    } else {
	    printf("\nError: %s is too small to be treated as 0x00000000\n", filePath);
    	return 0;
    }
}

int main(int argc, char* argv[]) {
    printTitle();

    if (argc != 3) {
        printUsage(argv[0]);
    } else {
        uint32_t firstNum, secondNum, result;

        firstNum = getData(argv[1]);

        secondNum = getData(argv[2]);

        result = firstNum + secondNum;

        printf("\n\n\n  0x%0.8x\n+ 0x%0.8x\n------------\n= 0x%0.8x\n\n\n", firstNum, secondNum, result);
    }
    return 0;
}
