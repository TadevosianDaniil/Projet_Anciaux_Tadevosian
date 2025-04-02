// Exo 3.4
#include "exo3.h"

int main(){
    ParserResult *PR = parse("parser.txt");
    afficher_parse(PR);
    free_parser_result(PR);
    return 0;
}