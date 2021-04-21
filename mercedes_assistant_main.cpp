#include "mercedes_assistant.h"
#include <iostream> // cout

// main entry point
int main() {
  int command_found = -1;
  IoHandler input = IoHandler();
  input.assistant_prompt_menu();
  Mercedes_Assistant hey_mercedes = Mercedes_Assistant();
  command_found =
      hey_mercedes.user_intent_recognition(input.get_user_command());

  while (command_found) {
    std::cout << "Intent: Not recognized command.\nPlease try again with a "
                 "valid command"
              << std::endl;
    input.get_user_command_menu();
    command_found =
        hey_mercedes.user_intent_recognition(input.get_user_command());
  }
  hey_mercedes.print_assistant_answer();
  return 0;
}