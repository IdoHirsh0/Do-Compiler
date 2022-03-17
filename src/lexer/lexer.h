#pragma once

#include <stdlib.h>

#include "../token/token.h"
#include "lexer_fsm/lexer_fsm.h"


// The size to allocate for each new token value
#define LEXER_MAX_TOKEN_SIZE 33 // 32 + 1, the max size of a token is 32 characters long. +1 for the null terminator


/* ---------- Structs ---------- */

// Struct of the lexer
typedef struct Lexer
{
    char c;         // Current character in the src code
    int i;          // Current offsest from the starting of the source code
    int line;       // Current line number in source file for error reporting
    Lexer_FSM* fsm; // The lexer's FSM
} Lexer;


/* ---------- Functions ---------- */

// Create a new lexer on the heap and updates the compiler's lexer to point to it
void lexer_create();

// Frees everything we've allocated in the lexer_init() function for the compiler's lexer
void lexer_destroy();

// Initializes the compiler's lexer
void lexer_init();

// Advances the lexer 1 character forward in the source code
void lexer_advance();

// Creates and returns a new token when reached to the end of a token
// If that token is a Whitespace token, returns NULL to indicate that
Token* lexer_EOT(char* value, int size, int state);

// Returns the next token from the source code
Token* lexer_get_next_token();
