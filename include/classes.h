#pragma once

#include <any>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "../include/calls.h"

class Interpreter;
class DepressedFunc;

class DepressedClasses: public DepressedCalls,
                public std::enable_shared_from_this<DepressedClasses> {
  friend class DepressedInst;
  const std::string name;
  const std::shared_ptr<DepressedClasses> superclass;
  std::map<std::string, std::shared_ptr<DepressedFunc>> methods;

public:
  DepressedClasses(std::string name, std::shared_ptr<DepressedClasses> superclass,
      std::map<std::string, std::shared_ptr<DepressedFunc>> methods);

  std::shared_ptr<DepressedFunc> findMethod(const std::string& name);
  std::string toString() override;
  std::any call(Interpreter& interpreter,
                std::vector<std::any> arguments) override;
  int arity() override;
};
