#include <cstring>      
#include <fstream>      
#include <iostream>     
#include <string>
#include <vector>


#include "../include/error.h"
#include "../include/intrptr.h"
#include "../include/parser.h"
#include "../include/resolver.h"
#include "../include/scan.h"

#include "../include/func.h" 
#include "../include/classes.h"    
#include "../include/inst.h" 

std::string read_file(std::string_view path) {
  std::ifstream file{path.data(), std::ios::in | std::ios::binary |
                                  std::ios::ate};
  if (!file) {
    std::cerr << "Failed to open file " << path << ": " << std::endl;
    std::exit(4);
  }

  std::string contents;
  contents.resize(file.tellg());

  file.seekg(0, std::ios::beg);
  file.read(contents.data(), contents.size());

  return contents;
}

Interpreter interpreter{};

void run(std::string_view source) {
  Scanner scanner {source};
  std::vector<Token> tokens = scanner.scanTokens();
  Parser parser{tokens};
  std::vector<std::shared_ptr<Stmt>> statements = parser.parse();

  if (hasError) 
    {
      return;
  }
  Resolver resolver{interpreter};
  resolver.resolve(statements);

  if (hasError)
  {
      return;
  }
  interpreter.interpret(statements);
}

void run_file(std::string_view path) {
  std::string contents = read_file(path);
  run(contents);

  if (hasError)
  {
      std::exit(2);
  }
  if (hasRuntimeError)
  {
      std::exit(3);
  }	
}

void run_prompt() {
    while (true) {
        std::cout << "kys > ";
        std::string line;
        if (!std::getline(std::cin, line) || line == "exit")
        {
            break;
        }
        run(line);
    }
}

int main(int argc, char* argv[]) {
  if (argc > 2) {
    std::cout << "Usage:" << argv[0] << "[script]\n";
    std::exit(1);
  } else if (argc == 2) {
    run_file(argv[1]);
  } else {
    run_prompt();
  }
}