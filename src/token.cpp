#include "../include/token.h"

std::string toString(TokenType type) {
    static const std::string strings[] = {
      "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE",
      "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH", "STAR",
      "BANG", "BANG_EQUAL",
      "EQUAL", "EQUAL_EQUAL",
      "GREATER", "GREATER_EQUAL",
      "LESS", "LESS_EQUAL",
      "IDENTIFIER", "STRING", "NUMBER",
      "AND", "GROUP", "ELSE", "NO", "DEPRESSION", "ITER", "IF", "NIL", "OR",
      "CRY", "RETURN", "SUPER", "THIS", "YES", "PAIN", "WHILE",
      "END_OF_FILE"
    };

    return strings[static_cast<int>(type)];
}
