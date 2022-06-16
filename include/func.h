#pragma once

#include <any>
#include <memory>
#include <string>
#include <vector>
#include "calls.h"
#include "inst.h"
#include "environ.h"

class Function;

class DepressedFunc: public DepressedCalls {
  std::shared_ptr<Function> declaration;
  std::shared_ptr<Environment> closure;

  bool isInitializer;

public:
  DepressedFunc(std::shared_ptr<Function> declaration,
              std::shared_ptr<Environment> closure,
              bool isInitializer);
  std::shared_ptr<DepressedFunc> bind(
      std::shared_ptr<DepressedInst> instance);
  std::string toString() override;
  int arity() override;
  std::any call(Interpreter& interpreter,
                std::vector<std::any> arguments) override;
};
