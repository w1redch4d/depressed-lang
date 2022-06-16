#include "../include/func.h"
#include "../include/environ.h"
#include "../include/inst.h"
#include "../include/intrptr.h"
#include "../include/stmt.h"

DepressedFunc::DepressedFunc(std::shared_ptr<Function> declaration,
                         std::shared_ptr<Environment> closure,
                         bool isInitializer)
  : isInitializer{isInitializer}, closure{std::move(closure)},
    declaration{std::move(declaration)}
{}

std::shared_ptr<DepressedFunc> DepressedFunc::bind(
    std::shared_ptr<DepressedInst> instance) {
  auto environment = std::make_shared<Environment>(closure);
  environment->define("this", instance);
  return std::make_shared<DepressedFunc>(declaration, environment,
                                       isInitializer);
}

std::string DepressedFunc::toString() {
  return "<fn " + declaration->name.lexeme + ">";
}

int DepressedFunc::arity() {
  return declaration->params.size();
}

std::any DepressedFunc::call(Interpreter& interpreter,
                           std::vector<std::any> arguments) {
  auto environment = std::make_shared<Environment>(closure);
  for (int i = 0; i < declaration->params.size(); ++i) {
    environment->define(declaration->params[i].lexeme,
        arguments[i]);
  }

  try {
    interpreter.executeBlock(declaration->body, environment);
  } catch (DepressedReturn returnValue) {
    if (isInitializer) return closure->getAt(0, "this");

    return returnValue.value;
  }

  if (isInitializer) return closure->getAt(0, "this");

  return nullptr;
}
