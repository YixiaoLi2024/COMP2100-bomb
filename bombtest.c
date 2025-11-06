#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void phase_defused(int a);

FILE *infile;
int num_input_strings = 0;
int call_count = 0;
char inputStrings[7][102];
struct structs {
    long ID;
    struct structs* num1;
    struct structs* num2;
};
struct structs n41 = {
    .ID = 11,
    .num1 = 0,
    .num2 = 0
};
struct structs n42 = {
    .ID = 64,
    .num1 = 0,
    .num2 = 0
};
struct structs n43 = {
    .ID = 130,
    .num1 = 0,
    .num2 = 0
};
struct structs n44 = {
    .ID = 183,
    .num1 = 0,
    .num2 = 0
};
struct structs n45 = {
    .ID = 243,
    .num1 = 0,
    .num2 = 0
};
struct structs n46 = {
    .ID = 318,
    .num1 = 0,
    .num2 = 0
};
struct structs n47 = {
    .ID = 507,
    .num1 = 0,
    .num2 = 0
};
struct structs n48 = {
    .ID = 931,
    .num1 = 0,
    .num2 = 0
};
struct structs n31 = {
    .ID = 43,
    .num1 = &n41,
    .num2 = &n42
};
struct structs n32 = {
    .ID = 147,
    .num1 = &n43,
    .num2 = &n44
};
struct structs n33 = {
    .ID = 297,
    .num1 = &n45,
    .num2 = &n46
};
struct structs n34 = {
    .ID = 623,
    .num1 = &n47,
    .num2 = &n48
};
struct structs n21 = {
    .ID = 91,
    .num1 = &n31,
    .num2 = &n32
};
struct structs n22 = {
    .ID = 411,
    .num1 = &n33,
    .num2 = &n34
};
struct structs n1 = {
    .ID = 203,
    .num1 = &n21,
    .num2 = &n22
};

int blank_line(char* a) {
    while (*a != 0) {
        if (isspace((char)*a++)) {
            return 0;
        }
    }
    return 1;
}

char* skip() {
    fwrite("Bomb> ", 1, 6, stdout);
    char *input;
    do {
        input = fgets(inputStrings[num_input_strings], 82, infile);
        if (input == 0) {
            return inputStrings[num_input_strings];
        }
    } while (blank_line(input) != 0);
    
    if (infile == stdin) {
        fputs(input, stdout);
    }
    return input;
}
void trigger_bomb_now() {
    puts("\nCRACK!");
    puts("The bomb has blown up.");
    exit(8);
}

char* read_line(int a, char* b) {
    char* input;
    int inputCount = 0;
    input = skip();
    if (input == NULL) {
        if (infile == stdin) {
            puts("Error: Premature EOF on stdin");
            exit(8);
        }
        infile = stdin;
        input = skip();
        if (input == NULL) {
            puts("Error: Premature EOF on stdin");
            exit(0);
        }
    }
    inputCount = 0;
    while (inputStrings[num_input_strings][inputCount] != 0) {
        inputCount++;
    }
    if (inputCount > 0 && inputStrings[num_input_strings][inputCount - 1] == 10) {
        inputStrings[num_input_strings][inputCount - 1] = 0;
    }
    if (inputCount <= 101) {
        while (inputCount != 102) {
            inputStrings[num_input_strings][inputCount++] = 0;
        }
    }
    inputCount = 0;
    while (inputStrings[num_input_strings][inputCount] != 0) {
        inputCount++; 
    }
    if (inputCount > 80) {
        puts("Error: Input line too long");
        inputCount = 0;
        while (inputStrings[num_input_strings][inputCount] != 0) {
            inputCount++;
        }
        char truncated[18] = "*** truncated ***";
        for (int j = 0; j < 18; j++) {
            inputStrings[num_input_strings][inputCount + j] = truncated[j];
        }
        num_input_strings++;
        trigger_bomb_now();
    } else {
        num_input_strings++;
        inputCount = 0;
        while (inputStrings[num_input_strings - 1][inputCount] != 0) {
            inputCount++; 
        }
        if (inputCount > 80) {
            trigger_bomb_now();
        }
    }
    return inputStrings[num_input_strings - 1];
}

int bombphase_1(char* input, int a, int b, int c) {
    if (input[0] != 45 || input[4] != 72 || input[3] != 105 || input[1] != 66) {
        trigger_bomb_now();
        return -605273121;
    }
    if (input[2] != 54) {
        if (input[35] != c || input[36] == input[18] || input[18] + 7 != input[36]) {
            trigger_bomb_now();
            return -605273121;
        }
        return 1;
    }
    return 0;
}

int my_strncmp(char* string1, char* string2, int charCount) {
    if (charCount == 0) {
        return 0;
    }
    int count = 0;
    while (count < charCount) {
        if (string1[count] == string2[count] && string1[count] == 0) {
            return 0;
        }
        if (string1[count] != string2[count]) {
            return 2*(string1[count] >= string2[count]) - 1;
        }
        count++;
    }
    return 0;
}

int my_strlen(char* string) {
    if (string == NULL) {
        return 0;
    }
    int count = 0;
    do {
        count++;
    } while (string[count] != 0);
    return count;
}

int bombphase_2(char* input) {
    long long int part1 = 0x69636e756e6f7270LL;
    int part2 = 0x6f697461;
    short part3 = 0x6e;
    char compareString[14];
    memcpy(compareString, &part1, 8);
    memcpy(compareString + 8, &part2, 4);
    memcpy(compareString + 12, &part3, 2);
    if (my_strncmp(input, compareString, 13) != 0) {
        trigger_bomb_now();
        return -605273121;
    }
    if (input[13] == 0) {
        return 0;
    }
    return my_strlen(input) == 22;
}

int bombphase_3(int inputNumberScanned, int a, int b, int c, int d) {
    if (inputNumberScanned != 4) {
        trigger_bomb_now();
        return -605273121;
    }
    d = d ^ 438;
    a = a - d + 301;
    if (a != b) {
        trigger_bomb_now();
        return -605273121;
    }
    return a == 704;
}

int bombphase_4(char* input) {
    short part1 = 0x1e14;
    char part2 = 0x12;
    int part3 = 0x1067d01b;
    short part4 = 0x17ef;
    int part5 = 0;
    long int part6 = 0x69c6ecdf;
    char buffer[48];
    memcpy(buffer + 22, &part1, 2);
    memcpy(buffer + 24, &part2, 1);
    memcpy(buffer + 28, &part3, 4);
    memcpy(buffer + 32, &part4, 2);
    memcpy(buffer + 36, &part5, 4);
    memcpy(buffer + 40, &part6, 8);
    short shortExtracted;
    memcpy(&shortExtracted, buffer + 32, 2);
    short temp = shortExtracted + 268;
    memcpy(buffer + 32, &temp, 2);
    strcpy(buffer, input);
    int returnValue = 0;
    char byteExtracted;
    int intExtracted;
    long longExtracted;
    memcpy(&byteExtracted, buffer + 24, 1);
    memcpy(&intExtracted, buffer + 36, 4);
    memcpy(&shortExtracted, buffer + 22, 2);
    memcpy(&longExtracted, buffer + 40, 8);
    if (byteExtracted != 0x79 || intExtracted != 0 || shortExtracted != 0x7c43 || longExtracted != 0x69c6ecdf) {
        trigger_bomb_now();
        returnValue = -605273121;
    }
    memcpy(&shortExtracted, buffer + 32, 2);
    memcpy(&intExtracted, buffer + 28, 4);
    int shortExtractedExtended = shortExtracted << 6;
    intExtracted = ~intExtracted;
    intExtracted = intExtracted & shortExtractedExtended;
    int returnValue2 = intExtracted == 692608;
    return returnValue | returnValue2;
}

int bombphase_5(char* input) {
    if (input[9] == 0) {
        trigger_bomb_now();
        return -605273121;
    }
    char* originalInput = input;
    char* comparePointer = input + 9;
    int asciiValue = 871;
    char* text = "azalea";
    do {
        asciiValue = asciiValue + comparePointer[0];
        int first5Bits = (comparePointer[0] - 92) & 31;
        if (first5Bits == comparePointer[0] - 92) {
            printf("%d\n", first5Bits);
            int first5Bits2 = ((1 - first5Bits) & 31) + 92;
            printf("%d\n", first5Bits2);
            if (first5Bits2 != text[0]) {
                trigger_bomb_now();
                return -605273121;
            }
            text++;
        }
        comparePointer++;
    } while (comparePointer[0] != 0);
    if (text[0] != 0) {
        trigger_bomb_now();
        return -605273121;
    }
    if (asciiValue == 3345) {
        int comparePointerMoved = comparePointer - (originalInput + 9);
        return comparePointerMoved == 29;
    }
    return 0;
}

int func_6(int input) {
    call_count++;
    if (input <= 0) {
        return 0;
    }
    int stored = input;
    input = input >> 4;
    int returnValue = func_6(input);
    return stored ^ returnValue;
}

int bombphase_6(char* input) {
    int input1;
    int input2;
    int scanned = sscanf(input, "%d,%d", &input1, &input2);
    int returnValue = 1;
    if (scanned != 2 || input2 == 0) {
        trigger_bomb_now();
        return -605273121;
    }
    int result = func_6(input2);
    if (call_count != 3 || result != input1) {
        trigger_bomb_now();
        return -605273121;
    }
    return returnValue;
}

int fun7(struct structs* target, int input) {
    if (target == NULL) {
        return -1;
    }
    long value = target->ID;
    if (value <= input) {
        int returnValue = 0;
        if (value == input) {
            return returnValue;
        }
        target = target->num2;
        int returnValue2 = fun7(target, input);
        return 2*returnValue2 + 1;
    } else {
        target = target->num1;
        int returnValue2 = fun7(target, input);
        return 2*returnValue2;
    }
}

void mqsecretphase() {
    char* input = read_line(0, NULL);
    long int answer = strtol(input, 0, 10);
    long int stored = answer;
    answer--;
    if (answer <= 1000) {
        int returnValue = fun7(&n1, stored);
        if (returnValue != 3) {
            trigger_bomb_now();
        } else {
            puts("Wow! You've defused the secret phase!");
            phase_defused(0);
        }
    }
}

int string_length(char* string) {
    int count = 0;
    while (string[0] != 0) {
        string++;
        count++;
    }
    return count;
}

int strings_not_equal(char* string1, char* string2) {
    int length1 = string_length(string1);
    int length2 = string_length(string2);
    int returnValue = 1;
    if (length1 != length2) {
        return returnValue;
    }
    char character = string1[0];
    if (character == 0) {
        return 0;
    }
    if (character != string2[0]) {
        return 1;
    }
    string1++;
    string2++;
    character = string1[0];
    while (character != 0) {
        if (character != string2[0]) {
            return 1;
        }
        string1++;
        string2++;
        character = string1[0];
    }
    return 0;
}

void phase_defused(int mark) {
    if (num_input_strings == 6) {
        char string1[102];
        char string2[102];
        char string3[102];
        char string4[102];
        char input[102];
        int scanned = sscanf(inputStrings[2], "%s %s %s %s %s", &string1, &string2, &string3, &string4, &input);
        if (scanned == 5) {
            char* password = "PaddyOBrien";
            int value = strings_not_equal(input, password);
            if (value == 0) {
                puts("Curses, you've found the secret phase!");
                puts("But finding it and solving it are quite different...");
                mqsecretphase();
            }
        }
        puts("Congratulations! You've defused the bomb!");
        puts("Your instructor has been notified and will verify your solution.");
    }
}

int main(int argc, char *argv[])
{
    char *input;
    int status;
    int k, a, b, c, d;

    /* Note to self: remember to port this bomb to Windows and put a
     * fantastic GUI on it. */

    /* When run with no arguments, the bomb reads its input lines
     * from standard input. */
    if (argc == 1) {
        infile = stdin;
    }

    /* When run with one argument <file>, the bomb reads from <file>
     * until EOF, and then switches to standard input. Thus, as you
     * defuse each phase, you can add its defusing string to <file> and
     * avoid having to retype it. */
    else if (argc == 2) {
        if (!(infile = fopen(argv[1], "r"))) {
            printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
            exit(8);
        }
    }

    /* You can't call the bomb with more than 1 command line argument. */
    else {
        printf("Usage: %s [<input_file>]\n", argv[0]);
        exit(8);
    }

    /* Do all sorts of secret stuff that makes the bomb harder to defuse. */
    //initialize_bomb();

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n");

    /* Hmm...  Six phases must be more secure than one phase! */
    /* A secure password has random characters.  They'll never guess
     * my password. Especially because it is encoded in ASCII! */
    

    /* They guessed my password coded in ASCII but they won't guess my encrypted password! */
    input = read_line(0, NULL);
    status = bombphase_5(input);
    if (status < 0) exit (1);        /* The bomb exploded. Excellent!  */
    phase_defused(status);
    if (status > 0) printf ("Perfect bomb defusing skill!\n");
    printf("Good work!  On to the next...\n");

    /* This phase will never be used, since no one will get past the
     * earlier ones.  But just in case, make this one extra hard. */
    input = read_line(0, NULL);
    status = bombphase_6(input);
    if (status < 0) exit (1);        /* The bomb exploded. Mua ha ha!  */
    phase_defused(status);

    /* Wow, they got it!  But isn't something... missing?  Perhaps
     * something they overlooked?  Mua ha ha ha ha! */

    return 0;
}

