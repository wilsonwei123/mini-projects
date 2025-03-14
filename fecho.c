#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_input(int i) {
    int memory_len = 0;
    char* dy_ar = NULL, dum_char;

    while ((dum_char = getchar())) {
        memory_len++;
        dy_ar = (char*)realloc(dy_ar, memory_len * sizeof(char));
        if (i == 0) {
            if (dum_char == EOF) {
                break;
            }
        } else {
            if (dum_char == EOF || dum_char == '\n') {
                break;
            }
        }

        dy_ar[memory_len - 1] = dum_char;
    }
    memory_len++;
    dy_ar = (char*)realloc(dy_ar, memory_len * sizeof(char));
    dy_ar[memory_len - 1] = '\0';

    return dy_ar;
}

int main() {
    printf("Enter the name of your file (it will be created if it doesn't already exist, and if it does exist, text will be added as a new line after the existing text): ");
    char* input_file = read_input(1);
    FILE *input = fopen(input_file, "a");

    printf("Enter your text to be appended with a new line (ctrl+d for mac/linux or ctrl+z for windows to exit):\n");
    char* text = read_input(0);

    fprintf(input, "\n");
    fprintf(input, "%s",text);

    printf("Successful\n");
    fclose(input);
    return 0;
}
