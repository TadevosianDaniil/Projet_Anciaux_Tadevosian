#include "exo3.h"

// Exo 3.1
Instruction *parse_data_instruction(const char *line, HashMap *memory_locations){
    char *pc = (char *)line;
    char mnemonic[10]= {0};
    char operand1[10]= {0};
    char operand2[10]= {0};
    char *temp = pc;
    
    sscanf(pc, " %s %s %s ", mnemonic, operand1, operand2);

    int count = 0;


    hashmap_insert(memory_locations, mnemonic, (void *)&(memory_locations->size));
    memory_locations->size += count + 1;

    Instruction *pi = (Instruction *)malloc(sizeof(Instruction)); 
    pi->mnemonic = strdup(mnemonic);
    pi->operand1 = strdup(operand1);
    pi->operand2 = strdup(operand2);

    return pi;

}

// Exo 3.2
Instruction *parse_code_instruction(const char *line, HashMap *labels, int code_count){
    char *pc = (char *)line;
    char label[10] = {0};
    char mnemonic[10] = {0};
    char operand1[10] = {0};
    char operand2[10] = {0};

    char *temp = strchr(pc, ':');

    if (temp){
        char *temp1 = strchr(pc, ',');
        if (temp1) {
            *temp1 = ' ';
            sscanf(pc, " %s %s %s %s ", label, mnemonic, operand1, operand2);
        } else {
            sscanf(pc, " %s %s %s ", label, mnemonic, operand1);
        }
        *temp = '\0';
    } else {
        char *temp1 = strchr(pc, ',');
        if (temp1) {
            *temp1 = ' ';
            sscanf(pc, " %s %s %s ", mnemonic, operand1, operand2);
        } else {
            sscanf(pc, " %s %s ", mnemonic, operand1);
        }
    }

    printf("%s\n", label);
    Instruction *pi = (Instruction *)malloc(sizeof(Instruction));
    if (label[0]){
        hashmap_insert(labels, label, (void *)&(code_count));
    }

    pi->mnemonic = strdup(mnemonic);
    pi->operand1 = strdup(operand1);
    
    if (operand2[0]){
        pi->operand2 = strdup(operand2);
    }

    return pi;
}

// Exo 3.3
ParserResult *parse(const char *filename){
    char buffer[256] = {0}; 
    FILE *fr = fopen(filename, "r");

    ParserResult * PR = (ParserResult *)malloc(sizeof(ParserResult));
    PR->data_instructions = (Instruction **)malloc(sizeof(Instruction *) * TAILLE);
    PR->data_count = 0;
    PR->code_instructions = (Instruction **)malloc(sizeof(Instruction *) * TAILLE * 2);
    PR->code_count = 0;
    PR->labels = hashmap_create();
    PR->memory_locations = hashmap_create();



    while(fgets(buffer, 256, fr) && strncmp(buffer, ".DATA", 5) != 0);
    while(fgets(buffer, 256, fr) && strncmp(buffer, ".CODE", 5) != 0){
        PR->data_instructions[PR->data_count] = parse_data_instruction(buffer, PR->memory_locations);
        PR->data_count++;
    }
    while(fgets(buffer, 256, fr)){
        PR->code_instructions[PR->code_count] = parse_code_instruction(buffer, PR->labels, PR->code_count);
        PR->code_count++;
    }

    return PR;


    fclose(fr);
}

// Extra
void afficher_instuct(Instruction * pi){
    printf("Instruction : %s %s %s\n", pi->mnemonic, pi->operand1, pi->operand2);
}


void afficher_parse(ParserResult *PR){
    printf("Parser:\n Data:\n");
    for(int i = 0; i < PR->data_count; i++){
        afficher_instuct(PR->data_instructions[i]);
    }
    printf("Count_data: %d\n", PR->data_count);
    for(int i = 0; i < PR->code_count; i++){
        afficher_instuct(PR->code_instructions[i]);
    }
    printf("Count_code: %d\n", PR->code_count);
    printf("Labels:\n");
    for(int i = 0; i < TAILLE; i++){
        printf("%d ", PR->labels->table[i].value);
    }
    printf("\nMemory locations:\n");
    for(int i = 0; i < TAILLE; i++){
        printf("%d ", PR->memory_locations->table[i].value);
    }
}

// Exo 3.5
void free_parser_result(ParserResult *result){
    for(int i = 0; i < result->data_count; i++){
        free((result->data_instructions)[i]);
    }
    free(result->data_instructions);
    for(int i = 0; i < result->code_count; i++){
        free((result->code_instructions)[i]);
    }
    free(result->code_instructions);
    hashmap_destroy(result->labels);
    hashmap_destroy(result->memory_locations);

    free(result);

}