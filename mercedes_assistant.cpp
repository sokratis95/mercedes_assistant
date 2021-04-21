#include "mercedes_assistant.h"
#include <iostream> // cout

int Mercedes_Assistant::user_intent_recognition(
    const std::string &user_command) {

  int exitCode = -1;
  for (auto intention = std::begin(predefined_user_commands_and_answers_);
       intention != std::end(predefined_user_commands_and_answers_);
       ++intention) {
    if (user_command == intention->first) {
      assistant_answer_ = intention->second;
      exitCode = 0;
    }
  }
  return exitCode;
}

void Mercedes_Assistant::print_assistant_answer() {
  std::cout << assistant_answer_ << std::endl;
}
