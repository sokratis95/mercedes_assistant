#if !defined(IOHANDLER_H)
#define IOHANDLER_H
#include <cstddef>
#include <string>
#include <vector>

class IoHandler {
private:
  std::string user_command_;

public:
  // I/O Handler constructor for CLI
  IoHandler() = default;

  // Get string from CLI
  auto static get_string();

  // starting assistant prompt
  void assistant_prompt_menu();

  // command given from the user
  void get_user_command_menu();

  std::string get_user_command() { return user_command_; };
};

#endif /// IOHANDLER_H