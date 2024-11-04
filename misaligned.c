#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* expectedOutput[25] = {
    "0 | White | Blue\n", "1 | White | Orange\n", "2 | White | Green\n",
    "3 | White | Brown\n", "4 | White | Slate\n", "5 | Red | Blue\n",
    "6 | Red | Orange\n", "7 | Red | Green\n", "8 | Red | Brown\n",
    "9 | Red | Slate\n", "10 | Black | Blue\n", "11 | Black | Orange\n",
    "12 | Black | Green\n", "13 | Black | Brown\n", "14 | Black | Slate\n",
    "15 | Yellow | Blue\n", "16 | Yellow | Orange\n", "17 | Yellow | Green\n",
    "18 | Yellow | Brown\n", "19 | Yellow | Slate\n", "20 | Violet | Blue\n",
    "21 | Violet | Orange\n", "22 | Violet | Green\n", "23 | Violet | Brown\n",
    "24 | Violet | Slate\n"
};

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;

    // Loop to print the color combinations
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }

    return i * j;  // Return the total number of entries
}

void testPrintColorMapOutput() {
    char buffer[2000] = {0};
    FILE* outputFile = freopen("/dev/null", "a+", stdout);  // Redirect stdout
    setvbuf(outputFile, buffer, _IOFBF, sizeof(buffer));    // Capture output

    int result = printColorMap();  // Call printColorMap to capture its output

    freopen("/dev/tty", "a", stdout);  // Restore stdout to terminal

    char* outputPtr = buffer;
    for (int i = 0; i < 25; i++) {
        char printedLine[50];
        sscanf(outputPtr, "%[^\n]\n", printedLine);
        outputPtr += strlen(printedLine) + 1;
        assert(strcmp(printedLine, expectedOutput[i]) == 0 && "Output mismatch");
    }

    assert(result == 25 && "Number of entries mismatch");
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPrintColorMapOutput();
    printf("All is well (maybe!)\n");

    return 0;
}
