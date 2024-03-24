#include <stdio.h>
#include <stdlib.h>

#include <libgeometry/geom_parser.h>
#include <libgeometry/lexer.h>

int main(int argc, char* argv[])
{
    FILE* file = NULL;
    if (argc < 2)
        parser(stdin, NOT_FILE);
    else if (argc == 2) {
        if ((file = fopen(argv[1], "r")) == NULL) {
            printf(RED_COLOR("Error") ": can't open file \e[1;35m\"%s\"\e[0m\n",
                   argv[1]);
        } else {
            parser(file, _FILE);
            fclose(file);
        }
    } else {
        printf(MAGENTA_COLOR("Usage") ": %s <filename>\n", argv[0]);
    }

    return 0;
}