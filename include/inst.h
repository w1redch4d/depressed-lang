#pragma once

#include <any>
#include <map>
#include <memory>
#include <string>

class DepressedClasses;
class Token;

class DepressedInst: public std::enable_shared_from_this<DepressedInst> {
  std::shared_ptr<DepressedClasses> klass;
  std::map<std::string, std::any> fields;

public:
  DepressedInst(std::shared_ptr<DepressedClasses> klass);
  std::any get(const Token& name);
  void set(const Token& name, std::any value);
  std::string toString();
};
