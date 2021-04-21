#include "iohandler.h"
#include <iostream>

auto IoHandler::get_string() {
  std::string intent;
  std::getline(std::cin, intent);
  return intent;
}

void IoHandler::assistant_prompt_menu() {
  std::cout << "How may I help you?" << std::endl;
  get_user_command_menu();
}

void IoHandler::get_user_command_menu() { user_command_ = get_string(); }
