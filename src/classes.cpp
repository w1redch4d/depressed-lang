#include "../include/classes.h"
#include "../include/func.h"

DepressedClasses::DepressedClasses(std::string name,
    std::shared_ptr<DepressedClasses> superclass,
    std::map<std::string, std::shared_ptr<DepressedFunc>> methods)
  : superclass{superclass}, name{std::move(name)},
    methods{std::move(methods)}
{}

std::shared_ptr<DepressedFunc> DepressedClasses::findMethod(
    const std::string& name) {
  auto elem = methods.find(name);
  if (elem != methods.end()) {
      return elem->second;
  }

  if (superclass != nullptr) {
    return superclass->findMethod(name);
  }

  return nullptr;
}

std::string DepressedClasses::toString() {
  return name;
}

std::any DepressedClasses::call(Interpreter& interpreter,
                        std::vector<std::any> arguments) {
  auto instance = std::make_shared<DepressedInst>(shared_from_this());
  std::shared_ptr<DepressedFunc> initializer = findMethod("init");
  if (initializer != nullptr) {
    initializer->bind(instance)->call(interpreter,
                                      std::move(arguments));
  }

  return instance;
}

int DepressedClasses::arity() {
  std::shared_ptr<DepressedFunc> initializer = findMethod("init");
  if (initializer == nullptr) return 0;
  return initializer->arity();
}
