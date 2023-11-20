#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define DEFAULT 10
#define ERROR -99

char buffer[512];

int readLinesToPrint(char* args[]) {
    char** read = args;
    int i = 1;
    char num[100];

    if (read[1][0] == '-') {
        for (i = 1; i < strlen(read[1]); i++) {
            num[i - 1] = (read[1][i] >= '0' && read[1][i] <= '9') ? read[1][i] : ERROR;
        }
        return (num[0] != '\0') ? atoi(num) : ERROR;
    } else {
        for (i = 0; i < strlen(read[1]); i++) {
            num[i] = (read[1][i] >= '0' && read[1][i] <= '9') ? read[1][i] : ERROR;
        }
        return (num[0] != '\0') ? atoi(num) : ERROR;
    }
}

void printLines(int fd, int lns) {
    int i, n;
    int lnsInFile = 0;
    int lnsReadInTempFile = 0;
    int lnsToPrintFn = lns;
    int lineIndexPrintStart;

    int tempFile = open("tempFile", O_CREATE | O_RDWR);

    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
        write(tempFile, buffer, n);
        for (i = 0; i < n; i++) {
            if (buffer[i] == '\n') {
                lnsInFile++;
            }
        }
    }
    close(tempFile);

    lineIndexPrintStart = lnsInFile - lnsToPrintFn;

    tempFile = open("tempFile", O_RDONLY);
    while ((n = read(tempFile, buffer, sizeof(buffer))) > 0) {
        for (i = 0; i < n; i++) {
            if (lnsReadInTempFile >= lineIndexPrintStart) {
                printf(1, "%c", buffer[i]);
            }
            if (buffer[i] == '\n') {
                lnsReadInTempFile++;
            }
        }
    }
    unlink("tempFile");
}

int main(int argc, char* argv[]) {
    int fd, numLines;

    if (argc <= 1) {
        printLines(0, DEFAULT);
        exit();
    } else if (argc == 2) {

        numLines = readLinesToPrint(argv);
        fd = open(argv[1], O_RDONLY);

        if (fd >= 0) {
            printLines(fd, DEFAULT);
            close(fd);
            exit();
        } else if (numLines == ERROR) {
            printf(1, "Illegal Option\n");
            exit();
        } else if ((fd < 0) && (numLines % 2)) {
            printLines(0, numLines);
            exit();
        } else if (fd < 0) {
            printf(1, "p: cannot open %s\n", argv[1]);
        }
    } else if (argc == 3) {

        numLines = readLinesToPrint(argv);

        if ((fd = open(argv[2], O_RDONLY)) < 0) {
            printf(1, "p: cannot open %s\n", argv[2]);
            exit();
        }
        if (numLines == ERROR) {
            printf(1, "Illegal option\n");
            exit();
        }
        numLines = (numLines != ERROR) ? numLines : DEFAULT;
        printLines(fd, numLines);
        close(fd);
        exit();
    } else {
        printf(1, "p: cannot open %s\n", argv[2]);
        exit();
    }
    exit();
}
