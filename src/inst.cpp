#include "../include/error.h"
#include "../include/inst.h"
#include "../include/classes.h"
#include "../include/func.h"

DepressedInst::DepressedInst(std::shared_ptr<DepressedClasses> Class)
  : klass{std::move(Class)}
{}

std::any DepressedInst::get(const Token& name) {
  auto elem = fields.find(name.lexeme);
  if (elem != fields.end()) {
    return elem->second;
  }

  std::shared_ptr<DepressedFunc> method =
      klass->findMethod(name.lexeme);
  if (method != nullptr) return method->bind(shared_from_this());

  throw RuntimeError(name,
      "Undefined property '" + name.lexeme + "'.");
}

void DepressedInst::set(const Token& name, std::any value) {
  fields[name.lexeme] = std::move(value);
}

std::string DepressedInst::toString() {
  return klass->name + " instance";
}
