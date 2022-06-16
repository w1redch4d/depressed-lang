#pragma once

#include <any>
#include <string>
#include <utility>   

enum TokenType {
    
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
  
    IDENTIFIER, STRING, NUMBER,
    AND, GROUP, ELSE, NO, DEPRESSION, ITER, IF, NIL, OR,
    CRY, RETURN, SUPER, THIS, YES, PAIN, WHILE,

    END_OF_FILE
};

std::string toString(TokenType type);

class Token {
public:
  const TokenType type;
  const std::string lexeme;
  const std::any literal;
  const int line;

  Token(TokenType type, std::string lexeme, std::any literal,
        int line)
    : type{type}, lexeme{std::move(lexeme)},
      literal{std::move(literal)}, line{line}
  {}

  std::string toString() const {
    std::string literal_text;

    switch (type) {
      case (IDENTIFIER):
        literal_text = lexeme;
        break;
      case (STRING):
        literal_text = std::any_cast<std::string>(literal);
        break;
      case (NUMBER):
        literal_text = std::to_string(std::any_cast<double>(literal));
        break;
      case (YES):
        literal_text = "yes";
        break;
      case (NO):
        literal_text = "no";
        break;
      default:
        literal_text = "nil";
    }

    return ::toString(type) + " " + lexeme + " " + literal_text;
  }
};